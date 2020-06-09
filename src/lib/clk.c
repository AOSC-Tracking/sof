// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2018 Intel Corporation. All rights reserved.
//
// Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
//         Keyon Jie <yang.jie@linux.intel.com>
//         Rander Wang <rander.wang@intel.com>
//         Janusz Jankowski <janusz.jankowski@linux.intel.com>

#include <sof/drivers/timer.h>
#include <sof/lib/clk.h>
#include <sof/lib/memory.h>
#include <sof/lib/notifier.h>
#include <sof/lib/wait.h>
#include <sof/platform.h>
#include <sof/spinlock.h>
#include <sof/trace/trace.h>
#include <user/trace.h>
#include <stdint.h>

struct clock_notify_data clk_notify_data;

static inline uint32_t clock_get_nearest_freq_idx(const struct freq_table *tab,
						  uint32_t size, uint32_t hz)
{
	uint32_t i;

	/* find lowest available frequency that is >= requested hz */
	for (i = 0; i < size; i++) {
		if (hz <= tab[i].freq)
			return i;
	}

	/* not found, so return max frequency */
	return size - 1;
}

uint32_t clock_get_freq(int clock)
{
	struct clock_info *clk_info = clocks_get() + clock;
	uint32_t freq = clk_info->freqs[clk_info->current_freq_idx].freq;

	platform_shared_commit(clk_info, sizeof(*clk_info));

	return freq;
}

void clock_set_freq(int clock, uint32_t hz)
{
	struct clock_info *clk_info = clocks_get() + clock;
	uint32_t idx;
	uint32_t flags;

	clk_notify_data.old_freq =
		clk_info->freqs[clk_info->current_freq_idx].freq;
	clk_notify_data.old_ticks_per_msec =
		clk_info->freqs[clk_info->current_freq_idx].ticks_per_msec;

	/* atomic context for changing clocks */
	spin_lock_irq(&clk_info->lock, flags);

	/* get nearest frequency that is >= requested Hz */
	idx = clock_get_nearest_freq_idx(clk_info->freqs, clk_info->freqs_num,
					 hz);
	clk_notify_data.freq = clk_info->freqs[idx].freq;

	/* tell anyone interested we are about to change freq */
	clk_notify_data.message = CLOCK_NOTIFY_PRE;
	notifier_event(clk_info, clk_info->notification_id,
		       clk_info->notification_mask, &clk_notify_data,
		       sizeof(clk_notify_data));

	if (!clk_info->set_freq ||
	    clk_info->set_freq(clock, idx) == 0)
		/* update clock frequency */
		clk_info->current_freq_idx = idx;

	/* tell anyone interested we have now changed freq */
	clk_notify_data.message = CLOCK_NOTIFY_POST;
	notifier_event(clk_info, clk_info->notification_id,
		       clk_info->notification_mask, &clk_notify_data,
		       sizeof(clk_notify_data));

	platform_shared_commit(clk_info, sizeof(*clk_info));

	spin_unlock_irq(&clk_info->lock, flags);
}

uint64_t clock_ms_to_ticks(int clock, uint64_t ms)
{
	struct clock_info *clk_info = clocks_get() + clock;
	uint64_t ticks;

	ticks = clk_info->freqs[clk_info->current_freq_idx].ticks_per_msec * ms;

	platform_shared_commit(clk_info, sizeof(*clk_info));

	return ticks;
}

void platform_timer_set_delta(struct timer *timer, uint64_t ns)
{
	struct clock_info *clk_info = clocks_get() + PLATFORM_DEFAULT_CLOCK;
	uint32_t ticks_per_msec =
		clk_info->freqs[clk_info->current_freq_idx].ticks_per_msec;
	uint64_t ticks;

	ticks = ticks_per_msec * ns / 1000000;
	timer->delta = ticks - platform_timer_get(timer);

	platform_shared_commit(clk_info, sizeof(*clk_info));
	platform_shared_commit(timer, sizeof(*timer));
}

#if CONFIG_CAVS_PM_RO

void clock_set_hpro(void)
{
	uint32_t reg;

	shim_write(SHIM_CLKCTL, ((shim_read(SHIM_CLKCTL) &
		   ~SHIM_CLKCTL_RLROSCC) | SHIM_CLKCTL_RHROSCC));

	reg = io_reg_read(SHIM_BASE + SHIM_CLKCTL);
	reg = reg & ~(SHIM_CLKCTL_OCS_LP_RING);
	reg = reg | SHIM_CLKCTL_OCS_HP_RING;

	io_reg_write(SHIM_BASE + SHIM_CLKCTL, reg);

	while (!(shim_read(SHIM_CLKSTS) & SHIM_CLKCTL_RHROSCC))
		idelay(16);
}

void clock_set_lpro(void)
{
	uint32_t reg;

	shim_write(SHIM_CLKCTL, ((shim_read(SHIM_CLKCTL) &
		   ~SHIM_CLKCTL_RHROSCC) | SHIM_CLKCTL_RLROSCC));

	reg = io_reg_read(SHIM_BASE + SHIM_CLKCTL);
	reg = reg & ~(SHIM_CLKCTL_OCS_HP_RING);
	reg = reg | SHIM_CLKCTL_OCS_LP_RING;

	io_reg_write(SHIM_BASE + SHIM_CLKCTL, reg);

	while (!(shim_read(SHIM_CLKSTS) & SHIM_CLKCTL_RLROSCC))
		idelay(16);
}

#endif
