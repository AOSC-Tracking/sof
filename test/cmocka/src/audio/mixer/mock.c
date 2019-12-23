// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2018 Intel Corporation. All rights reserved.
//
// Author: Slawomir Blauciak <slawomir.blauciak@linux.intel.com>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <malloc.h>
#include <cmocka.h>

#include <sof/lib/alloc.h>
#include <sof/audio/component.h>

#include "comp_mock.h"

#include <mock_trace.h>

TRACE_IMPL()

void *_balloc(uint32_t flags, uint32_t caps, size_t bytes,
	      uint32_t alignment)
{
	(void)flags;
	(void)caps;

	return malloc(bytes);
}

void *_zalloc(enum mem_zone zone, uint32_t flags, uint32_t caps, size_t bytes)
{
	(void)zone;
	(void)flags;
	(void)caps;

	return calloc(bytes, 1);
}

void rfree(void *ptr)
{
	free(ptr);
}

void *_brealloc(void *ptr, uint32_t flags, uint32_t caps, size_t bytes,
		uint32_t alignment)
{
	(void)flags;
	(void)caps;

	return realloc(ptr, bytes);
}

void pipeline_xrun(struct pipeline *p, struct comp_dev *dev, int32_t bytes)
{
}

int comp_set_state(struct comp_dev *dev, int cmd)
{
	return 0;
}

void __panic(uint32_t p, char *filename, uint32_t linenum)
{
	(void)p;
	(void)filename;
	(void)linenum;
}
