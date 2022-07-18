// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2019 Intel Corporation. All rights reserved.
//
// Author: Lech Betlej <lech.betlej@linux.intel.com>

/**
 * \file
 * \brief Audio channel selector / extractor - generic processing functions
 * \authors Lech Betlej <lech.betlej@linux.intel.com>
 */

#include <sof/audio/buffer.h>
#include <sof/audio/component.h>
#include <sof/audio/selector.h>
#include <sof/common.h>
#include <ipc/stream.h>
#include <stddef.h>
#include <stdint.h>

LOG_MODULE_DECLARE(selector, CONFIG_SOF_LOG_LEVEL);

#if CONFIG_FORMAT_S16LE
/**
 * \brief Channel selection for 16 bit, 1 channel data format.
 * \param[in,out] dev Selector base component device.
 * \param[in,out] sink Destination buffer.
 * \param[in,out] source Source buffer.
 * \param[in] frames Number of frames to process.
 */
static void sel_s16le_1ch(struct comp_dev *dev, struct audio_stream __sparse_cache *sink,
			  const struct audio_stream __sparse_cache *source, uint32_t frames)
{
	struct comp_data *cd = comp_get_drvdata(dev);
	int16_t *src = source->r_ptr;
	int16_t *dest = sink->w_ptr;
	int16_t *src_ch;
	int nmax;
	int i;
	int n;
	int processed = 0;
	const int source_frame_bytes = audio_stream_frame_bytes(source);
	const unsigned int nch = source->channels;
	const unsigned int sel_channel = cd->config.sel_channel; /* 0 to nch - 1 */

	while (processed < frames) {
		n = frames - processed;
		nmax = audio_stream_bytes_without_wrap(source, src) / source_frame_bytes;
		n = MIN(n, nmax);
		nmax = BYTES_TO_S16_SAMPLES(audio_stream_bytes_without_wrap(sink, dest));
		n = MIN(n, nmax);
		src_ch = src + sel_channel;
		for (i = 0; i < n; i++) {
			*dest = *src_ch;
			src_ch += nch;
			dest++;
		}
		src = audio_stream_wrap(source, src + nch * n);
		dest = audio_stream_wrap(sink, dest);
		processed += n;
	}
}

/**
 * \brief Channel selection for 16 bit, at least 2 channels data format.
 * \param[in,out] dev Selector base component device.
 * \param[in,out] sink Destination buffer.
 * \param[in,out] source Source buffer.
 * \param[in] frames Number of frames to process.
 */
static void sel_s16le_nch(struct comp_dev *dev, struct audio_stream __sparse_cache *sink,
			  const struct audio_stream __sparse_cache *source, uint32_t frames)
{
	int8_t *src = (int8_t *)source->r_ptr;
	int8_t *dst = (int8_t *)sink->w_ptr;
	int bmax;
	int b;
	int bytes_copied = 0;
	const int bytes_total = frames * audio_stream_frame_bytes(source);

	while (bytes_copied < bytes_total) {
		b = bytes_total - bytes_copied;
		bmax = audio_stream_bytes_without_wrap(source, src);
		b = MIN(b, bmax);
		bmax = audio_stream_bytes_without_wrap(sink, dst);
		b = MIN(b, bmax);
		memcpy(dst, src, b);
		src = audio_stream_wrap(source, src + b);
		dst = audio_stream_wrap(sink, dst + b);
		bytes_copied += b;
	}
}
#endif /* CONFIG_FORMAT_S16LE */

#if CONFIG_FORMAT_S24LE || CONFIG_FORMAT_S32LE
/**
 * \brief Channel selection for 32 bit, 1 channel data format.
 * \param[in,out] dev Selector base component device.
 * \param[in,out] sink Destination buffer.
 * \param[in,out] source Source buffer.
 * \param[in] frames Number of frames to process.
 */
static void sel_s32le_1ch(struct comp_dev *dev, struct audio_stream __sparse_cache *sink,
			  const struct audio_stream __sparse_cache *source, uint32_t frames)
{
	struct comp_data *cd = comp_get_drvdata(dev);
	int32_t *src = source->r_ptr;
	int32_t *dest = sink->w_ptr;
	int32_t *src_ch;
	int nmax;
	int i;
	int n;
	int processed = 0;
	const int source_frame_bytes = audio_stream_frame_bytes(source);
	const unsigned int nch = source->channels;
	const unsigned int sel_channel = cd->config.sel_channel; /* 0 to nch - 1 */

	while (processed < frames) {
		n = frames - processed;
		nmax = audio_stream_bytes_without_wrap(source, src) / source_frame_bytes;
		n = MIN(n, nmax);
		nmax = BYTES_TO_S32_SAMPLES(audio_stream_bytes_without_wrap(sink, dest));
		n = MIN(n, nmax);
		src_ch = src + sel_channel;
		for (i = 0; i < n; i++) {
			*dest = *src_ch;
			src_ch += nch;
			dest++;
		}
		src = audio_stream_wrap(source, src + nch * n);
		dest = audio_stream_wrap(sink, dest);
		processed += n;
	}
}

/**
 * \brief Channel selection for 32 bit, at least 2 channels data format.
 * \param[in,out] dev Selector base component device.
 * \param[in,out] sink Destination buffer.
 * \param[in,out] source Source buffer.
 * \param[in] frames Number of frames to process.
 */
static void sel_s32le_nch(struct comp_dev *dev, struct audio_stream __sparse_cache *sink,
			  const struct audio_stream __sparse_cache *source, uint32_t frames)
{
	int8_t *src = (int8_t *)source->r_ptr;
	int8_t *dst = (int8_t *)sink->w_ptr;
	int bmax;
	int b;
	int bytes_copied = 0;
	const int bytes_total = frames * audio_stream_frame_bytes(source);

	while (bytes_copied < bytes_total) {
		b = bytes_total - bytes_copied;
		bmax = audio_stream_bytes_without_wrap(source, src);
		b = MIN(b, bmax);
		bmax = audio_stream_bytes_without_wrap(sink, dst);
		b = MIN(b, bmax);
		memcpy(dst, src, b);
		src = audio_stream_wrap(source, src + b);
		dst = audio_stream_wrap(sink, dst + b);
		bytes_copied += b;
	}
}
#endif /* CONFIG_FORMAT_S24LE || CONFIG_FORMAT_S32LE */

const struct comp_func_map func_table[] = {
#if CONFIG_FORMAT_S16LE
	{SOF_IPC_FRAME_S16_LE, 1, sel_s16le_1ch},
	{SOF_IPC_FRAME_S16_LE, 2, sel_s16le_nch},
	{SOF_IPC_FRAME_S16_LE, 4, sel_s16le_nch},
#endif /* CONFIG_FORMAT_S16LE */
#if CONFIG_FORMAT_S24LE
	{SOF_IPC_FRAME_S24_4LE, 1, sel_s32le_1ch},
	{SOF_IPC_FRAME_S24_4LE, 2, sel_s32le_nch},
	{SOF_IPC_FRAME_S24_4LE, 4, sel_s32le_nch},
#endif /* CONFIG_FORMAT_S24LE */
#if CONFIG_FORMAT_S32LE
	{SOF_IPC_FRAME_S32_LE, 1, sel_s32le_1ch},
	{SOF_IPC_FRAME_S32_LE, 2, sel_s32le_nch},
	{SOF_IPC_FRAME_S32_LE, 4, sel_s32le_nch},
#endif /* CONFIG_FORMAT_S32LE */
};

sel_func sel_get_processing_function(struct comp_dev *dev)
{
	struct comp_data *cd = comp_get_drvdata(dev);
	int i;

	/* map the channel selection function for source and sink buffers */
	for (i = 0; i < ARRAY_SIZE(func_table); i++) {
		if (cd->source_format != func_table[i].source)
			continue;
		if (cd->config.out_channels_count != func_table[i].out_channels)
			continue;

		/* TODO: add additional criteria as needed */
		return func_table[i].sel_func;
	}

	return NULL;
}
