// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2020 Intel Corporation. All rights reserved.
//

#ifndef __SOF_TRACE_TRACE1_H__
#define __SOF_TRACE_TRACE1_H__

#ifndef ZEPHYR_INCLUDE_LOGGING_LOG_H_
#include <logging/log.h>
#include <sys/printk.h>

/* Level of SOF trace on Zephyr */
#define SOF_ZEPHYR_TRACE_LEVEL LOG_LEVEL_INF

#endif

/* printk supports uint64_t so use it until LOG is ready */
#define USE_PRINTK	1

/* SOF trace header */
#include "../../../../src/include/sof/trace/trace.h"

extern struct tr_ctx zephyr_tr;

struct timer;
uint64_t platform_timer_get(struct timer *timer);

/*
 * Override SOF dictionary macros for now and let Zephyr take care of
 * the physical log IO.
 */
#undef _log_message
#undef mtrace_printf

#if USE_PRINTK
#define mtrace_printf(level, format, ...)				\
	do {								        \
		if ((level) <= SOF_ZEPHYR_TRACE_LEVEL)                          \
			printk("%llu: " format "\n", platform_timer_get(NULL),	\
				##__VA_ARGS__);					\
	} while (0)
#define _log_message(log_func, atomic, level, comp_class, ctx, id1, id2, format, ...)	\
	do {								        \
		if ((level) <= SOF_ZEPHYR_TRACE_LEVEL)                          \
			printk("%llu: " format "\n", platform_timer_get(NULL),	\
				##__VA_ARGS__);					\
	} while (0)
#else /* not tested */
#define _log_message(log_func, atomic, level, comp_class, ctx, id1, id2, format, ...)	\
	do {								        \
		Z_LOG(level, "%u: " format, (uint32_t)platform_timer_get(NULL),	\
		      ##__VA_ARGS__);					        \
	} while (0)
#endif

#endif /* __INCLUDE_TRACE__ */
