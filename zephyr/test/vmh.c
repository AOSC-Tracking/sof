// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright(c) 2023 Intel Corporation. All rights reserved.
 *
 * Author: Guennadi Liakhovetski <guennadi.liakhovetski@linux.intel.com>
 */

#include <errno.h>
#include <stdbool.h>

#include <adsp_memory_regions.h>
#include <sof/boot_test.h>
#include <sof/lib/regions_mm.h>

#include <zephyr/logging/log.h>
#include <zephyr/ztest.h>

LOG_MODULE_DECLARE(sof_boot_test, CONFIG_SOF_LOG_LEVEL);


ZTEST(sof_boot, virtual_memory_heap)
{
	TEST_CHECK_RET(true, "virtual_memory_heap");
}
