/*
 * Copyright (c) 2017, Intel Corporation
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
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include <platform/memory.h>

#define SUE_GPIO_OFFSET(x)	((x) + DW_GPIO_BASE)
#define SUE_GPIO_PORTA_DAT_REG	SUE_GPIO_OFFSET(0x00)
#define SUE_GPIO_PORTA_DIR_REG	SUE_GPIO_OFFSET(0x04)
#define SUE_GPIO_PORTA_CTL_REG	SUE_GPIO_OFFSET(0x08)

#define SUE_IOMUX_OFFSET(x)	((x) + EXT_CTRL_BASE)
#define SUE_IOMUX_CTL0_REG	SUE_IOMUX_OFFSET(0x30)
#define SUE_IOMUX_CTL1_REG	SUE_IOMUX_OFFSET(0x34)


#define SUE_LEVEL_HI		1
#define SUE_LEVEL_LO		0

#define SUE_GPIO_DIR_OUT	1
#define SUE_GPIO_DIE_IN		0


/* the GPIO pin number */
enum GPIO {
	GPIO0 = 0,
	GPIO1,
	GPIO2,
	GPIO3,
	GPIO4,
	GPIO5,
	GPIO6,
	GPIO7,
	GPIO8,
	GPIO9,
	GPIO10,
	GPIO11,
	GPIO12,
	GPIO13,
	GPIO14,
	GPIO15,
	GPIO16,
	GPIO17,
	GPIO18,
	GPIO19,
	GPIO20,
	GPIO21,
	GPIO22,
	GPIO23,
	GPIO24,
	GPIO25,
	GPIO_NUM,
};

int gpio_config(enum GPIO port, int dir);
int gpio_read(enum GPIO port);
int gpio_write(enum GPIO port, int level);

#endif
