/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2016 Intel Corporation. All rights reserved.
 *
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 */

#ifdef __SOF_DRIVERS_TIMER_H__

#ifndef __ARCH_DRIVERS_TIMER_H__
#define __ARCH_DRIVERS_TIMER_H__

#include <sof/drivers/interrupt.h>
#include <stdint.h>

struct timer_irq {
	int logical_irq;
	void *irq_arg;
};

struct timer {
	uint32_t id;
	int irq;
	const char *irq_name;
	unsigned int core;
	void *timer_data;	/* used by core */
	struct timer_irq *tirq;	/* dynamic non-cacheable IRQ data */
	uint32_t hitime;	/* high end of 64bit timer */
	uint32_t hitimeout;
	uint32_t lowtimeout;
	uint64_t delta;
};

/* internal API calls */
int timer64_register(struct timer *timer, void (*handler)(void *arg),
		     void *arg);
void timer_64_handler(void *arg);

static inline int arch_timer_register(struct timer *timer,
	void (*handler)(void *arg), void *arg)
{
	uint32_t flags;
	int ret;

	flags = arch_interrupt_global_disable();
	timer64_register(timer, handler, arg);
	ret = arch_interrupt_register(timer->id, timer_64_handler, timer);
	arch_interrupt_global_enable(flags);

	return ret;
}

static inline void arch_timer_unregister(struct timer *timer)
{
	arch_interrupt_unregister(timer->id);
}

static inline void arch_timer_enable(struct timer *timer)
{
	arch_interrupt_enable_mask(1 << timer->irq);
}

static inline void arch_timer_disable(struct timer *timer)
{
	arch_interrupt_disable_mask(1 << timer->irq);
}

uint64_t arch_timer_get_system(struct timer *timer);

int arch_timer_set(struct timer *timer, uint64_t ticks);

static inline void arch_timer_clear(struct timer *timer)
{
	arch_interrupt_clear(timer->irq);
}

#endif /* __ARCH_DRIVERS_TIMER_H__ */

#else

#error "This file shouldn't be included from outside of sof/drivers/timer.h"

#endif /* __SOF_DRIVERS_TIMER_H__ */
