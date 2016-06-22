//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CoefsVer3_1.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "CoefsVer3_1.h"

// Function Declarations
static void b_coefsDenVer2_0(const double mx2[20], const double my2[20], const
  double nx1[20], const double nx2[20], const double ny1[20], const double ny2
  [20], const double r1[20], const double r2[20], const double s2[20], double
  coefsD[200]);
static void b_coefsNumVer2_0(const double mx1[20], const double mx2[20], const
  double my1[20], const double my2[20], const double nx2[20], const double ny2
  [20], const double r2[20], const double s1[20], const double s2[20], double
  coefsN[200]);

// Function Definitions

//
// Arguments    : const double mx2[20]
//                const double my2[20]
//                const double nx1[20]
//                const double nx2[20]
//                const double ny1[20]
//                const double ny2[20]
//                const double r1[20]
//                const double r2[20]
//                const double s2[20]
//                double coefsD[200]
// Return Type  : void
//
static void b_coefsDenVer2_0(const double mx2[20], const double my2[20], const
  double nx1[20], const double nx2[20], const double ny1[20], const double ny2
  [20], const double r1[20], const double r2[20], const double s2[20], double
  coefsD[200])
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
  for (i = 0; i < 20; i++) {
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
    coefsD[20 + i] = ((t11 + t12) - my2[i] * nx2[i] * ny1[i] * 2.0) - nx2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[40 + i] = ((t7 + t8) - mx2[i] * nx1[i] * ny2[i] * 2.0) - ny2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[60 + i] = ((t5 + t6) - mx2[i] * nx1[i] * r2[i] * 2.0) - my2[i] *
      ny1[i] * r2[i] * 2.0;
    coefsD[80 + i] = ((((t2 - t3) - t4) + t9) + t10) - mx2[i] * ny2[i] * r1[i];
    coefsD[100 + i] = ((t5 - t6) - mx2[i] * nx1[i] * r2[i] * 2.0) + my2[i] *
      ny1[i] * r2[i] * 2.0;
    coefsD[120 + i] = ((-t7 + t8) + mx2[i] * nx1[i] * ny2[i] * 2.0) - ny2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[140 + i] = ((((-t2 + t3) - t4) - t9) + t10) + t13;
    coefsD[160 + i] = ((t11 - t12) - my2[i] * nx2[i] * ny1[i] * 2.0) + nx2[i] *
      r1[i] * s2[i] * 2.0;
    coefsD[180 + i] = ((((-t2 - t3) + t4) + t9) - t10) + t13;
  }
}

//
// Arguments    : const double mx1[20]
//                const double mx2[20]
//                const double my1[20]
//                const double my2[20]
//                const double nx2[20]
//                const double ny2[20]
//                const double r2[20]
//                const double s1[20]
//                const double s2[20]
//                double coefsN[200]
// Return Type  : void
//
static void b_coefsNumVer2_0(const double mx1[20], const double mx2[20], const
  double my1[20], const double my2[20], const double nx2[20], const double ny2
  [20], const double r2[20], const double s1[20], const double s2[20], double
  coefsN[200])
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
  for (i = 0; i < 20; i++) {
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
    coefsN[20 + i] = ((t11 + t12) - mx1[i] * my2[i] * ny2[i] * 2.0) - mx1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[40 + i] = ((t7 + t8) - mx2[i] * my1[i] * nx2[i] * 2.0) - my1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[60 + i] = ((t5 + t6) - mx2[i] * nx2[i] * s1[i] * 2.0) - my2[i] *
      ny2[i] * s1[i] * 2.0;
    coefsN[80 + i] = ((((-t2 - t3) + t4) + t9) + t10) - my2[i] * nx2[i] * s1[i];
    coefsN[100 + i] = ((-t5 + t6) + mx2[i] * nx2[i] * s1[i] * 2.0) - my2[i] *
      ny2[i] * s1[i] * 2.0;
    coefsN[120 + i] = ((t7 - t8) - mx2[i] * my1[i] * nx2[i] * 2.0) + my1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[140 + i] = ((((-t2 + t3) - t4) + t9) - t10) + t13;
    coefsN[160 + i] = ((-t11 + t12) + mx1[i] * my2[i] * ny2[i] * 2.0) - mx1[i] *
      r2[i] * s2[i] * 2.0;
    coefsN[180 + i] = ((((t2 - t3) - t4) - t9) + t10) + t13;
  }
}

//
// #codegen
// Arguments    : const double m1[21]
//                const double m2[21]
//                double C[1260]
// Return Type  : void
//
void CoefsVer3_1(const double m1[21], const double m2[21], double C[1260])
{
  signed char idxBin1[40];
  int i6;
  int counter;
  int i;
  int j;
  double b_m1[20];
  double c_m1[20];
  double d_m1[20];
  double mx2[20];
  double my2[20];
  double nx2[20];
  double ny2[20];
  double s2[20];
  double r2[20];
  double b_m2[20];
  double c_m2[20];
  double d_m2[20];
  double coefsN[200];
  double coefsD[200];
  double idxBin2[70];
  double counter2;
  double b_j;
  int i7;
  int k;
  double a1[70];
  double a2[70];
  double a3[70];
  double a4[70];
  double a5[70];
  double a6[70];
  double a7[70];
  double a8[70];
  double a9[70];
  double a10[70];
  double b1[70];
  double b2[70];
  double b3[70];
  double b4[70];
  double b5[70];
  double b6[70];
  double b7[70];
  double b8[70];
  double b9[70];
  double b10[70];
  double coefsND[2450];
  static const signed char c0[35] = { 1, 0, 2, 0, 1, 0, 0, 0, 0, 2, 0, 2, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 1 };

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
  //  Number of feature points
  for (i6 = 0; i6 < 40; i6++) {
    idxBin1[i6] = 0;
  }

  counter = -1;
  for (i = 0; i < 5; i++) {
    for (j = 0; j <= 5 - i; j++) {
      counter++;
      idxBin1[counter << 1] = (signed char)(1 + i);
      idxBin1[1 + (counter << 1)] = (signed char)((i + j) + 2);
    }
  }

  //  coefsN = num1
  for (i6 = 0; i6 < 20; i6++) {
    mx2[i6] = m1[3 * (idxBin1[1 + (i6 << 1)] - 1)];
    my2[i6] = m1[1 + 3 * (idxBin1[1 + (i6 << 1)] - 1)];
    nx2[i6] = m2[3 * (idxBin1[1 + (i6 << 1)] - 1)];
    ny2[i6] = m2[1 + 3 * (idxBin1[1 + (i6 << 1)] - 1)];
    s2[i6] = m1[2 + 3 * (idxBin1[1 + (i6 << 1)] - 1)];
    r2[i6] = m2[2 + 3 * (idxBin1[1 + (i6 << 1)] - 1)];
    b_m1[i6] = m1[3 * (idxBin1[i6 << 1] - 1)];
    c_m1[i6] = m1[1 + 3 * (idxBin1[i6 << 1] - 1)];
    d_m1[i6] = m1[2 + 3 * (idxBin1[i6 << 1] - 1)];
    b_m2[i6] = m2[3 * (idxBin1[i6 << 1] - 1)];
    c_m2[i6] = m2[1 + 3 * (idxBin1[i6 << 1] - 1)];
    d_m2[i6] = m2[2 + 3 * (idxBin1[i6 << 1] - 1)];
  }

  b_coefsNumVer2_0(b_m1, mx2, c_m1, my2, nx2, ny2, r2, d_m1, s2, coefsN);

  //  coefsD = den1
  b_coefsDenVer2_0(mx2, my2, b_m2, nx2, c_m2, ny2, d_m2, r2, s2, coefsD);

  // %
  //  Total number of equations
  memset(&idxBin2[0], 0, 70U * sizeof(double));
  counter = -1;
  counter2 = 0.0;
  for (i = 0; i < 5; i++) {
    i6 = (int)((((6.0 + -(double)i) - 1.0) + counter2) + (1.0 - (1.0 + counter2)));
    for (j = 0; j < i6; j++) {
      b_j = (1.0 + counter2) + (double)j;
      i7 = (int)(((6.0 + -(double)i) + counter2) + (1.0 - (b_j + 1.0)));
      for (k = 0; k < i7; k++) {
        counter++;
        idxBin2[counter << 1] = b_j;
        idxBin2[1 + (counter << 1)] = (b_j + 1.0) + (double)k;
      }
    }

    counter2 += 6.0 + -(double)i;
  }

  //  ai = [num1;
  //        den1];
  for (i6 = 0; i6 < 35; i6++) {
    a1[i6] = coefsN[(int)idxBin2[i6 << 1] - 1];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a1[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] - 1];
    a2[i6] = coefsN[(int)idxBin2[i6 << 1] + 19];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a2[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 19];
    a3[i6] = coefsN[(int)idxBin2[i6 << 1] + 39];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a3[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 39];
    a4[i6] = coefsN[(int)idxBin2[i6 << 1] + 59];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a4[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 59];
    a5[i6] = coefsN[(int)idxBin2[i6 << 1] + 79];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a5[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 79];
    a6[i6] = coefsN[(int)idxBin2[i6 << 1] + 99];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a6[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 99];
    a7[i6] = coefsN[(int)idxBin2[i6 << 1] + 119];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a7[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 119];
    a8[i6] = coefsN[(int)idxBin2[i6 << 1] + 139];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a8[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 139];
    a9[i6] = coefsN[(int)idxBin2[i6 << 1] + 159];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a9[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 159];
    a10[i6] = coefsN[(int)idxBin2[i6 << 1] + 179];
  }

  for (i6 = 0; i6 < 35; i6++) {
    a10[i6 + 35] = coefsD[(int)idxBin2[i6 << 1] + 179];

    //  bi = [num2;
    //        den2];
    b1[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] - 1];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b1[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] - 1];
    b2[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 19];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b2[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 19];
    b3[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 39];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b3[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 39];
    b4[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 59];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b4[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 59];
    b5[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 79];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b5[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 79];
    b6[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 99];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b6[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 99];
    b7[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 119];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b7[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 119];
    b8[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 139];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b8[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 139];
    b9[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 159];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b9[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 159];
    b10[i6] = coefsD[(int)idxBin2[1 + (i6 << 1)] + 179];
  }

  for (i6 = 0; i6 < 35; i6++) {
    b10[i6 + 35] = coefsN[(int)idxBin2[1 + (i6 << 1)] + 179];
  }

  //  coefsND = [num1 * den2;
  //             den1 * num2];
  // %
  for (i6 = 0; i6 < 70; i6++) {
    coefsND[i6] = a1[i6] * b1[i6];
    coefsND[70 + i6] = a1[i6] * b2[i6] + a2[i6] * b1[i6];
    coefsND[140 + i6] = (a2[i6] * b2[i6] + a1[i6] * b5[i6]) + a5[i6] * b1[i6];
    coefsND[210 + i6] = a2[i6] * b5[i6] + a5[i6] * b2[i6];
    coefsND[280 + i6] = a5[i6] * b5[i6];
    coefsND[350 + i6] = a1[i6] * b3[i6] + a3[i6] * b1[i6];
    coefsND[420 + i6] = ((a2[i6] * b3[i6] + a3[i6] * b2[i6]) + a1[i6] * b6[i6])
      + a6[i6] * b1[i6];
    coefsND[490 + i6] = ((a2[i6] * b6[i6] + a3[i6] * b5[i6]) + a5[i6] * b3[i6])
      + a6[i6] * b2[i6];
    coefsND[560 + i6] = a5[i6] * b6[i6] + a6[i6] * b5[i6];
    coefsND[630 + i6] = (a3[i6] * b3[i6] + a1[i6] * b8[i6]) + a8[i6] * b1[i6];
    coefsND[700 + i6] = ((a3[i6] * b6[i6] + a6[i6] * b3[i6]) + a2[i6] * b8[i6])
      + a8[i6] * b2[i6];
    coefsND[770 + i6] = (a6[i6] * b6[i6] + a5[i6] * b8[i6]) + a8[i6] * b5[i6];
    coefsND[840 + i6] = a3[i6] * b8[i6] + a8[i6] * b3[i6];
    coefsND[910 + i6] = a6[i6] * b8[i6] + a8[i6] * b6[i6];
    coefsND[980 + i6] = a8[i6] * b8[i6];
    coefsND[1050 + i6] = a1[i6] * b4[i6] + a4[i6] * b1[i6];
    coefsND[1120 + i6] = ((a2[i6] * b4[i6] + a4[i6] * b2[i6]) + a1[i6] * b7[i6])
      + a7[i6] * b1[i6];
    coefsND[1190 + i6] = ((a2[i6] * b7[i6] + a4[i6] * b5[i6]) + a5[i6] * b4[i6])
      + a7[i6] * b2[i6];
    coefsND[1260 + i6] = a5[i6] * b7[i6] + a7[i6] * b5[i6];
    coefsND[1330 + i6] = ((a3[i6] * b4[i6] + a4[i6] * b3[i6]) + a1[i6] * b9[i6])
      + a9[i6] * b1[i6];
    coefsND[1400 + i6] = ((((a3[i6] * b7[i6] + a4[i6] * b6[i6]) + a6[i6] * b4[i6])
      + a7[i6] * b3[i6]) + a2[i6] * b9[i6]) + a9[i6] * b2[i6];
    coefsND[1470 + i6] = ((a6[i6] * b7[i6] + a7[i6] * b6[i6]) + a5[i6] * b9[i6])
      + a9[i6] * b5[i6];
    coefsND[1540 + i6] = ((a3[i6] * b9[i6] + a4[i6] * b8[i6]) + a8[i6] * b4[i6])
      + a9[i6] * b3[i6];
    coefsND[1610 + i6] = ((a6[i6] * b9[i6] + a7[i6] * b8[i6]) + a8[i6] * b7[i6])
      + a9[i6] * b6[i6];
    coefsND[1680 + i6] = a8[i6] * b9[i6] + a9[i6] * b8[i6];
    coefsND[1750 + i6] = (a4[i6] * b4[i6] + a1[i6] * b10[i6]) + a10[i6] * b1[i6];
    coefsND[1820 + i6] = ((a4[i6] * b7[i6] + a7[i6] * b4[i6]) + a2[i6] * b10[i6])
      + a10[i6] * b2[i6];
    coefsND[1890 + i6] = (a7[i6] * b7[i6] + a5[i6] * b10[i6]) + a10[i6] * b5[i6];
    coefsND[1960 + i6] = ((a3[i6] * b10[i6] + a4[i6] * b9[i6]) + a9[i6] * b4[i6])
      + a10[i6] * b3[i6];
    coefsND[2030 + i6] = ((a6[i6] * b10[i6] + a7[i6] * b9[i6]) + a9[i6] * b7[i6])
      + a10[i6] * b6[i6];
    coefsND[2100 + i6] = (a8[i6] * b10[i6] + a9[i6] * b9[i6]) + a10[i6] * b8[i6];
    coefsND[2170 + i6] = a4[i6] * b10[i6] + a10[i6] * b4[i6];
    coefsND[2240 + i6] = a7[i6] * b10[i6] + a10[i6] * b7[i6];
    coefsND[2310 + i6] = a9[i6] * b10[i6] + a10[i6] * b9[i6];
    coefsND[2380 + i6] = a10[i6] * b10[i6];
  }

  // %
  //  coefs = (num1 * den2)  -  (den1 * num2)
  //  Coefficients corresponding to unit quaternion norm condition
  for (i6 = 0; i6 < 35; i6++) {
    for (i7 = 0; i7 < 35; i7++) {
      C[i7 + 36 * i6] = coefsND[i7 + 70 * i6] - coefsND[(i7 + 70 * i6) + 35];
    }

    C[35 + 36 * i6] = c0[i6];
  }

  //  Matrix of all coefficients
}

//
// File trailer for CoefsVer3_1.cpp
//
// [EOF]
//
