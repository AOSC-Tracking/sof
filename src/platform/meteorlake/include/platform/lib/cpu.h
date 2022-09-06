// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2022 Intel Corporation. All rights reserved.

/**
 * \file
 * \brief DSP core parameters.
 */

#ifdef __SOF_LIB_CPU_H__

#ifndef __PLATFORM_LIB_CPU_H__
#define __PLATFORM_LIB_CPU_H__

#include <ace/lib/cpu.h>

/** \brief Maximum allowed number of DSP cores */
#define MAX_CORE_COUNT	4

#endif /* __PLATFORM_LIB_CPU_H__ */

#else

#error "This file shouldn't be included from outside of sof/lib/cpu.h"

#endif /* __SOF_LIB_CPU_H__ */
