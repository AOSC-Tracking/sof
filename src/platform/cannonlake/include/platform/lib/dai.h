/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2018 Intel Corporation. All rights reserved.
 *
 * Author: Marcin Maka <marcin.maka@linux.intel.com>
 */

#ifdef __SOF_LIB_DAI_H__

#ifndef __PLATFORM_LIB_DAI_H__
#define __PLATFORM_LIB_DAI_H__

/* CANNONLAKE */

/* SSP */

/*
 * Number of base and extended SSP ports must be defined separately
 * since some HW registers are in two groups, one for base and one
 * for extended.
 */

/** \brief Number of 'base' SSP ports available */
#define DAI_NUM_SSP_BASE	3

/** \brief Number of 'extended' SSP ports available */
#define DAI_NUM_SSP_EXT		0

/* HD/A */

/** \brief Number of HD/A Link Outputs */
#define DAI_NUM_HDA_OUT		9

/** \brief Number of HD/A Link Inputs */
#define DAI_NUM_HDA_IN		7

/** \brief Number of Echo Reference Signal outputs */
#define DAI_NUM_ERS		1

int dai_init(void);

#endif /* __PLATFORM_LIB_DAI_H__ */

#else

#error "This file shouldn't be included from outside of sof/lib/dai.h"

#endif /* __SOF_LIB_DAI_H__ */
