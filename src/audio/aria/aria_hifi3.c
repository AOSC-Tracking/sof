// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2021 Intel Corporation. All rights reserved.

#include <sof/audio/aria/aria.h>

#if __XCC__ && (XCHAL_HAVE_HIFI3 || XCHAL_HAVE_HIFI4)
#include <xtensa/config/defs.h>
#include <xtensa/tie/xt_hifi3.h>

/**
 * \brief Aria gain index mapping table
 */
const uint8_t INDEX_TAB[] = {
		0,    1,    2,    3,
		4,    5,    6,    7,
		8,    9,    0,    1,
		2,    3,    4,    5,
		6,    7,    8,    9,
		0,    1,    2,    3
};

inline void aria_algo_calc_gain(struct comp_dev *dev, size_t gain_idx,
				struct audio_stream __sparse_cache *source, int frames)
{
	struct aria_data *cd = comp_get_drvdata(dev);
	/* detecting maximum value in data chunk */
	ae_int32x2 in_sample;
	ae_int32x2 max_data = AE_ZERO32();
	int32_t att = cd->att;
	ae_valign inu = AE_ZALIGN64();
	uint64_t gain = (1ULL << (att + 32)) - 1;
	int32_t *max_ptr = (int32_t *)&max_data;
	int32_t max;
	int samples = frames * audio_stream_get_channels(source);
	ae_int32x2 *in = audio_stream_get_rptr(source);
	int i, n, m;

	while (samples) {
		n = audio_stream_samples_without_wrap_s32(source, in);
		n = MIN(samples, n);
		m = n >> 1;
		inu = AE_LA64_PP(in);
		for (i = 0; i < m; i++) {
			AE_LA32X2_IP(in_sample, inu, in);
			max_data = AE_MAXABS32S(max_data, in_sample);
		}
		if (n & 1) {
			AE_L32_IP(in_sample, (ae_int32 *)in, sizeof(ae_int32));
			max_data = AE_MAXABS32S(max_data, in_sample);
		}
		max = MAX(max_ptr[0], max_ptr[1]);
		in = audio_stream_wrap(source, in);
		samples -= n;
	}

	if (max > (0x7fffffff >> att) && max != 0)
		gain = (0x7fffffffULL << 32) / max;

	/* normalization by attenuation factor to obtain fractional range <1 / (2 pow att), 1> */
	cd->gains[gain_idx] = (int32_t)(gain >> (att + 1));
}

void aria_algo_get_data(struct comp_dev *dev, struct audio_stream __sparse_cache *sink, int frames)
{
	struct aria_data *cd = comp_get_drvdata(dev);
	size_t i, m, n, ch;
	ae_int32x2 step;
	int32_t gain_state_add_2 = cd->gain_state + 2;
	int32_t gain_state_add_3 = cd->gain_state + 3;
	int32_t gain_begin = cd->gains[INDEX_TAB[gain_state_add_2]];
	/* do linear approximation between points gain_begin and gain_end */
	int32_t gain_end = cd->gains[INDEX_TAB[gain_state_add_3]];
	size_t samples = frames * audio_stream_get_channels(sink);
	ae_int32x2 *out = audio_stream_get_wptr(sink);
	int32_t att = cd->att;
	ae_int32x2 *in = (ae_int32x2 *)cd->data_ptr;
	ae_valign inu = AE_ZALIGN64();
	ae_valign outu = AE_ZALIGN64();
	ae_int32x2 in_sample, out_sample;
	const int inc = sizeof(ae_int32);
	ae_int32x2 gain;
	const int ch_n = cd->chan_cnt;

	for (i = 1; i < ARIA_MAX_GAIN_STATES - 1; i++) {
		if (cd->gains[INDEX_TAB[gain_state_add_2 + i]] < gain_begin)
			gain_begin = cd->gains[INDEX_TAB[gain_state_add_2 + i]];
		if (cd->gains[INDEX_TAB[gain_state_add_3 + i]] < gain_end)
			gain_end = cd->gains[INDEX_TAB[gain_state_add_3 + i]];
	}

	step = (gain_end - gain_begin) / frames;
	gain = gain_begin;
	while (samples) {
		m = audio_stream_samples_without_wrap_s32(sink, out);
		n = MIN(m, samples);
		m = cir_buf_samples_without_wrap_s32(cd->data_ptr, cd->data_end);
		n = MIN(m, n);
		inu = AE_LA64_PP(in);
		for (i = 0; i < n; i += ch_n) {
			if (ch_n & 1)
				/*process data one by one if ch_n is odd*/
				for (ch = 0; ch < ch_n; ch++) {
					AE_L32_XP(in_sample, (ae_int32 *)in, inc);
					out_sample = AE_MULFP32X2RS(in_sample, gain);

					out_sample = AE_SLAA32S(out_sample, att);
					AE_S32_L_XP(out_sample, (ae_int32 *)out, inc);
				}
			else
				/*process 2 samples per time if ch_n is even*/
				for (ch = 0; ch < ch_n; ch += 2) {
					AE_LA32X2_IP(in_sample, inu, in);
					out_sample = AE_MULFP32X2RS(in_sample, gain);

					out_sample = AE_SLAA32S(out_sample, att);
					AE_SA32X2_IP(out_sample, outu, out);
				}
			gain = AE_ADD32S(gain, step);
		}
		AE_SA64POS_FP(outu, out);
		samples -= n;
		in = cir_buf_wrap(in, cd->data_addr, cd->data_end);
		out = audio_stream_wrap(sink, out);
	}
	cd->gain_state = INDEX_TAB[cd->gain_state + 1];
}
#endif
