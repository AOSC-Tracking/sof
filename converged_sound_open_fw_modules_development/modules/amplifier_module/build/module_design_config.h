// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2021 Intel Corporation. All rights reserved.

/*  (this file was generated -- do not edit)  */
#ifndef MODULE_DESIGN_CONFIG_H_
#define MODULE_DESIGN_CONFIG_H_

#define INPUT_NUMBER 1
#define OUTPUT_NUMBER 1

#include <stdint.h>

/*
 *  sizeof(queue_buf) for a reference pin (INPUT_NUMBER > 1) equals:
 *  RoundUp(Max(src_mod_output_chunk_size, designed_mod_input_chunk_size), 64) * 3 + sizeof(queue_object)
 *  chunk_size = max_sample_group * max_channels_num * max_sample_size / sizeof(uint8_t)
 */
#pragma pack(4)
struct RefQueueBuffers
{
};
#pragma pack()

#define DESIGN_CONFIG  INPUT_NUMBER, OUTPUT_NUMBER, sizeof(RefQueueBuffers)

#endif // MODULE_DESIGN_CONFIG_H_
/*  (this file was generated -- do not edit)  */
