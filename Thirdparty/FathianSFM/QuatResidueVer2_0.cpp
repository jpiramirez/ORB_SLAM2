//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: QuatResidueVer2_0.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "CoefsVer4_0.h"
#include "CheckInlierVer1_0_rtwutil.h"

// Function Definitions

//
// numSol = size(qSol,2);
// Arguments    : const double m1[21]
//                const double m2[21]
//                const double qSol[4]
//                double *residu
//                double C[1225]
// Return Type  : void
//
void QuatResidueVer2_0(const double m1[21], const double m2[21], const double
  qSol[4], double *residu, double C[1225])
{
  double dv13[35];
  double y[35];
  int k;
  double residuMat[35];
  int i11;

  // % Calculate the residue value |C x - c| for estimated quaternion solutions
  //  Coefficinet matrix in the linearized system of multinomials (C * x = c)
  CoefsVer4_0(m1, m2, C);

  //  Residues
  dv13[0] = rt_powd_snf(qSol[0], 4.0);
  dv13[1] = rt_powd_snf(qSol[0], 3.0) * qSol[1];
  dv13[2] = qSol[0] * qSol[0] * (qSol[1] * qSol[1]);
  dv13[3] = qSol[0] * rt_powd_snf(qSol[1], 3.0);
  dv13[4] = rt_powd_snf(qSol[1], 4.0);
  dv13[5] = rt_powd_snf(qSol[0], 3.0) * qSol[2];
  dv13[6] = qSol[0] * qSol[0] * qSol[1] * qSol[2];
  dv13[7] = qSol[0] * (qSol[1] * qSol[1]) * qSol[2];
  dv13[8] = rt_powd_snf(qSol[1], 3.0) * qSol[2];
  dv13[9] = qSol[0] * qSol[0] * (qSol[2] * qSol[2]);
  dv13[10] = qSol[0] * qSol[1] * (qSol[2] * qSol[2]);
  dv13[11] = qSol[1] * qSol[1] * (qSol[2] * qSol[2]);
  dv13[12] = qSol[0] * rt_powd_snf(qSol[2], 3.0);
  dv13[13] = qSol[1] * rt_powd_snf(qSol[2], 3.0);
  dv13[14] = rt_powd_snf(qSol[2], 4.0);
  dv13[15] = rt_powd_snf(qSol[0], 3.0) * qSol[3];
  dv13[16] = qSol[0] * qSol[0] * qSol[1] * qSol[3];
  dv13[17] = qSol[0] * (qSol[1] * qSol[1]) * qSol[3];
  dv13[18] = rt_powd_snf(qSol[1], 3.0) * qSol[3];
  dv13[19] = qSol[0] * qSol[0] * qSol[2] * qSol[3];
  dv13[20] = qSol[0] * qSol[1] * qSol[2] * qSol[3];
  dv13[21] = qSol[1] * qSol[1] * qSol[2] * qSol[3];
  dv13[22] = qSol[0] * (qSol[2] * qSol[2]) * qSol[3];
  dv13[23] = qSol[1] * (qSol[2] * qSol[2]) * qSol[3];
  dv13[24] = rt_powd_snf(qSol[2], 3.0) * qSol[3];
  dv13[25] = qSol[0] * qSol[0] * (qSol[3] * qSol[3]);
  dv13[26] = qSol[0] * qSol[1] * (qSol[3] * qSol[3]);
  dv13[27] = qSol[1] * qSol[1] * (qSol[3] * qSol[3]);
  dv13[28] = qSol[0] * qSol[2] * (qSol[3] * qSol[3]);
  dv13[29] = qSol[1] * qSol[2] * (qSol[3] * qSol[3]);
  dv13[30] = qSol[2] * qSol[2] * (qSol[3] * qSol[3]);
  dv13[31] = qSol[0] * rt_powd_snf(qSol[3], 3.0);
  dv13[32] = qSol[1] * rt_powd_snf(qSol[3], 3.0);
  dv13[33] = qSol[2] * rt_powd_snf(qSol[3], 3.0);
  dv13[34] = rt_powd_snf(qSol[3], 4.0);
  for (k = 0; k < 35; k++) {
    residuMat[k] = 0.0;
    for (i11 = 0; i11 < 35; i11++) {
      residuMat[k] += C[k + 35 * i11] * dv13[i11];
    }

    y[k] = fabs(residuMat[k]);
  }

  *residu = y[0];
  for (k = 0; k < 34; k++) {
    *residu += y[k + 1];
  }
}

//
// File trailer for QuatResidueVer2_0.cpp
//
// [EOF]
//
