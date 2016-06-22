//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CoefsAppendVer1_0.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "CoefsAppendVer1_0.h"

// Function Declarations
static void coefsDenVer2_0(const double mx2[27], const double my2[27], const
  double nx1[27], const double nx2[27], const double ny1[27], const double ny2
  [27], const double r1[27], const double r2[27], const double s2[27], double
  coefsD[270]);
static void coefsNumVer2_0(const double mx1[27], const double mx2[27], const
  double my1[27], const double my2[27], const double nx2[27], const double ny2
  [27], const double r2[27], const double s1[27], const double s2[27], double
  coefsN[270]);

// Function Definitions

//
// Arguments    : const double mx2[27]
//                const double my2[27]
//                const double nx1[27]
//                const double nx2[27]
//                const double ny1[27]
//                const double ny2[27]
//                const double r1[27]
//                const double r2[27]
//                const double s2[27]
//                double coefsD[270]
// Return Type  : void
//
static void coefsDenVer2_0(const double mx2[27], const double my2[27], const
  double nx1[27], const double nx2[27], const double ny1[27], const double ny2
  [27], const double r1[27], const double r2[27], const double s2[27], double
  coefsD[270])
{
  int i;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;

  // %
  for (i = 0; i < 27; i++) {
    t2 = mx2[i] * ny1[i] * r2[i];
    t3 = my2[i] * nx2[i] * r1[i];
    t4 = nx1[i] * ny2[i] * s2[i];
    t5 = mx2[i] * nx2[i] * r1[i] * 2.0;
    t6 = my2[i] * ny2[i] * r1[i] * 2.0;
    t7 = mx2[i] * nx2[i] * ny1[i] * 2.0;
    t8 = ny1[i] * r2[i] * s2[i] * 2.0;
    t9 = my2[i] * nx1[i] * r2[i];
    t10 = nx2[i] * ny1[i] * s2[i];
    t11 = my2[i] * nx1[i] * ny2[i] * 2.0;
    t12 = nx1[i] * r2[i] * s2[i] * 2.0;
    t13 = mx2[i] * ny2[i] * r1[i];
    coefsD[i] = ((((t2 + t3) + t4) - mx2[i] * ny2[i] * r1[i]) - my2[i] * nx1[i] *
                 r2[i]) - nx2[i] * ny1[i] * s2[i];
    coefsD[27 + i] = ((t11 + t12) - my2[i] * nx2[i] * ny1[i] * 2.0) - nx2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[54 + i] = ((t7 + t8) - mx2[i] * nx1[i] * ny2[i] * 2.0) - ny2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[81 + i] = ((t5 + t6) - mx2[i] * nx1[i] * r2[i] * 2.0) - my2[i] *
      ny1[i] * r2[i] * 2.0;
    coefsD[108 + i] = ((((t2 - t3) - t4) + t9) + t10) - mx2[i] * ny2[i] * r1[i];
    coefsD[135 + i] = ((t5 - t6) - mx2[i] * nx1[i] * r2[i] * 2.0) + my2[i] *
      ny1[i] * r2[i] * 2.0;
    coefsD[162 + i] = ((-t7 + t8) + mx2[i] * nx1[i] * ny2[i] * 2.0) - ny2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[189 + i] = ((((-t2 + t3) - t4) - t9) + t10) + t13;
    coefsD[216 + i] = ((t11 - t12) - my2[i] * nx2[i] * ny1[i] * 2.0) + nx2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[243 + i] = ((((-t2 - t3) + t4) + t9) - t10) + t13;
  }
}

//
// Arguments    : const double mx1[27]
//                const double mx2[27]
//                const double my1[27]
//                const double my2[27]
//                const double nx2[27]
//                const double ny2[27]
//                const double r2[27]
//                const double s1[27]
//                const double s2[27]
//                double coefsN[270]
// Return Type  : void
//
static void coefsNumVer2_0(const double mx1[27], const double mx2[27], const
  double my1[27], const double my2[27], const double nx2[27], const double ny2
  [27], const double r2[27], const double s1[27], const double s2[27], double
  coefsN[270])
{
  int i;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;

  // %
  for (i = 0; i < 27; i++) {
    t2 = mx1[i] * my2[i] * r2[i];
    t3 = mx2[i] * ny2[i] * s1[i];
    t4 = my1[i] * nx2[i] * s2[i];
    t5 = mx1[i] * nx2[i] * s2[i] * 2.0;
    t6 = my1[i] * ny2[i] * s2[i] * 2.0;
    t7 = mx1[i] * my2[i] * nx2[i] * 2.0;
    t8 = my2[i] * r2[i] * s1[i] * 2.0;
    t9 = mx2[i] * my1[i] * r2[i];
    t10 = mx1[i] * ny2[i] * s2[i];
    t11 = mx2[i] * my1[i] * ny2[i] * 2.0;
    t12 = mx2[i] * r2[i] * s1[i] * 2.0;
    t13 = my2[i] * nx2[i] * s1[i];
    coefsN[i] = ((((t2 + t3) + t4) - mx2[i] * my1[i] * r2[i]) - mx1[i] * ny2[i] *
                 s2[i]) - my2[i] * nx2[i] * s1[i];
    coefsN[27 + i] = ((t11 + t12) - mx1[i] * my2[i] * ny2[i] * 2.0) - mx1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[54 + i] = ((t7 + t8) - mx2[i] * my1[i] * nx2[i] * 2.0) - my1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[81 + i] = ((t5 + t6) - mx2[i] * nx2[i] * s1[i] * 2.0) - my2[i] *
      ny2[i] * s1[i] * 2.0;
    coefsN[108 + i] = ((((-t2 - t3) + t4) + t9) + t10) - my2[i] * nx2[i] * s1[i];
    coefsN[135 + i] = ((-t5 + t6) + mx2[i] * nx2[i] * s1[i] * 2.0) - my2[i] *
      ny2[i] * s1[i] * 2.0;
    coefsN[162 + i] = ((t7 - t8) - mx2[i] * my1[i] * nx2[i] * 2.0) + my1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[189 + i] = ((((-t2 + t3) - t4) + t9) - t10) + t13;
    coefsN[216 + i] = ((-t11 + t12) + mx1[i] * my2[i] * ny2[i] * 2.0) - mx1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[243 + i] = ((((t2 - t3) - t4) - t9) + t10) + t13;
  }
}

//
// #codegen
// Arguments    : const double m1Orig[21]
//                const double m2Orig[21]
//                const double m1Check[3]
//                const double m2Check[3]
//                double C[735]
// Return Type  : void
//
void CoefsAppendVer1_0(const double m1Orig[21], const double m2Orig[21], const
  double m1Check[3], const double m2Check[3], double C[735])
{
  int i;
  double m1[24];
  int k;
  double m2[24];
  signed char idxBin1[54];
  int counter;
  int j;
  double b_m1[27];
  double c_m1[27];
  double d_m1[27];
  double mx2[27];
  double my2[27];
  double nx2[27];
  double ny2[27];
  double s2[27];
  double r2[27];
  double b_m2[27];
  double c_m2[27];
  double d_m2[27];
  double coefsN[270];
  double coefsD[270];
  signed char idxBin2[42];
  double a1[42];
  double a2[42];
  double a3[42];
  double a4[42];
  double a5[42];
  double a6[42];
  double a7[42];
  double a8[42];
  double a9[42];
  double a10[42];
  double b1[42];
  double b2[42];
  double b3[42];
  double b4[42];
  double b5[42];
  double b6[42];
  double b7[42];
  double b8[42];
  double b9[42];
  double b10[42];
  double coefsND[1470];

  // % Five Point Pose Estimation using Quaternion
  //
  //  Fast way of generating the coefficient matrix C from the image points.
  //
  //
  //  Inputs:
  //         m1: A 3*5 matrix containing the homogeneous coordinates of 5
  //               feature points in the 1st camera view.
  //
  //         m2: A 3*5 matrix containing the homogeneous coordinates of 5
  //               feature points in the 2nd camera view.
  //
  //
  //  Output:
  //         C: The 11*35 coefficient matrix
  //
  //
  //  Copyright (C) 2013-2015, by Kaveh Fathian.
  //
  //
  for (i = 0; i < 3; i++) {
    m1[i] = m1Check[i];
  }

  for (i = 0; i < 7; i++) {
    for (k = 0; k < 3; k++) {
      m1[k + 3 * (i + 1)] = m1Orig[k + 3 * i];
    }
  }

  for (i = 0; i < 3; i++) {
    m2[i] = m2Check[i];
  }

  for (i = 0; i < 7; i++) {
    for (k = 0; k < 3; k++) {
      m2[k + 3 * (i + 1)] = m2Orig[k + 3 * i];
    }
  }

  //  Number of feature points
  //  idxBin1 = [ones(1,numPts-1);
  //             (2 : numPts) ];
  for (i = 0; i < 54; i++) {
    idxBin1[i] = 0;
  }

  counter = -1;
  for (i = 0; i < 6; i++) {
    for (j = 0; j <= 6 - i; j++) {
      counter++;
      idxBin1[counter << 1] = (signed char)(1 + i);
      idxBin1[1 + (counter << 1)] = (signed char)((i + j) + 2);
    }
  }

  //  coefsN = num1
  for (i = 0; i < 27; i++) {
    mx2[i] = m1[3 * (idxBin1[1 + (i << 1)] - 1)];
    my2[i] = m1[1 + 3 * (idxBin1[1 + (i << 1)] - 1)];
    nx2[i] = m2[3 * (idxBin1[1 + (i << 1)] - 1)];
    ny2[i] = m2[1 + 3 * (idxBin1[1 + (i << 1)] - 1)];
    s2[i] = m1[2 + 3 * (idxBin1[1 + (i << 1)] - 1)];
    r2[i] = m2[2 + 3 * (idxBin1[1 + (i << 1)] - 1)];
    b_m1[i] = m1[3 * (idxBin1[i << 1] - 1)];
    c_m1[i] = m1[1 + 3 * (idxBin1[i << 1] - 1)];
    d_m1[i] = m1[2 + 3 * (idxBin1[i << 1] - 1)];
    b_m2[i] = m2[3 * (idxBin1[i << 1] - 1)];
    c_m2[i] = m2[1 + 3 * (idxBin1[i << 1] - 1)];
    d_m2[i] = m2[2 + 3 * (idxBin1[i << 1] - 1)];
  }

  coefsNumVer2_0(b_m1, mx2, c_m1, my2, nx2, ny2, r2, d_m1, s2, coefsN);

  //  coefsD = den1
  coefsDenVer2_0(mx2, my2, b_m2, nx2, c_m2, ny2, d_m2, r2, s2, coefsD);

  // %
  //  Total number of equations
  //  numEq = nchoosek(numPts,3);
  for (i = 0; i < 42; i++) {
    idxBin2[i] = 0;
  }

  counter = -1;

  //  for i = numPts-1 : -1 : 2
  for (j = 0; j < 6; j++) {
    for (k = 0; k <= 5 - j; k++) {
      counter++;
      idxBin2[counter << 1] = (signed char)(1 + j);
      idxBin2[1 + (counter << 1)] = (signed char)((j + k) + 2);
    }
  }

  //      counter2 = i  + counter2;
  //  end
  //  ai = [num1;
  //        den1];
  for (i = 0; i < 21; i++) {
    a1[i] = coefsN[idxBin2[i << 1] - 1];
  }

  for (i = 0; i < 21; i++) {
    a1[i + 21] = coefsD[idxBin2[i << 1] - 1];
    a2[i] = coefsN[idxBin2[i << 1] + 26];
  }

  for (i = 0; i < 21; i++) {
    a2[i + 21] = coefsD[idxBin2[i << 1] + 26];
    a3[i] = coefsN[idxBin2[i << 1] + 53];
  }

  for (i = 0; i < 21; i++) {
    a3[i + 21] = coefsD[idxBin2[i << 1] + 53];
    a4[i] = coefsN[idxBin2[i << 1] + 80];
  }

  for (i = 0; i < 21; i++) {
    a4[i + 21] = coefsD[idxBin2[i << 1] + 80];
    a5[i] = coefsN[idxBin2[i << 1] + 107];
  }

  for (i = 0; i < 21; i++) {
    a5[i + 21] = coefsD[idxBin2[i << 1] + 107];
    a6[i] = coefsN[idxBin2[i << 1] + 134];
  }

  for (i = 0; i < 21; i++) {
    a6[i + 21] = coefsD[idxBin2[i << 1] + 134];
    a7[i] = coefsN[idxBin2[i << 1] + 161];
  }

  for (i = 0; i < 21; i++) {
    a7[i + 21] = coefsD[idxBin2[i << 1] + 161];
    a8[i] = coefsN[idxBin2[i << 1] + 188];
  }

  for (i = 0; i < 21; i++) {
    a8[i + 21] = coefsD[idxBin2[i << 1] + 188];
    a9[i] = coefsN[idxBin2[i << 1] + 215];
  }

  for (i = 0; i < 21; i++) {
    a9[i + 21] = coefsD[idxBin2[i << 1] + 215];
    a10[i] = coefsN[idxBin2[i << 1] + 242];
  }

  for (i = 0; i < 21; i++) {
    a10[i + 21] = coefsD[idxBin2[i << 1] + 242];

    //  bi = [num2;
    //        den2];
    b1[i] = coefsD[idxBin2[1 + (i << 1)] - 1];
  }

  for (i = 0; i < 21; i++) {
    b1[i + 21] = coefsN[idxBin2[1 + (i << 1)] - 1];
    b2[i] = coefsD[idxBin2[1 + (i << 1)] + 26];
  }

  for (i = 0; i < 21; i++) {
    b2[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 26];
    b3[i] = coefsD[idxBin2[1 + (i << 1)] + 53];
  }

  for (i = 0; i < 21; i++) {
    b3[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 53];
    b4[i] = coefsD[idxBin2[1 + (i << 1)] + 80];
  }

  for (i = 0; i < 21; i++) {
    b4[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 80];
    b5[i] = coefsD[idxBin2[1 + (i << 1)] + 107];
  }

  for (i = 0; i < 21; i++) {
    b5[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 107];
    b6[i] = coefsD[idxBin2[1 + (i << 1)] + 134];
  }

  for (i = 0; i < 21; i++) {
    b6[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 134];
    b7[i] = coefsD[idxBin2[1 + (i << 1)] + 161];
  }

  for (i = 0; i < 21; i++) {
    b7[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 161];
    b8[i] = coefsD[idxBin2[1 + (i << 1)] + 188];
  }

  for (i = 0; i < 21; i++) {
    b8[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 188];
    b9[i] = coefsD[idxBin2[1 + (i << 1)] + 215];
  }

  for (i = 0; i < 21; i++) {
    b9[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 215];
    b10[i] = coefsD[idxBin2[1 + (i << 1)] + 242];
  }

  for (i = 0; i < 21; i++) {
    b10[i + 21] = coefsN[idxBin2[1 + (i << 1)] + 242];
  }

  //  coefsND = [num1 * den2;
  //             den1 * num2];
  // %
  for (i = 0; i < 42; i++) {
    coefsND[i] = a1[i] * b1[i];
    coefsND[42 + i] = a1[i] * b2[i] + a2[i] * b1[i];
    coefsND[84 + i] = (a2[i] * b2[i] + a1[i] * b5[i]) + a5[i] * b1[i];
    coefsND[126 + i] = a2[i] * b5[i] + a5[i] * b2[i];
    coefsND[168 + i] = a5[i] * b5[i];
    coefsND[210 + i] = a1[i] * b3[i] + a3[i] * b1[i];
    coefsND[252 + i] = ((a2[i] * b3[i] + a3[i] * b2[i]) + a1[i] * b6[i]) + a6[i]
      * b1[i];
    coefsND[294 + i] = ((a2[i] * b6[i] + a3[i] * b5[i]) + a5[i] * b3[i]) + a6[i]
      * b2[i];
    coefsND[336 + i] = a5[i] * b6[i] + a6[i] * b5[i];
    coefsND[378 + i] = (a3[i] * b3[i] + a1[i] * b8[i]) + a8[i] * b1[i];
    coefsND[420 + i] = ((a3[i] * b6[i] + a6[i] * b3[i]) + a2[i] * b8[i]) + a8[i]
      * b2[i];
    coefsND[462 + i] = (a6[i] * b6[i] + a5[i] * b8[i]) + a8[i] * b5[i];
    coefsND[504 + i] = a3[i] * b8[i] + a8[i] * b3[i];
    coefsND[546 + i] = a6[i] * b8[i] + a8[i] * b6[i];
    coefsND[588 + i] = a8[i] * b8[i];
    coefsND[630 + i] = a1[i] * b4[i] + a4[i] * b1[i];
    coefsND[672 + i] = ((a2[i] * b4[i] + a4[i] * b2[i]) + a1[i] * b7[i]) + a7[i]
      * b1[i];
    coefsND[714 + i] = ((a2[i] * b7[i] + a4[i] * b5[i]) + a5[i] * b4[i]) + a7[i]
      * b2[i];
    coefsND[756 + i] = a5[i] * b7[i] + a7[i] * b5[i];
    coefsND[798 + i] = ((a3[i] * b4[i] + a4[i] * b3[i]) + a1[i] * b9[i]) + a9[i]
      * b1[i];
    coefsND[840 + i] = ((((a3[i] * b7[i] + a4[i] * b6[i]) + a6[i] * b4[i]) +
                         a7[i] * b3[i]) + a2[i] * b9[i]) + a9[i] * b2[i];
    coefsND[882 + i] = ((a6[i] * b7[i] + a7[i] * b6[i]) + a5[i] * b9[i]) + a9[i]
      * b5[i];
    coefsND[924 + i] = ((a3[i] * b9[i] + a4[i] * b8[i]) + a8[i] * b4[i]) + a9[i]
      * b3[i];
    coefsND[966 + i] = ((a6[i] * b9[i] + a7[i] * b8[i]) + a8[i] * b7[i]) + a9[i]
      * b6[i];
    coefsND[1008 + i] = a8[i] * b9[i] + a9[i] * b8[i];
    coefsND[1050 + i] = (a4[i] * b4[i] + a1[i] * b10[i]) + a10[i] * b1[i];
    coefsND[1092 + i] = ((a4[i] * b7[i] + a7[i] * b4[i]) + a2[i] * b10[i]) +
      a10[i] * b2[i];
    coefsND[1134 + i] = (a7[i] * b7[i] + a5[i] * b10[i]) + a10[i] * b5[i];
    coefsND[1176 + i] = ((a3[i] * b10[i] + a4[i] * b9[i]) + a9[i] * b4[i]) +
      a10[i] * b3[i];
    coefsND[1218 + i] = ((a6[i] * b10[i] + a7[i] * b9[i]) + a9[i] * b7[i]) +
      a10[i] * b6[i];
    coefsND[1260 + i] = (a8[i] * b10[i] + a9[i] * b9[i]) + a10[i] * b8[i];
    coefsND[1302 + i] = a4[i] * b10[i] + a10[i] * b4[i];
    coefsND[1344 + i] = a7[i] * b10[i] + a10[i] * b7[i];
    coefsND[1386 + i] = a9[i] * b10[i] + a10[i] * b9[i];
    coefsND[1428 + i] = a10[i] * b10[i];
  }

  // %
  //  coefs = (num1 * den2)  -  (den1 * num2)
  for (i = 0; i < 35; i++) {
    for (k = 0; k < 21; k++) {
      C[k + 21 * i] = coefsND[k + 42 * i] - coefsND[(k + 42 * i) + 21];
    }
  }
}

//
// File trailer for CoefsAppendVer1_0.cpp
//
// [EOF]
//
