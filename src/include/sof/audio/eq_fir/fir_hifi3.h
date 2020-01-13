/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2017 Intel Corporation. All rights reserved.
 *
 * Author: Seppo Ingalsuo <seppo.ingalsuo@linux.intel.com>
 */

#ifndef __SOF_AUDIO_EQ_FIR_FIR_HIFI3_H__
#define __SOF_AUDIO_EQ_FIR_FIR_HIFI3_H__

#include <sof/audio/eq_fir/fir_config.h>

#if FIR_HIFI3

#include <sof/audio/buffer.h>
#include <xtensa/config/defs.h>
#include <xtensa/tie/xt_hifi3.h>

struct sof_eq_fir_coef_data;

struct fir_state_32x16 {
	ae_int32 *rwp; /* Circular read and write pointer */
	ae_int32 *delay; /* Pointer to FIR delay line */
	ae_int32 *delay_end; /* Pointer to FIR delay line end */
	ae_f16x4 *coef; /* Pointer to FIR coefficients */
	int taps; /* Number of FIR taps */
	int length; /* Number of FIR taps plus input length (even) */
	int in_shift; /* Amount of right shifts at input */
	int out_shift; /* Amount of right shifts at output */
};

void fir_reset(struct fir_state_32x16 *fir);

int fir_delay_size(struct sof_eq_fir_coef_data *config);

int fir_init_coef(struct fir_state_32x16 *fir,
		  struct sof_eq_fir_coef_data *config);

void fir_init_delay(struct fir_state_32x16 *fir, int32_t **data);

#if CONFIG_FORMAT_S16LE
void eq_fir_s16_hifi3(struct fir_state_32x16 *fir,
		      const struct audio_stream *source,
		      struct audio_stream *sink, int frames, int nch);

void eq_fir_2x_s16_hifi3(struct fir_state_32x16 *fir,
			 const struct audio_stream *source,
			 struct audio_stream *sink, int frames, int nch);
#endif /* CONFIG_FORMAT_S16LE */

#if CONFIG_FORMAT_S24LE
void eq_fir_s24_hifi3(struct fir_state_32x16 *fir,
		      const struct audio_stream *source,
		      struct audio_stream *sink, int frames, int nch);

void eq_fir_2x_s24_hifi3(struct fir_state_32x16 *fir,
			 const struct audio_stream *source,
			 struct audio_stream *sink, int frames, int nch);
#endif /* CONFIG_FORMAT_S24LE */

#if CONFIG_FORMAT_S32LE
void eq_fir_s32_hifi3(struct fir_state_32x16 *fir,
		      const struct audio_stream *source,
		      struct audio_stream *sink, int frames, int nch);

void eq_fir_2x_s32_hifi3(struct fir_state_32x16 *fir,
			 const struct audio_stream *source,
			 struct audio_stream *sink, int frames, int nch);
#endif /* CONFIG_FORMAT_S32LE */

/* Setup circular buffer for FIR input data delay */
static inline void fir_core_setup_circular(struct fir_state_32x16 *fir)
{
	AE_SETCBEGIN0(fir->delay);
	AE_SETCEND0(fir->delay_end);
}

/* Setup circular for component buffer */
static inline void fir_comp_setup_circular(const struct audio_stream *buffer)
{
	AE_SETCBEGIN0(buffer->addr);
	AE_SETCEND0(buffer->end_addr);
}

void fir_get_lrshifts(struct fir_state_32x16 *fir, int *lshift,
		      int *rshift);

/* The next functions are inlined to optmize execution speed */

/* HiFi EP has the follow number of reqisters that should not be exceeded
 * 4x 56 bit registers in register file Q
 * 8x 48 bit registers in register file P
 */

static inline void fir_32x16_hifi3(struct fir_state_32x16 *fir, ae_int32 x,
				   ae_int32 *y, int shift)
{
	/* This function uses
	 * 1x 56 bit registers Q,
	 * 4x 48 bit registers P
	 * 3x integers
	 * 2x address pointers,
	 */
	ae_f64 a;
	ae_valign u;
	ae_f32x2 data2;
	ae_f16x4 coefs;
	ae_f32x2 d0;
	ae_f32x2 d1;
	int i;
	ae_int32 *dp = fir->rwp;
	ae_int16x4 *coefp = (ae_int16x4 *)fir->coef;
	const int taps_div_4 = fir->taps >> 2;
	const int inc = sizeof(int32_t);

	/* Bypass samples if taps count is zero. */
	if (!taps_div_4) {
		*y = x;
		return;
	}

	/* Write sample to delay */
	AE_S32_L_XC(x, fir->rwp, -sizeof(int32_t));

	/* Prime the coefficients stream */
	u = AE_LA64_PP(coefp);

	/* Note: If the next function is converted to handle two samples
	 * per call the data load can be done with single instruction
	 * AE_LP24X2F_C(data2, dp, sizeof(ae_p24x2f));
	 */
	a = AE_ZEROQ56();
	for (i = 0; i < taps_div_4; i++) {
		/* Load four coefficients. Coef_3 contains tap h[n],
		 * coef_2 contains h[n+1], coef_1 contains h[n+2], and
		 * coef_0 contains h[n+3];
		 */
		AE_LA16X4_IP(coefs, u, coefp);

		/* Load two data samples and pack to d0 to data2_h and
		 * d1 to data2_l.
		 */
		AE_L32_XC(d0, dp, inc);
		AE_L32_XC(d1, dp, inc);
		data2 = AE_SEL32_LL(d0, d1);

		/* Accumulate
		 * a += data2_h * coefs_3 + data2_l * coefs_2. The Q1.31
		 * data and Q1.15 coefficients are used as 24 bits as
		 * Q1.23 values.
		 */
		AE_MULAAFD32X16_H3_L2(a, data2, coefs);

		/* Repeat the same for next two taps and increase coefp.
		 * a += data2_h * coefs_1 + data2_l * coefs_0.
		 */
		AE_L32_XC(d0, dp, inc);
		AE_L32_XC(d1, dp, inc);
		data2 = AE_SEL32_LL(d0, d1);
		AE_MULAAFD32X16_H1_L0(a, data2, coefs);
	}

	/* Do scaling shifts and store sample. */
	a = AE_SLAA64S(a, shift);
	AE_S32_L_I(AE_ROUND32F48SSYM(a), (ae_int32 *)y, 0);
}

/* HiFi EP has the follow number of reqisters that should not be exceeded
 * 4x 56 bit registers in register file Q
 * 8x 48 bit registers in register file P
 */

static inline void fir_32x16_2x_hifi3(struct fir_state_32x16 *fir, ae_int32 x0,
				      ae_int32 x1, ae_int32 *y0, ae_int32 *y1,
				      int shift)
{
	/* This function uses
	 * 2x 56 bit registers Q,
	 * 4x 48 bit registers P
	 * 3x integers
	 * 2x address pointers,
	 */
	ae_f64 a;
	ae_f64 b;
	ae_valign u;
	ae_f32x2 d0;
	ae_f32x2 d1;
	ae_f16x4 coefs;
	int i;
	ae_f32x2 *dp;
	ae_f16x4 *coefp = fir->coef;
	const int taps_div_4 = fir->taps >> 2;
	const int inc = 2 * sizeof(int32_t);

	/* Bypass samples if taps count is zero. */
	if (!taps_div_4) {
		*y0 = x0;
		*y1 = x1;
		return;
	}

	/* Write samples to delay */
	AE_S32_L_XC(x0, fir->rwp, -sizeof(int32_t));
	dp = (ae_f32x2 *)fir->rwp;
	AE_S32_L_XC(x1, fir->rwp, -sizeof(int32_t));

	/* Note: If the next function is converted to handle two samples
	 * per call the data load can be done with single instruction
	 * AE_LP24X2F_C(data2, dp, sizeof(ae_p24x2f));
	 */
	a = AE_ZERO64();
	b = AE_ZERO64();

	/* Prime the coefficients stream */
	u = AE_LA64_PP(coefp);

	/* Load two data samples and pack to d0 to data2_h and
	 * d1 to data2_l.
	 */
	AE_L32X2_XC(d0, dp, inc);
	for (i = 0; i < taps_div_4; i++) {
		/* Load four coefficients. Coef_3 contains tap h[n],
		 * coef_2 contains h[n+1], coef_1 contains h[n+2], and
		 * coef_0 contains h[n+3];
		 */
		AE_LA16X4_IP(coefs, u, coefp);

		/* Load two data samples. Upper part d1_h is x[n+1] and
		 * lower part d1_l is x[n].
		 */
		AE_L32X2_XC(d1, dp, inc);

		/* Quad MAC (HH)
		 * b += d0_h * coefs_3 + d0_l * coefs_2
		 * a += d0_l * coefs_3 + d1_h * coefs_2
		 */
		AE_MULAFD32X16X2_FIR_HH(b, a, d0, d1, coefs);
		d0 = d1;

		/* Repeat the same for next two taps and increase coefp. */
		AE_L32X2_XC(d1, dp, inc);

		/* Quad MAC (HL)
		 * b += d0_h * coefs_1 + d0_l * coefs_0
		 * a += d0_l * coefs_1 + d1_h * coefs_0
		 */
		AE_MULAFD32X16X2_FIR_HL(b, a, d0, d1, coefs);
		d0 = d1;
	}

	/* Do scaling shifts and store sample. */
	b = AE_SLAA64S(b, shift);
	a = AE_SLAA64S(a, shift);
	AE_S32_L_I(AE_ROUND32F48SSYM(b), (ae_int32 *)y1, 0);
	AE_S32_L_I(AE_ROUND32F48SSYM(a), (ae_int32 *)y0, 0);
}

#endif
#endif /* __SOF_AUDIO_EQ_FIR_FIR_HIFI3_H__ */
