//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "bsxfun.h"

// Function Definitions

//
// Arguments    : const double a[4]
//                const double b[16]
//                double c[16]
// Return Type  : void
//
void b_bsxfun(const double a[4], const double b[16], double c[16])
{
  int ak;
  int bk;
  int ck;
  double cv[4];
  int k;
  ak = 0;
  bk = 0;
  for (ck = 0; ck < 14; ck += 4) {
    for (k = 0; k < 4; k++) {
      cv[k] = a[ak] * b[bk + k];
    }

    for (k = 0; k < 4; k++) {
      c[ck + k] = cv[k];
    }

    ak++;
    bk += 4;
  }
}

//
// Arguments    : const double a[60]
//                const double b[6]
//                double c[60]
// Return Type  : void
//
void bsxfun(const double a[60], const double b[6], double c[60])
{
  int ak;
  int ck;
  double cv[6];
  int k;
  ak = 0;
  for (ck = 0; ck < 56; ck += 6) {
    for (k = 0; k < 6; k++) {
      cv[k] = a[ak + k] / b[k];
    }

    for (k = 0; k < 6; k++) {
      c[ck + k] = cv[k];
    }

    ak += 6;
  }
}

//
// File trailer for bsxfun.cpp
//
// [EOF]
//
