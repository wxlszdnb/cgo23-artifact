#include "rlibm.h"
#include "log2.h"
#include <math.h>

double rlibm_log2_adapt(float x) {
  float_x fix, fit, spec;
  fix.f = x;
  int m = 0;

  if (fix.x < 0x800000 || fix.x >= 0x7F800000) {
    if ((fix.x & 0x7FFFFFFF) == 0) { // log(+/-0) = -infty
      fix.x = 0xFF800000;
      return fix.f;
    }
    
    if (fix.x > 0x7FFFFFFF) { // Log(-val) = NaN
      return (x - x) / 0;
        
    }
    
    if (fix.x >= 0x7F800000) {
      return x + x;
    }

    // Special case when we have denormal input and exact result
    int exp;
    spec.f = frexpf(fix.f, &exp);
    if (spec.x == 0x3f000000) return (double)(exp - 1);

    fix.f *= 8.388608e+06;
    m -= 23;
  }
  
  m += fix.x >> 23;
  m -= 127;
  fix.x &= 0x007FFFFF;
  
  if (fix.x == 0) {
    return (double)m;
  }
  
  fix.x |= 0x3F800000;
  
  fit.x = fix.x & 0x007F0000;
  int FIndex = fit.x >> 16;
  fit.x |= 0x3F800000;
  
  double f = fix.f - fit.f;
  f *= __log_oneByF[FIndex];

  double k = f + 6.2205068595460266678287553077097982168197631835937500000000000000000000e-02;
  double z = k*k;
  double y = z + 1.7674195338269491628579999087378382682800292968750000000000000000000000e+00;
  y *= z;
  y += 4.6589452159712134715618958580307662487030029296875000000000000000000000e+00;
  y *= (f + -1.3433279529358896908775022893678396940231323242187500000000000000000000e+00);
  y += 6.2676984433124776074919282109476625919342041015625000000000000000000000e+00;
  y *= 3.3020203420754101752976339412271045148372650146484375000000000000000000e-01;

  y += __log2_lut[FIndex];
  y += m;
  
  return y;
}
