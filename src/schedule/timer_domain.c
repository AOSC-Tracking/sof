// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2019 Intel Corporation. All rights reserved.
//
// Author: Tomasz Lauda <tomasz.lauda@linux.intel.com>

#include <sof/drivers/timer.h>
#include <sof/lib/alloc.h>
#include <sof/lib/cpu.h>
#include <sof/platform.h>
#include <sof/schedule/ll_schedule_domain.h>
#include <sof/schedule/schedule.h>
#include <sof/schedule/task.h>
#include <ipc/topology.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct timer_domain {
	struct timer *timer;
	uint64_t timeout;
	void *arg[PLATFORM_CORE_COUNT];
};

struct ll_schedule_domain_ops timer_domain_ops;

static int timer_domain_register(struct ll_schedule_domain *domain,
				 uint64_t period, struct task *task,
				 void (*handler)(void *arg), void *arg)
{
	struct timer_domain *timer_domain = ll_sch_domain_get_pdata(domain);
	int core = cpu_get_id();

	/* tasks already registered on this core */
	if (timer_domain->arg[core])
		return 0;

	timer_domain->arg[core] = arg;

	return timer_register(timer_domain->timer, handler, arg);
}

static void timer_domain_unregister(struct ll_schedule_domain *domain,
				    uint32_t num_tasks)
{
	struct timer_domain *timer_domain = ll_sch_domain_get_pdata(domain);
	int core = cpu_get_id();

	/* tasks still registered on this core */
	if (!timer_domain->arg[core] || num_tasks)
		return;

	timer_unregister(timer_domain->timer, timer_domain->arg[core]);

	timer_domain->arg[core] = NULL;
}

static void timer_domain_enable(struct ll_schedule_domain *domain, int core)
{
	struct timer_domain *timer_domain = ll_sch_domain_get_pdata(domain);

	timer_enable(timer_domain->timer, timer_domain->arg[core], core);
}

static void timer_domain_disable(struct ll_schedule_domain *domain, int core)
{
	struct timer_domain *timer_domain = ll_sch_domain_get_pdata(domain);

	timer_disable(timer_domain->timer, timer_domain->arg[core], core);
}

static void timer_domain_set(struct ll_schedule_domain *domain, uint64_t start)
{
	struct timer_domain *timer_domain = ll_sch_domain_get_pdata(domain);
	uint64_t ticks = domain->ticks_per_ms * timer_domain->timeout / 1000 +
		start;

	platform_timer_set(timer_domain->timer, ticks);

	domain->last_tick = ticks;
}

static void timer_domain_clear(struct ll_schedule_domain *domain)
{
	struct timer_domain *timer_domain = ll_sch_domain_get_pdata(domain);

	platform_timer_clear(timer_domain->timer);
}

static bool timer_domain_is_pending(struct ll_schedule_domain *domain,
				    struct task *task)
{
	return task->start <= platform_timer_get(platform_timer);
}

struct ll_schedule_domain *timer_domain_init(struct timer *timer, int clk,
					     uint64_t timeout)
{
	struct ll_schedule_domain *domain;
	struct timer_domain *timer_domain;

	domain = domain_init(SOF_SCHEDULE_LL, clk, &timer_domain_ops);

	timer_domain = rzalloc(RZONE_SYS | RZONE_FLAG_UNCACHED,
			       SOF_MEM_CAPS_RAM, sizeof(*timer_domain));
	timer_domain->timer = timer;
	timer_domain->timeout = timeout;

	ll_sch_domain_set_pdata(domain, timer_domain);

	return domain;
}

struct ll_schedule_domain_ops timer_domain_ops = {
	.domain_register	= timer_domain_register,
	.domain_unregister	= timer_domain_unregister,
	.domain_enable		= timer_domain_enable,
	.domain_disable		= timer_domain_disable,
	.domain_set		= timer_domain_set,
	.domain_clear		= timer_domain_clear,
	.domain_is_pending	= timer_domain_is_pending
};
