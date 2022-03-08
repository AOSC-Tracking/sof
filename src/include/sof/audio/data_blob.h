/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2022 Intel Corporation. All rights reserved.
 *
 * Author: Jyri Sarha <jyri.sarha@intel.com>
 */

#ifndef __SOF_AUDIO_DATA_BLOB_H__
#define __SOF_AUDIO_DATA_BLOB_H__

#include <sof/sof.h>

struct comp_dev;

struct comp_data_blob_handler;

/**
 * Returns data blob. In case when new data blob is available it returns new
 * one. Function returns also data blob size in case when size pointer is given.
 *
 * @param blob_handler Data blob handler
 * @param size Pointer to data blob size variable
 * @param crc Pointer to data blolb crc value
 */
void *comp_get_data_blob(struct comp_data_blob_handler *blob_handler,
			 size_t *size, uint32_t *crc);

/**
 * Checks whether new data blob is available. Function allows to check (even
 * during streaming - in copy() function) whether new config is available and
 * if it is, component can perform reconfiguration.
 *
 * @param blob_handler Data blob handler
 */
bool comp_is_new_data_blob_available(struct comp_data_blob_handler
					*blob_handler);

/**
 * Initializes data blob with given value. If init_data is not specified,
 * function will zero data blob.
 *
 * @param blob_handler Data blob handler
 * @param size Data blob size
 * @param init_data Initial data blob values
 */
int comp_init_data_blob(struct comp_data_blob_handler *blob_handler,
			uint32_t size, void *init_data);

/**
 * Handles IPC set command.
 *
 * @param blob_handler Data blob handler
 * @param cdata IPC ctrl data
 */
int comp_data_blob_set_cmd(struct comp_data_blob_handler *blob_handler,
			   struct sof_ipc_ctrl_data *cdata);
/**
 * Handles IPC get command.
 * @param blob_handler Data blob handler
 * @param cdata IPC ctrl data
 * @param size Required size
 */
int comp_data_blob_get_cmd(struct comp_data_blob_handler *blob_handler,
			   struct sof_ipc_ctrl_data *cdata, int size);

/**
 * Returns new data blob handler.
 *
 * @param dev Component device
 */
struct comp_data_blob_handler *comp_data_blob_handler_new(struct comp_dev *dev);

/**
 * Free data blob handler.
 *
 * @param blob_handler Data blob handler
 */
void comp_data_blob_handler_free(struct comp_data_blob_handler *blob_handler);

#endif /* __SOF_AUDIO_DATA_BLOB_H__ */
