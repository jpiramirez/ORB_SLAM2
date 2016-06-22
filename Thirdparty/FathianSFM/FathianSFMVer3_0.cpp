//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FathianSFMVer3_0.cpp
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
#include "rdivide.h"
#include "abs.h"
#include "svd.h"
#include "Quat7PtVer3_4.h"

// Function Definitions

//
// Run the 7pt algorithm to recover the rotation quaternion
// Arguments    : const double m1[21]
//                const double m2[21]
//                double qBest[4]
//                double tBest[3]
//                double *resBest
// Return Type  : void
//
void FathianSFMVer3_0(const double m1[21], const double m2[21], double qBest[4],
                      double tBest[3], double *resBest)
{
  double qRes[4];
  double qSol[16];
  int ixstart;
  double mtmp;
  int itmp;
  int ix;
  boolean_T exitg1;
  int i2;
  double M1[112];
  double M2[112];
  int i;
  double Qbar[12];
  double B[476];
  signed char tmp_data[28];
  int i3;
  int b_i;
  double b_M1[4];
  double b_M2[16];
  double c_M2[4];
  double c_M1[8];
  double N[289];
  double unusedU1[289];
  double unusedU0[476];
  double b_N[5];
  double dv2[5];
  double z1Sum;
  double z[14];
  boolean_T b_z[14];
  boolean_T c_z[14];

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
  //  qBest:   a 4*1 vector for the (uniquely) recovered quaternion solution.
  //
  //  tBest:   a 3*1 translation vector corresponding to the recovered quaternion. 
  //
  //  resBest: Residue of the recovered quaternion corresponding to the equality 
  //           C0 * q.^4 = c0. When there is no noise, the residue value
  //           should be zero.
  //
  Quat7PtVer3_4(m1, m2, qSol, qRes);

  //  Chosse quaternion with least residue as the unique solution
  ixstart = 1;
  mtmp = qRes[0];
  itmp = 0;
  if (rtIsNaN(qRes[0])) {
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix + 1 < 5)) {
      ixstart = ix + 1;
      if (!rtIsNaN(qRes[ix])) {
        mtmp = qRes[ix];
        itmp = ix;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 4) {
    while (ixstart + 1 < 5) {
      if (qRes[ixstart] < mtmp) {
        mtmp = qRes[ixstart];
        itmp = ixstart;
      }

      ixstart++;
    }
  }

  *resBest = mtmp;
  for (i2 = 0; i2 < 4; i2++) {
    qBest[i2] = qSol[i2 + (itmp << 2)];
  }

  //  Recover the translation vector (up to a scale factor) for the quaternion
  // % Five Point Pose Estimation using Quaternion
  //
  //  This script recovers the corresponding translation and depth for each
  //  quaternion solution candidate.
  //
  //  Inputs:
  //         m1  : A 3*5 matrix containing the homogeneous coordinates of 5
  //               feature points in the 1st camera view.
  //
  //         m2  : A 3*5 matrix containing the homogeneous coordinates of 5
  //               feature points in the 2nd camera view.
  //
  //         qSol: Quaternion solution candidates recovered from m1 and m2.
  //
  //
  //
  //  Outputs:
  //       tSol    : Matrix of the recovered translation vectors. Each column
  //                 corresponds to a quaternion solution.
  //
  //       zSolCam1: Matrix of the recovered depths in the coordinate frame of
  //                 the camera at 1st view.
  //
  //       zSolCam2: Matrix of the recovered depths in the coordinate frame of
  //                 the camera at 2nd view.
  //
  //
  //  Copyright (C) 2013-2015, by Kaveh Fathian.
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
  //  Number of feature points
  //  Number of recovered solution candidates
  //  Preallocate variables
  //  Recover depth and translation for each solution candidate
  //  Pick a quaternion solution candidate
  //  Generate matrices ^1M_i, ^2M_i, and Qbar
  for (i = 0; i < 7; i++) {
    M1[i << 4] = 0.0;
    M1[4 + (i << 4)] = m1[3 * i];
    M1[8 + (i << 4)] = m1[1 + 3 * i];
    M1[12 + (i << 4)] = 1.0;
    M1[1 + (i << 4)] = m1[3 * i];
    M1[5 + (i << 4)] = 0.0;
    M1[9 + (i << 4)] = 1.0;
    M1[13 + (i << 4)] = -m1[1 + 3 * i];
    M1[2 + (i << 4)] = m1[1 + 3 * i];
    M1[6 + (i << 4)] = -1.0;
    M1[10 + (i << 4)] = 0.0;
    M1[14 + (i << 4)] = m1[3 * i];
    M1[3 + (i << 4)] = 1.0;
    M1[7 + (i << 4)] = m1[1 + 3 * i];
    M1[11 + (i << 4)] = -m1[3 * i];
    M1[15 + (i << 4)] = 0.0;
    M2[i << 4] = 0.0;
    M2[4 + (i << 4)] = m2[3 * i];
    M2[8 + (i << 4)] = m2[1 + 3 * i];
    M2[12 + (i << 4)] = 1.0;
    M2[1 + (i << 4)] = m2[3 * i];
    M2[5 + (i << 4)] = 0.0;
    M2[9 + (i << 4)] = -1.0;
    M2[13 + (i << 4)] = m2[1 + 3 * i];
    M2[2 + (i << 4)] = m2[1 + 3 * i];
    M2[6 + (i << 4)] = 1.0;
    M2[10 + (i << 4)] = 0.0;
    M2[14 + (i << 4)] = -m2[3 * i];
    M2[3 + (i << 4)] = 1.0;
    M2[7 + (i << 4)] = -m2[1 + 3 * i];
    M2[11 + (i << 4)] = m2[3 * i];
    M2[15 + (i << 4)] = 0.0;
  }

  Qbar[0] = qSol[1 + (itmp << 2)];
  Qbar[4] = qSol[2 + (itmp << 2)];
  Qbar[8] = qSol[3 + (itmp << 2)];
  Qbar[1] = qSol[itmp << 2];
  Qbar[5] = qSol[3 + (itmp << 2)];
  Qbar[9] = -qSol[2 + (itmp << 2)];
  Qbar[2] = -qSol[3 + (itmp << 2)];
  Qbar[6] = qSol[itmp << 2];
  Qbar[10] = qSol[1 + (itmp << 2)];
  Qbar[3] = qSol[2 + (itmp << 2)];
  Qbar[7] = -qSol[1 + (itmp << 2)];
  Qbar[11] = qSol[itmp << 2];

  //  Stack all matrices in matrix B
  memset(&B[0], 0, 476U * sizeof(double));
  for (i = 0; i < 7; i++) {
    i2 = (i << 2) + 1;
    i3 = (1 + i) << 2;
    if (i2 > i3) {
      i2 = 0;
      i3 = 0;
    } else {
      i2--;
    }

    ixstart = i3 - i2;
    for (ix = 0; ix < ixstart; ix++) {
      tmp_data[ix] = (signed char)(i2 + ix);
    }

    ixstart = i3 - i2;
    for (i2 = 0; i2 < 3; i2++) {
      for (i3 = 0; i3 < ixstart; i3++) {
        B[tmp_data[i3] + 28 * i2] = Qbar[i3 + ixstart * i2];
      }
    }

    i2 = (i << 2) + 1;
    i3 = (1 + i) << 2;
    if (i2 > i3) {
      i2 = 0;
      i3 = 0;
    } else {
      i2--;
    }

    ixstart = i3 - i2;
    for (ix = 0; ix < ixstart; ix++) {
      tmp_data[ix] = (signed char)(i2 + ix);
    }

    b_i = i << 1;
    for (ix = 0; ix < 4; ix++) {
      b_M1[ix] = 0.0;
      for (ixstart = 0; ixstart < 4; ixstart++) {
        b_M1[ix] += M1[(ix + (ixstart << 2)) + (i << 4)] * qSol[ixstart + (itmp <<
          2)];
      }

      for (ixstart = 0; ixstart < 4; ixstart++) {
        b_M2[ixstart + (ix << 2)] = -M2[(ixstart + (ix << 2)) + (i << 4)];
      }
    }

    for (ix = 0; ix < 4; ix++) {
      c_M2[ix] = 0.0;
      for (ixstart = 0; ixstart < 4; ixstart++) {
        c_M2[ix] += b_M2[ix + (ixstart << 2)] * qSol[ixstart + (itmp << 2)];
      }

      c_M1[ix] = b_M1[ix];
      c_M1[4 + ix] = c_M2[ix];
    }

    ixstart = i3 - i2;
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < ixstart; i3++) {
        B[tmp_data[i3] + 28 * ((i2 + b_i) + 3)] = c_M1[i3 + ixstart * i2];
      }
    }
  }

  //  Use SVD to find all singular vectors
  svd(B, unusedU0, unusedU1, N);

  //  The right singular vector corresponding to the zero singular value of B.
  //     %% Normalize the depth and translation
  b_N[0] = N[275];
  b_N[1] = N[277];
  b_N[2] = N[279];
  b_N[3] = N[281];
  b_N[4] = N[283];
  f_abs(b_N, dv2);
  z1Sum = e_sum(dv2);

  //  Normalize translation and depth such that the sum of depths of points
  //  in the 1st camera coor. frame is one.
  rdivide(*(double (*)[3])&(*(double (*)[17])&N[272])[0], z1Sum, tBest);
  b_rdivide(*(double (*)[14])&(*(double (*)[17])&N[272])[3], z1Sum, z);

  //     %% Adjust the sign (s.t. recovered depth is positive)
  for (i = 0; i < 14; i++) {
    b_z[i] = (z[i] > 0.0);
    c_z[i] = (z[i] < 0.0);
  }

  if (f_sum(b_z) < f_sum(c_z)) {
    for (i2 = 0; i2 < 3; i2++) {
      tBest[i2] = -tBest[i2];
    }
  }

  //     %% Store the recovered translation and depths
  //  Translation vector
  //  Depths in cam frame 1
  //  Depths in cam frame 2
}

//
// File trailer for FathianSFMVer3_0.cpp
//
// [EOF]
//
