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
 */

#include "xtos-internal.h"

#ifndef __XTOS_STRUCTS_H__
#define __XTOS_STRUCTS_H__

struct idc;
struct irq_task;
struct schedule_data;

struct thread_data {
	xtos_structures_pointers xtos_ptrs;
};

struct xtos_core_data {
	struct XtosInterruptStructure xtos_int_data;
	int xtos_stack_for_interrupt_2[XTOS_INT_STACK_SIZE / 4];
	int xtos_stack_for_interrupt_3[XTOS_INT_STACK_SIZE / 4];
	int xtos_stack_for_interrupt_4[XTOS_INT_STACK_SIZE / 4];
	int xtos_stack_for_interrupt_5[XTOS_INT_STACK_SIZE / 4];

	struct thread_data *thread_data_ptr;
};

struct core_context {
	struct thread_data td;
	struct irq_task *irq_low_task;
	struct irq_task *irq_med_task;
	struct irq_task *irq_high_task;
	struct schedule_data *sch;
	struct idc *idc;
};

void _xtos_initialize_pointers_per_core(void);

#endif /* __XTOS_STRUCTS_H__ */
