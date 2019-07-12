/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2017 Intel Corporation. All rights reserved.
 *
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 */

#ifdef __SOF_CACHE_H__

#ifndef __ARCH_CACHE_H__
#define __ARCH_CACHE_H__

#include <stddef.h>

static inline void dcache_writeback_region(void *addr, size_t size) {}
static inline void dcache_invalidate_region(void *addr, size_t size) {}
static inline void icache_invalidate_region(void *addr, size_t size) {}
static inline void dcache_writeback_invalidate_region(void *addr,
	size_t size) {}

#endif /* __ARCH_CACHE_H__ */

#else

#error "This file shouldn't be included from outside of sof/cache.h"

#endif /* __SOF_CACHE_H__ */
