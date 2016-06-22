//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Quat7PtVer3_4.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "Quat7PtVer3_4.h"
#include "kron.h"
#include "sum.h"
#include "abs.h"
#include "mldivide.h"
#include "eml_sort.h"
#include "power.h"
#include "bsxfun.h"
#include "sign.h"
#include "eig.h"
#include "mrdivide.h"
#include "diag.h"
#include "qr.h"
#include "CoefsVer3_1.h"
#include "CheckInlierVer1_0_rtwutil.h"

// Function Declarations
static void fValVer2_0(const double xn[4], const double C0[1260], const double
  c0[36], double F[36], double J[144]);

// Function Definitions

//
// Arguments    : const double xn[4]
//                const double C0[1260]
//                const double c0[36]
//                double F[36]
//                double J[144]
// Return Type  : void
//
static void fValVer2_0(const double xn[4], const double C0[1260], const double
  c0[36], double F[36], double J[144])
{
  double dv11[35];
  int i8;
  double d1;
  int i9;
  double dv12[140];
  int i10;

  // % Function for Newton's method
  //  F is a function, and J is the Jacobian of F
  //  syms q1 q2 q3 q4
  //  Fucntion
  dv11[0] = rt_powd_snf(xn[0], 4.0);
  dv11[1] = rt_powd_snf(xn[0], 3.0) * xn[1];
  dv11[2] = xn[0] * xn[0] * (xn[1] * xn[1]);
  dv11[3] = xn[0] * rt_powd_snf(xn[1], 3.0);
  dv11[4] = rt_powd_snf(xn[1], 4.0);
  dv11[5] = rt_powd_snf(xn[0], 3.0) * xn[2];
  dv11[6] = xn[0] * xn[0] * xn[1] * xn[2];
  dv11[7] = xn[0] * (xn[1] * xn[1]) * xn[2];
  dv11[8] = rt_powd_snf(xn[1], 3.0) * xn[2];
  dv11[9] = xn[0] * xn[0] * (xn[2] * xn[2]);
  dv11[10] = xn[0] * xn[1] * (xn[2] * xn[2]);
  dv11[11] = xn[1] * xn[1] * (xn[2] * xn[2]);
  dv11[12] = xn[0] * rt_powd_snf(xn[2], 3.0);
  dv11[13] = xn[1] * rt_powd_snf(xn[2], 3.0);
  dv11[14] = rt_powd_snf(xn[2], 4.0);
  dv11[15] = rt_powd_snf(xn[0], 3.0) * xn[3];
  dv11[16] = xn[0] * xn[0] * xn[1] * xn[3];
  dv11[17] = xn[0] * (xn[1] * xn[1]) * xn[3];
  dv11[18] = rt_powd_snf(xn[1], 3.0) * xn[3];
  dv11[19] = xn[0] * xn[0] * xn[2] * xn[3];
  dv11[20] = xn[0] * xn[1] * xn[2] * xn[3];
  dv11[21] = xn[1] * xn[1] * xn[2] * xn[3];
  dv11[22] = xn[0] * (xn[2] * xn[2]) * xn[3];
  dv11[23] = xn[1] * (xn[2] * xn[2]) * xn[3];
  dv11[24] = rt_powd_snf(xn[2], 3.0) * xn[3];
  dv11[25] = xn[0] * xn[0] * (xn[3] * xn[3]);
  dv11[26] = xn[0] * xn[1] * (xn[3] * xn[3]);
  dv11[27] = xn[1] * xn[1] * (xn[3] * xn[3]);
  dv11[28] = xn[0] * xn[2] * (xn[3] * xn[3]);
  dv11[29] = xn[1] * xn[2] * (xn[3] * xn[3]);
  dv11[30] = xn[2] * xn[2] * (xn[3] * xn[3]);
  dv11[31] = xn[0] * rt_powd_snf(xn[3], 3.0);
  dv11[32] = xn[1] * rt_powd_snf(xn[3], 3.0);
  dv11[33] = xn[2] * rt_powd_snf(xn[3], 3.0);
  dv11[34] = rt_powd_snf(xn[3], 4.0);
  for (i8 = 0; i8 < 36; i8++) {
    d1 = 0.0;
    for (i9 = 0; i9 < 35; i9++) {
      d1 += C0[i8 + 36 * i9] * dv11[i9];
    }

    F[i8] = d1 - c0[i8];
  }

  //  J = jacobian(F)
  dv12[0] = 4.0 * rt_powd_snf(xn[0], 3.0);
  dv12[35] = 0.0;
  dv12[70] = 0.0;
  dv12[105] = 0.0;
  dv12[1] = 3.0 * (xn[0] * xn[0]) * xn[1];
  dv12[36] = rt_powd_snf(xn[0], 3.0);
  dv12[71] = 0.0;
  dv12[106] = 0.0;
  dv12[2] = 2.0 * xn[0] * (xn[1] * xn[1]);
  dv12[37] = 2.0 * (xn[0] * xn[0]) * xn[1];
  dv12[72] = 0.0;
  dv12[107] = 0.0;
  dv12[3] = rt_powd_snf(xn[1], 3.0);
  dv12[38] = 3.0 * xn[0] * (xn[1] * xn[1]);
  dv12[73] = 0.0;
  dv12[108] = 0.0;
  dv12[4] = 0.0;
  dv12[39] = 4.0 * rt_powd_snf(xn[1], 3.0);
  dv12[74] = 0.0;
  dv12[109] = 0.0;
  dv12[5] = 3.0 * (xn[0] * xn[0]) * xn[2];
  dv12[40] = 0.0;
  dv12[75] = rt_powd_snf(xn[0], 3.0);
  dv12[110] = 0.0;
  dv12[6] = 2.0 * xn[0] * xn[1] * xn[2];
  dv12[41] = xn[0] * xn[0] * xn[2];
  dv12[76] = xn[0] * xn[0] * xn[1];
  dv12[111] = 0.0;
  dv12[7] = xn[1] * xn[1] * xn[2];
  dv12[42] = 2.0 * xn[0] * xn[1] * xn[2];
  dv12[77] = xn[0] * (xn[1] * xn[1]);
  dv12[112] = 0.0;
  dv12[8] = 0.0;
  dv12[43] = 3.0 * (xn[1] * xn[1]) * xn[2];
  dv12[78] = rt_powd_snf(xn[1], 3.0);
  dv12[113] = 0.0;
  dv12[9] = 2.0 * xn[0] * (xn[2] * xn[2]);
  dv12[44] = 0.0;
  dv12[79] = 2.0 * (xn[0] * xn[0]) * xn[2];
  dv12[114] = 0.0;
  dv12[10] = xn[1] * (xn[2] * xn[2]);
  dv12[45] = xn[0] * (xn[2] * xn[2]);
  dv12[80] = 2.0 * xn[0] * xn[1] * xn[2];
  dv12[115] = 0.0;
  dv12[11] = 0.0;
  dv12[46] = 2.0 * xn[1] * (xn[2] * xn[2]);
  dv12[81] = 2.0 * (xn[1] * xn[1]) * xn[2];
  dv12[116] = 0.0;
  dv12[12] = rt_powd_snf(xn[2], 3.0);
  dv12[47] = 0.0;
  dv12[82] = 3.0 * xn[0] * (xn[2] * xn[2]);
  dv12[117] = 0.0;
  dv12[13] = 0.0;
  dv12[48] = rt_powd_snf(xn[2], 3.0);
  dv12[83] = 3.0 * xn[1] * (xn[2] * xn[2]);
  dv12[118] = 0.0;
  dv12[14] = 0.0;
  dv12[49] = 0.0;
  dv12[84] = 4.0 * rt_powd_snf(xn[2], 3.0);
  dv12[119] = 0.0;
  dv12[15] = 3.0 * (xn[0] * xn[0]) * xn[3];
  dv12[50] = 0.0;
  dv12[85] = 0.0;
  dv12[120] = rt_powd_snf(xn[0], 3.0);
  dv12[16] = 2.0 * xn[0] * xn[1] * xn[3];
  dv12[51] = xn[0] * xn[0] * xn[3];
  dv12[86] = 0.0;
  dv12[121] = xn[0] * xn[0] * xn[1];
  dv12[17] = xn[1] * xn[1] * xn[3];
  dv12[52] = 2.0 * xn[0] * xn[1] * xn[3];
  dv12[87] = 0.0;
  dv12[122] = xn[0] * (xn[1] * xn[1]);
  dv12[18] = 0.0;
  dv12[53] = 3.0 * (xn[1] * xn[1]) * xn[3];
  dv12[88] = 0.0;
  dv12[123] = rt_powd_snf(xn[1], 3.0);
  dv12[19] = 2.0 * xn[0] * xn[2] * xn[3];
  dv12[54] = 0.0;
  dv12[89] = xn[0] * xn[0] * xn[3];
  dv12[124] = xn[0] * xn[0] * xn[2];
  dv12[20] = xn[1] * xn[2] * xn[3];
  dv12[55] = xn[0] * xn[2] * xn[3];
  dv12[90] = xn[0] * xn[1] * xn[3];
  dv12[125] = xn[0] * xn[1] * xn[2];
  dv12[21] = 0.0;
  dv12[56] = 2.0 * xn[1] * xn[2] * xn[3];
  dv12[91] = xn[1] * xn[1] * xn[3];
  dv12[126] = xn[1] * xn[1] * xn[2];
  dv12[22] = xn[2] * xn[2] * xn[3];
  dv12[57] = 0.0;
  dv12[92] = 2.0 * xn[0] * xn[2] * xn[3];
  dv12[127] = xn[0] * (xn[2] * xn[2]);
  dv12[23] = 0.0;
  dv12[58] = xn[2] * xn[2] * xn[3];
  dv12[93] = 2.0 * xn[1] * xn[2] * xn[3];
  dv12[128] = xn[1] * (xn[2] * xn[2]);
  dv12[24] = 0.0;
  dv12[59] = 0.0;
  dv12[94] = 3.0 * (xn[2] * xn[2]) * xn[3];
  dv12[129] = rt_powd_snf(xn[2], 3.0);
  dv12[25] = 2.0 * xn[0] * (xn[3] * xn[3]);
  dv12[60] = 0.0;
  dv12[95] = 0.0;
  dv12[130] = 2.0 * (xn[0] * xn[0]) * xn[3];
  dv12[26] = xn[1] * (xn[3] * xn[3]);
  dv12[61] = xn[0] * (xn[3] * xn[3]);
  dv12[96] = 0.0;
  dv12[131] = 2.0 * xn[0] * xn[1] * xn[3];
  dv12[27] = 0.0;
  dv12[62] = 2.0 * xn[1] * (xn[3] * xn[3]);
  dv12[97] = 0.0;
  dv12[132] = 2.0 * (xn[1] * xn[1]) * xn[3];
  dv12[28] = xn[2] * (xn[3] * xn[3]);
  dv12[63] = 0.0;
  dv12[98] = xn[0] * (xn[3] * xn[3]);
  dv12[133] = 2.0 * xn[0] * xn[2] * xn[3];
  dv12[29] = 0.0;
  dv12[64] = xn[2] * (xn[3] * xn[3]);
  dv12[99] = xn[1] * (xn[3] * xn[3]);
  dv12[134] = 2.0 * xn[1] * xn[2] * xn[3];
  dv12[30] = 0.0;
  dv12[65] = 0.0;
  dv12[100] = 2.0 * xn[2] * (xn[3] * xn[3]);
  dv12[135] = 2.0 * (xn[2] * xn[2]) * xn[3];
  dv12[31] = rt_powd_snf(xn[3], 3.0);
  dv12[66] = 0.0;
  dv12[101] = 0.0;
  dv12[136] = 3.0 * xn[0] * (xn[3] * xn[3]);
  dv12[32] = 0.0;
  dv12[67] = rt_powd_snf(xn[3], 3.0);
  dv12[102] = 0.0;
  dv12[137] = 3.0 * xn[1] * (xn[3] * xn[3]);
  dv12[33] = 0.0;
  dv12[68] = 0.0;
  dv12[103] = rt_powd_snf(xn[3], 3.0);
  dv12[138] = 3.0 * xn[2] * (xn[3] * xn[3]);
  dv12[34] = 0.0;
  dv12[69] = 0.0;
  dv12[104] = 0.0;
  dv12[139] = 4.0 * rt_powd_snf(xn[3], 3.0);
  for (i8 = 0; i8 < 36; i8++) {
    for (i9 = 0; i9 < 4; i9++) {
      J[i8 + 36 * i9] = 0.0;
      for (i10 = 0; i10 < 35; i10++) {
        J[i8 + 36 * i9] += C0[i8 + 36 * i10] * dv12[i10 + 35 * i9];
      }
    }
  }
}

//
// Initialize required matrices
// Arguments    : const double m1[21]
//                const double m2[21]
//                double qSol[16]
//                double qRes[4]
// Return Type  : void
//
void Quat7PtVer3_4(const double m1[21], const double m2[21], double qSol[16],
                   double qRes[4])
{
  double C0[1260];
  double b_C0[1225];
  int i4;
  int i5;
  int i;
  static const signed char b[1225] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  double R0[1225];
  double unusedU0[1225];
  double b_R0[60];
  double c_R0[60];
  double dv3[6];
  double Rn[60];
  double Rr[60];
  int b_i;
  double Rn_data[5];
  int tmp_size[1];
  double b_Rr[10];
  int colMat_size[2];
  double colMat_data[50];
  int unnamed_idx_0;
  double b_colMat_data[100];
  int colMat_size_idx_0;
  double Q4[12];
  static const signed char iv0[4] = { 1, 0, 0, 0 };

  double Q1Pos[16];
  static const signed char iv1[4] = { -1, 0, 0, 0 };

  double Q1Neg[16];
  static const signed char iv2[3] = { 2, 4, 5 };

  double dv4[16];
  static const signed char iv3[4] = { 0, 0, 0, 1 };

  creal_T unusedU1[16];
  creal_T VP[16];
  static const signed char iv4[4] = { 0, 0, 0, -1 };

  creal_T unusedU2[16];
  double VPos[16];
  double VNeg[16];
  double b_VPos[4];
  double c_VPos[16];
  double b_VNeg[16];
  double dv5[16];
  double difPos[16];
  double d0;
  double b_Q1Neg[16];
  double dv6[16];
  double dv7[16];
  double dv8[4];
  double resAll[8];
  int iidx[8];
  double d_VPos[32];
  double xn[4];
  int F_size[1];
  double F_data[36];
  double difX;
  int k;
  double J[144];
  double F[36];
  static const double dv9[36] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  double xnp1[4];
  double b_xnp1;
  double dv10[4];
  double tmp_data[36];

  // % Seven Point Pose Estimation using Quaternion
  //
  //  NOTE: Include the folder "Helpers" in Matlab path before execution.
  //
  //
  //  Inputs:
  //
  //  m1   : Homogeneous coordinates of 7 image points in the first camera
  //         coordinate frame. Each column of m1 has the format [u, v, 1]^T,
  //         where u and v are coordinate of the feature point. Thus, m1 is
  //         a 3*7 matrix, where all elements in the last row are one.
  //
  //  m2   : Homogeneous coordinates of 7 image points in the second camera
  //         coordinate frame. Each column of m2 has the format [u, v, 1]^T,
  //         where u and v are coordinate of the feature point. Thus, m2 is
  //         a 3*7 matrix, where all elements in the last row are one.
  //
  //
  //
  //  Outputs:
  //
  //  qSol: Matrix of all recovered quaternion solutions. Each column
  //        of the matrix corresponds to a quaternion solution candidate.
  //
  //  qRes: Residue of the recovered quaternion solutions corresponding to the
  //        conditoin C0 * q.^4 = c0. When there is no noise, the residue value  
  //        corresponding to the correct solution is zero.
  //
  //
  //
  //
  //  Copyright (C) 2013-2016, by Kaveh Fathian.
  //
  //  This program is a free software: you can redistribute it and/or modify it
  //  under the terms of the GNU lesser General Public License as published by
  //  the Free Software Foundation, either version 3 of the License, or
  //  (at your option) any later version.
  //
  //  This program is distributed in the hope that it will be useful,
  //  but WITHOUT ANY WARRANTY; without even the implied warranty of
  //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //  GNU Lesser General Public License for more details.
  //
  //  You should have received a copy of the GNU Lesser General Public License
  //  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  //
  //
  // % Ver 3_4:
  //        - Solves the problem using row-echelon form
  //        - Refines the solutions uisng Newton's method
  //        - The solution is derived based on the assumption that q(1)> 0,
  //          that is, the rotation is smaller than 180 deg. This assumption is
  //          true for most practical applications, although the method can be
  //          generalized to include any rotation.
  //        - The residue of each 4 solutions are saved in qRes. The minimum
  //          value of qRes corresponds to the best solution.
  //
  //
  // % Linearization
  //  Coefficinet matrix in the linearized system of multinomials (Ca * x = c)
  CoefsVer3_1(m1, m2, C0);

  //  Coefficinet matrix in the linearized system of multinomials (C * x = 0)
  //  Permute matrix C0 s.t. last 10 columns correspond to
  //  q = [q0*q1
  //       q0*q2
  //       q0*q3
  //       q1*q2
  //       q1*q3
  //       q2*q3
  //       q0^2
  //       q1^2
  //       q2^2
  //       q3^2];
  // % QR factorization
  for (i4 = 0; i4 < 35; i4++) {
    for (i5 = 0; i5 < 35; i5++) {
      b_C0[i4 + 35 * i5] = 0.0;
      for (i = 0; i < 35; i++) {
        b_C0[i4 + 35 * i5] += C0[i4 + 36 * i] * (double)b[i + 35 * i5];
      }
    }
  }

  qr(b_C0, unusedU0, R0);

  //  Note: the expected nullity of matrix C is 4
  //  Remove zero rows of R and only keep the required part (rows 26 to 31, columns 26 to 35) 
  //  % Reduces row echelon form (usign Matlab's algorithm)
  //  Rr = rref(R);
  // % Reduces row echelon form for C++ code generation
  //  Diagonal elements of R
  //  Normalize the diagonal elements
  for (i4 = 0; i4 < 10; i4++) {
    for (i5 = 0; i5 < 6; i5++) {
      b_R0[i5 + 6 * i4] = R0[(i5 + 35 * (25 + i4)) + 25];
      c_R0[i5 + 6 * i4] = R0[(i5 + 35 * (25 + i4)) + 25];
    }
  }

  diag(b_R0, dv3);
  bsxfun(c_R0, dv3, Rn);
  memcpy(&Rr[0], &Rn[0], 60U * sizeof(double));
  for (b_i = 0; b_i < 5; b_i++) {
    i = 5 - b_i;
    tmp_size[0] = 5 - b_i;
    for (i4 = 0; i4 < i; i4++) {
      Rn_data[i4] = Rn[i4 + 6 * (5 - b_i)];
    }

    for (i4 = 0; i4 < 10; i4++) {
      b_Rr[i4] = Rr[(6 * i4 - b_i) + 5];
    }

    kron(Rn_data, tmp_size, b_Rr, colMat_data, colMat_size);
    unnamed_idx_0 = b_i + 1;
    colMat_size_idx_0 = colMat_size[0] + unnamed_idx_0;
    for (i4 = 0; i4 < 10; i4++) {
      i = colMat_size[0];
      for (i5 = 0; i5 < i; i5++) {
        b_colMat_data[i5 + colMat_size_idx_0 * i4] = colMat_data[i5 +
          colMat_size[0] * i4];
      }
    }

    for (i4 = 0; i4 < 10; i4++) {
      for (i5 = 0; i5 < unnamed_idx_0; i5++) {
        b_colMat_data[(i5 + colMat_size[0]) + colMat_size_idx_0 * i4] = 0.0;
      }
    }

    for (i4 = 0; i4 < 10; i4++) {
      for (i5 = 0; i5 < 6; i5++) {
        Rr[i5 + 6 * i4] -= b_colMat_data[i5 + 6 * i4];
      }
    }
  }

  // %
  //  Sub-matrices of row-echelon form matrix correcponding to q1^2 * [q_i q_j]
  //  elements. Specifically if q := [q_1; q_2; q_3; q_4], then
  //   q_1 * q = Q1 * q.^2,
  //   q_4 * q = Q4 * q.^2
  for (i4 = 0; i4 < 4; i4++) {
    //  Add the unit norm constraint (q_1^2 + q_2^2 + q_3^2 + q_4^2 = 1) to the matrices 
    Q1Pos[i4 << 2] = iv0[i4];
    Q1Neg[i4 << 2] = iv1[i4];
    for (i5 = 0; i5 < 3; i5++) {
      Q4[i5 + 3 * i4] = Rr[iv2[i5] + 6 * (6 + i4)];
      Q1Pos[(i5 + (i4 << 2)) + 1] = Rr[i5 + 6 * (6 + i4)];
      Q1Neg[(i5 + (i4 << 2)) + 1] = Rr[i5 + 6 * (6 + i4)];

      //
      //  Define VP and VN as complex 4*4 matrices (required for C++ code generation) 
      dv4[i5 + (i4 << 2)] = Q4[i5 + 3 * i4];
    }

    dv4[3 + (i4 << 2)] = iv3[i4];
  }

  mrdivide(dv4, Q1Pos);
  eig(dv4, VP, unusedU1);
  for (i4 = 0; i4 < 4; i4++) {
    for (i5 = 0; i5 < 3; i5++) {
      dv4[i5 + (i4 << 2)] = Q4[i5 + 3 * i4];
    }

    dv4[3 + (i4 << 2)] = iv4[i4];
  }

  mrdivide(dv4, Q1Neg);
  eig(dv4, unusedU1, unusedU2);

  //  Use only the real parts
  for (i4 = 0; i4 < 16; i4++) {
    VPos[i4] = VP[i4].re;
    VNeg[i4] = unusedU1[i4].re;
  }

  //  Correct the sign of each column vector s.t. the first element is always positive 
  for (i4 = 0; i4 < 4; i4++) {
    b_VPos[i4] = VPos[i4 << 2];
  }

  b_sign(b_VPos);
  memcpy(&c_VPos[0], &VPos[0], sizeof(double) << 4);
  b_bsxfun(b_VPos, c_VPos, VPos);
  for (i4 = 0; i4 < 4; i4++) {
    b_VPos[i4] = VNeg[i4 << 2];
  }

  b_sign(b_VPos);
  memcpy(&b_VNeg[0], &VNeg[0], sizeof(double) << 4);
  b_bsxfun(b_VPos, b_VNeg, VNeg);

  //  Check to see if the condition   q_1 * q = Q1 * q.^2  is satisfied
  for (i4 = 0; i4 < 4; i4++) {
    b_VPos[i4] = VPos[i4 << 2];
  }

  b_bsxfun(b_VPos, VPos, dv4);
  power(VPos, dv5);
  for (i4 = 0; i4 < 4; i4++) {
    for (i5 = 0; i5 < 4; i5++) {
      d0 = 0.0;
      for (i = 0; i < 4; i++) {
        d0 += Q1Pos[i4 + (i << 2)] * dv5[i + (i5 << 2)];
      }

      difPos[i4 + (i5 << 2)] = dv4[i4 + (i5 << 2)] - d0;
    }
  }

  for (i4 = 0; i4 < 4; i4++) {
    b_VPos[i4] = VNeg[i4 << 2];
    for (i5 = 0; i5 < 4; i5++) {
      b_Q1Neg[i5 + (i4 << 2)] = -Q1Neg[i5 + (i4 << 2)];
    }
  }

  b_bsxfun(b_VPos, VNeg, dv4);
  power(VNeg, dv5);
  for (i4 = 0; i4 < 4; i4++) {
    for (i5 = 0; i5 < 4; i5++) {
      d0 = 0.0;
      for (i = 0; i < 4; i++) {
        d0 += b_Q1Neg[i4 + (i << 2)] * dv5[i + (i5 << 2)];
      }

      Q1Pos[i4 + (i5 << 2)] = dv4[i4 + (i5 << 2)] - d0;
    }
  }

  //  Residual values for condition q_1 * q = Q1 * q.^2
  c_abs(difPos, dv6);
  b_sum(dv6, b_VPos);
  c_abs(Q1Pos, dv7);
  b_sum(dv7, dv8);
  for (i4 = 0; i4 < 4; i4++) {
    resAll[i4] = b_VPos[i4];
  }

  for (i4 = 0; i4 < 4; i4++) {
    resAll[i4 + 4] = dv8[i4];
  }

  //  Pick 4 solution candidates with the least residues
  eml_sort(resAll, iidx);
  for (i4 = 0; i4 < 4; i4++) {
    for (i5 = 0; i5 < 4; i5++) {
      d_VPos[i5 + (i4 << 2)] = VPos[i5 + (i4 << 2)];
    }
  }

  for (i4 = 0; i4 < 4; i4++) {
    for (i5 = 0; i5 < 4; i5++) {
      d_VPos[i5 + ((i4 + 4) << 2)] = VNeg[i5 + (i4 << 2)];
    }
  }

  for (i4 = 0; i4 < 4; i4++) {
    for (i5 = 0; i5 < 4; i5++) {
      Q1Pos[i5 + (i4 << 2)] = d_VPos[i5 + ((iidx[i4] - 1) << 2)];
    }
  }

  // % Use Newton's method to refine the recovered pose
  //  Matrix of recovered quaternion
  //  Residue values corresponding to condition C0 * q^4 = c0
  for (b_i = 0; b_i < 4; b_i++) {
    // %%%%%%%%%%%%%%%%%%%%%%%%% Newton Method %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    //  Tolerence
    //  Maximum number of iterations
    for (i4 = 0; i4 < 4; i4++) {
      xn[i4] = Q1Pos[i4 + (b_i << 2)];
    }

    //  Initial value
    F_size[0] = 35;
    for (i4 = 0; i4 < 35; i4++) {
      F_data[i4] = 1.0;
    }

    //  Preallocate F (required for C++ code generation)
    difX = 1.00001;
    k = 0;
    while ((difX >= 1.0E-5) && (k <= 5)) {
      fValVer2_0(xn, C0, dv9, F, J);
      F_size[0] = 36;
      memcpy(&F_data[0], &F[0], 36U * sizeof(double));
      mldivide(J, F, xnp1);

      //  calculate x_{n+1}
      for (i4 = 0; i4 < 4; i4++) {
        b_xnp1 = xn[i4] - xnp1[i4];
        b_VPos[i4] = b_xnp1 - xn[i4];
        xnp1[i4] = b_xnp1;
      }

      d_abs(b_VPos, dv10);
      difX = c_sum(dv10);
      for (i = 0; i < 4; i++) {
        xn[i] = xnp1[i];
      }

      k++;
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    //  Save residue value (l1 norm)
    e_abs(F_data, F_size, tmp_data, tmp_size);
    qRes[b_i] = d_sum(tmp_data, tmp_size);

    //  Save optimized quaternion vector
    for (i4 = 0; i4 < 4; i4++) {
      qSol[i4 + (b_i << 2)] = xn[i4];
    }
  }
}

//
// File trailer for Quat7PtVer3_4.cpp
//
// [EOF]
//
