#ifndef __RLIBM_LATEST_LIBM_H__
#define __RLIBM_LATEST_LIBM_H__

#include <stdint.h>

typedef union {
  double d;
  uint64_t x;
} double_x;

typedef union {
  float f;
  uint32_t x;
} float_x;

double rlibm_log2(float);
double rlibm_log2_adapt(float);
double rlibm_log2_estrin(float);
double rlibm_log2_estrin_fma(float);

double rlibm_log10(float);
double rlibm_log10_estrin(float);
double rlibm_log10_estrin_fma(float);

double rlibm_log(float);
double rlibm_log_estrin(float);
double rlibm_log_estrin_fma(float);

double rlibm_exp2(float);
double rlibm_exp2_adapt(float);
double rlibm_exp2_estrin(float);
double rlibm_exp2_estrin_fma(float);

double rlibm_exp10(float);
double rlibm_exp10_adapt(float);
double rlibm_exp10_estrin(float);
double rlibm_exp10_estrin_fma(float);

double rlibm_exp(float);
double rlibm_exp_adapt(float);
double rlibm_exp_estrin(float);
double rlibm_exp_estrin_fma(float);

double log(double);
double log2(double);
double log10(double);
double exp(double);
double exp2(double);
double exp10(double);

#endif
