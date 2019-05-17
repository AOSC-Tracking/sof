/*
 * Copyright (c) 2016, Intel Corporation
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
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 *         Janusz Jankowski <janusz.jankowski@linux.intel.com>
 *
 */

#ifndef __INCLUDE_ARCH_SOF__
#define __INCLUDE_ARCH_SOF__

#include <stdint.h>
#include <stddef.h>
#include <sof/mailbox.h>
#include <uapi/ipc/xtensa.h>
#include <arch/offset-defs.h>

/* architecture specific stack frames to dump */
#define ARCH_STACK_DUMP_FRAMES		32

/* xtensa core specific oops size */
#define ARCH_OOPS_SIZE (sizeof(struct sof_ipc_dsp_oops_xtensa) \
			+ (XCHAL_NUM_AREGS * sizeof(uint32_t)))

void arch_dump_regs_a(void *dump_buf, uint32_t ps);

static inline void *arch_get_stack_ptr(void)
{
	void *ptr;

	/* stack pointer is in a1 */
	__asm__ __volatile__ ("mov %0, a1"
		: "=a" (ptr)
		:
		: "memory");
	return ptr;
}

static inline void fill_core_dump(struct sof_ipc_dsp_oops_xtensa *oops,
				  uint32_t ps, uintptr_t stack_ptr,
				  uintptr_t *epc1)
{
	oops->arch_hdr.arch = ARCHITECTURE_ID;
	oops->arch_hdr.totalsize = ARCH_OOPS_SIZE;
#if XCHAL_HW_CONFIGID_RELIABLE
	oops->plat_hdr.configidhi = XCHAL_HW_CONFIGID0;
	oops->plat_hdr.configidlo = XCHAL_HW_CONFIGID1;
#else
	oops->plat_hdr.configidhi = 0;
	oops->plat_hdr.configidlo = 0;
#endif
	oops->plat_hdr.numaregs = XCHAL_NUM_AREGS;
	oops->plat_hdr.stackoffset = oops->arch_hdr.totalsize
				     + sizeof(struct sof_ipc_panic_info);
	oops->plat_hdr.stackptr = stack_ptr;

	oops->epc1 = *epc1;

	arch_dump_regs_a((void *)&oops->exccause, ps);
}

static inline void arch_dump_regs(uint32_t ps, uintptr_t stack_ptr,
				  uintptr_t *epc1)
{
	void *buf = (void *)mailbox_get_exception_base();

	fill_core_dump(buf, ps, stack_ptr, epc1);

	dcache_writeback_region(buf, ARCH_OOPS_SIZE);
}

#endif
