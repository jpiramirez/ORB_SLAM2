//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CheckInlierVer1_0.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "sum.h"
#include "abs.h"
#include "CoefsAppendVer1_0.h"
#include "CheckInlierVer1_0_rtwutil.h"

// Function Definitions

//
// Arguments    : const double qSolBest[4]
//                const double m1Orig[21]
//                const double m2Orig[21]
//                const double m1Check[3]
//                const double m2Check[3]
//                double *residu
//                double *residues
// Return Type  : void
//
void CheckInlierVer1_0(const double qSolBest[4], const double m1Orig[21], const
  double m2Orig[21], const double m1Check[3], const double m2Check[3], double
  *residu, double *residues)
{
  double C[735];
  double b_C[21];
  double dv0[35];
  int i0;
  int i1;
  double dv1[21];

  // % Return a residue that can be used to find out if a matched set of feature points is an outlier 
  CoefsAppendVer1_0(m1Orig, m2Orig, m1Check, m2Check, C);

  //  Evaluate residues for all quaternion solutions
  //  Residues
  dv0[0] = rt_powd_snf(qSolBest[0], 4.0);
  dv0[1] = rt_powd_snf(qSolBest[0], 3.0) * qSolBest[1];
  dv0[2] = qSolBest[0] * qSolBest[0] * (qSolBest[1] * qSolBest[1]);
  dv0[3] = qSolBest[0] * rt_powd_snf(qSolBest[1], 3.0);
  dv0[4] = rt_powd_snf(qSolBest[1], 4.0);
  dv0[5] = rt_powd_snf(qSolBest[0], 3.0) * qSolBest[2];
  dv0[6] = qSolBest[0] * qSolBest[0] * qSolBest[1] * qSolBest[2];
  dv0[7] = qSolBest[0] * (qSolBest[1] * qSolBest[1]) * qSolBest[2];
  dv0[8] = rt_powd_snf(qSolBest[1], 3.0) * qSolBest[2];
  dv0[9] = qSolBest[0] * qSolBest[0] * (qSolBest[2] * qSolBest[2]);
  dv0[10] = qSolBest[0] * qSolBest[1] * (qSolBest[2] * qSolBest[2]);
  dv0[11] = qSolBest[1] * qSolBest[1] * (qSolBest[2] * qSolBest[2]);
  dv0[12] = qSolBest[0] * rt_powd_snf(qSolBest[2], 3.0);
  dv0[13] = qSolBest[1] * rt_powd_snf(qSolBest[2], 3.0);
  dv0[14] = rt_powd_snf(qSolBest[2], 4.0);
  dv0[15] = rt_powd_snf(qSolBest[0], 3.0) * qSolBest[3];
  dv0[16] = qSolBest[0] * qSolBest[0] * qSolBest[1] * qSolBest[3];
  dv0[17] = qSolBest[0] * (qSolBest[1] * qSolBest[1]) * qSolBest[3];
  dv0[18] = rt_powd_snf(qSolBest[1], 3.0) * qSolBest[3];
  dv0[19] = qSolBest[0] * qSolBest[0] * qSolBest[2] * qSolBest[3];
  dv0[20] = qSolBest[0] * qSolBest[1] * qSolBest[2] * qSolBest[3];
  dv0[21] = qSolBest[1] * qSolBest[1] * qSolBest[2] * qSolBest[3];
  dv0[22] = qSolBest[0] * (qSolBest[2] * qSolBest[2]) * qSolBest[3];
  dv0[23] = qSolBest[1] * (qSolBest[2] * qSolBest[2]) * qSolBest[3];
  dv0[24] = rt_powd_snf(qSolBest[2], 3.0) * qSolBest[3];
  dv0[25] = qSolBest[0] * qSolBest[0] * (qSolBest[3] * qSolBest[3]);
  dv0[26] = qSolBest[0] * qSolBest[1] * (qSolBest[3] * qSolBest[3]);
  dv0[27] = qSolBest[1] * qSolBest[1] * (qSolBest[3] * qSolBest[3]);
  dv0[28] = qSolBest[0] * qSolBest[2] * (qSolBest[3] * qSolBest[3]);
  dv0[29] = qSolBest[1] * qSolBest[2] * (qSolBest[3] * qSolBest[3]);
  dv0[30] = qSolBest[2] * qSolBest[2] * (qSolBest[3] * qSolBest[3]);
  dv0[31] = qSolBest[0] * rt_powd_snf(qSolBest[3], 3.0);
  dv0[32] = qSolBest[1] * rt_powd_snf(qSolBest[3], 3.0);
  dv0[33] = qSolBest[2] * rt_powd_snf(qSolBest[3], 3.0);
  dv0[34] = rt_powd_snf(qSolBest[3], 4.0);
  for (i0 = 0; i0 < 21; i0++) {
    b_C[i0] = 0.0;
    for (i1 = 0; i1 < 35; i1++) {
      b_C[i0] += C[i0 + 21 * i1] * dv0[i1];
    }
  }

  b_abs(b_C, dv1);
  *residues = sum(dv1);

  //  residue corresponding to the best quaternion solution
  *residu = *residues;
}

//
// File trailer for CheckInlierVer1_0.cpp
//
// [EOF]
//
