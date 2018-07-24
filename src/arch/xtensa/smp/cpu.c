/*
 * Copyright (c) 2018, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the Intel Corporation nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Tomasz Lauda <tomasz.lauda@linux.intel.com>
 *
 */

/**
 * \file arch/xtensa/smp/cpu.c
 * \brief Xtensa SMP CPU implementation file
 * \authors Tomasz Lauda <tomasz.lauda@linux.intel.com>
 */

#include <arch/alloc.h>
#include <arch/atomic.h>
#include <arch/cpu.h>
#include <arch/idc.h>
#include <platform/platform.h>
#include <sof/lock.h>
#include <sof/schedule.h>

static uint32_t active_cores_mask = 0x1;
static spinlock_t lock = { 0 };

void arch_cpu_enable_core(int id)
{
	struct idc_msg power_up = {
		IDC_POWER_UP_MESSAGE, IDC_POWER_UP_EXTENSION, id };
	uint32_t flags;

	spin_lock_irq(&lock, flags);

	if (!(active_cores_mask & (1 << id))) {
		/* allocate resources for core */
		alloc_core_context(id);

		/* enable IDC interrupt for the the slave core */
		idc_enable_interrupts(id, arch_cpu_get_id());

		/* send IDC power up message */
		arch_idc_send_msg(&power_up);

		active_cores_mask |= (1 << id);
	}

	spin_unlock_irq(&lock, flags);
}

void arch_cpu_disable_core(int id)
{
	struct idc_msg power_down = { IDC_POWER_DOWN_MESSAGE, 0, id };
	uint32_t flags;

	spin_lock_irq(&lock, flags);

	if (active_cores_mask & (1 << id)) {
		arch_idc_send_msg(&power_down);

		active_cores_mask ^= (1 << id);
	}

	spin_unlock_irq(&lock, flags);
}

void cpu_power_down_core(void)
{
	arch_interrupt_global_disable();

	idc_free();

	scheduler_free();

	free_core_context(arch_cpu_get_id());

	dcache_writeback_invalidate_all();

	while (1)
		arch_wait_for_interrupt(0);
}
