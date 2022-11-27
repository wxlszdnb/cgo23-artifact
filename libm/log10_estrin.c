#include "rlibm.h"
#include "log10.h"
#include "math.h"

#define LOG102HIGH 0.30102999566398114250631579125183634459972381591796875
#define LOG102LOW  5.27074231034726570126349709198449199648263806413338306011695522101945243775844573974609375e-17

double rlibm_log10_estrin(float x) {
  float_x fix, fit;
  fix.f = x;
  int m = 0;

  if (fix.f == 0x1.265154p+0){
    return 0x1.f03dea8p-5;
  }

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
      
      fix.f *= 8.388608e+06;
      m -= 23;
  }

  switch (fix.x) {
  case 0x3f800000 : return 0.0;
  case 0x41200000 : return 1.0;
  case 0x42c80000 : return 2.0;
  case 0x447a0000 : return 3.0;
  case 0x461c4000 : return 4.0;
  case 0x47c35000 : return 5.0;
  case 0x49742400 : return 6.0;
  case 0x4b189680 : return 7.0;
  case 0x4cbebc20 : return 8.0;
  case 0x4e6e6b28 : return 9.0;
  case 0x501502f9 : return 10.0;
  }
  
  m += fix.x >> 23;
  m -= 127;
  fix.x &= 0x007FFFFF;
  fix.x |= 0x3F800000;
  
  fit.x = fix.x & 0x007F0000;
  int FIndex = fit.x >> 16;
  fit.x |= 0x3F800000;
  
  double f = fix.f - fit.f;
  f *= log_oneByF[FIndex];

  double y;

  if (f < 2.6440486729702099115424385189498934778384864330291748046875e-03) {
    if (f < 1.32204691569010415221063770019327421323396265506744384765625e-03) {
      // 1st sub-domain
      y = f*4.3429448189781855171887059441360179334878921508789062500000000000000000e-01;
      y += f*f*(-2.1714721804400019533609622612857492640614509582519531250000000000000000e-01 + f*1.4473422532229135439862943712796550244092941284179687500000000000000000e-01);
      y += f*f*f*f*-9.5737458758581334139492469148535747081041336059570312500000000000000000e-02;
    } else {
      // 2nd sub-doomain
      if(f == 2.1962431288257088478343970194828216335736215114593505859375000000000000e-03){
          y = 9.5276969354843397269627658374702150467783212661743164062500000000000000e-04;
      } else{
          y = f*4.3429448184451485692747496614174451678991317749023437500000000000000000e-01;
          y += f*f*(-2.1714714669530019164334078141109785065054893493652343750000000000000000e-01 + f*1.4471541198011303452908293820655671879649162292480468750000000000000000e-01);
          y += f*f*f*f*-9.9928508614256034148226603974762838333845138549804687500000000000000000e-02;
      }
    }
  } else {
    if (f < 3.95805722191220309136294730478766723535954952239990234375e-03) {
      // 3rd sub-domain
      if(f == 3.0512989015507516188385750410816399380564689636230468750000000000000000e-03){
          y = 1.3231444016983692855277121580570565129164606332778930664062500000000000e-03;
      } else if(f == 3.4018543279059577574829908996889571426436305046081542968750000000000000e-03){
          y = 1.4748992865482070391269786568955169059336185455322265625000000000000000e-03;
      } else if(f == 3.6675160325418307803724271565215531154535710811614990234375000000000000e-03){
          y = 1.5898682721431607947626396537543769227340817451477050781250000000000000e-03;
      } else{
          y = f*4.3429448183591634613520682250964455306529998779296875000000000000000000e-01;
          y += f*f*(-2.1714717902637165058976620457542594522237777709960937500000000000000000e-01 + f*1.4474493388075213018417741750454297289252281188964843750000000000000000e-01);
          y += f*f*f*f*-1.0607108213718817457671406145891523919999599456787109375000000000000000e-01;
      }
    } else {
      // 4th sub-domain
      if(f == 4.9144603587962963284208051106816128594800829887390136718750000000000000e-03){
          y = 2.1290956120136798716824255706114854547195136547088623046875000000000000e-03;
      } else if(f == 7.2027177953008390473566002754068904323503375053405761718750000000000000e-03){
          y = 3.1168889841416266492379882890872977441176772117614746093750000000000000e-03;
      } else if(f == 7.4919462203979492187500000000000000000000000000000000000000000000000000e-03){
          y = 3.2415831247761569926246760786625600303523242473602294921875000000000000e-03;
      } else{
          y = f*4.3429448187314961815630454111669678241014480590820312500000000000000000e-01;
          y += f*f*(-2.1714721081355303766713404911570250988006591796875000000000000000000000e-01 + f*1.4475413180100188403898187061713542789220809936523437500000000000000000e-01);
          y += f*f*f*f*-1.0697036250738632678913830886813229881227016448974609375000000000000000e-01;
      }
    }
  }
  
  y += m * LOG102LOW;
  y += log10_lut[FIndex];
  y += m * LOG102HIGH;
  
  return y;
}
