//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: diag.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "diag.h"

// Function Definitions

//
// Arguments    : const double v[60]
//                double d[6]
// Return Type  : void
//
void diag(const double v[60], double d[6])
{
  int j;
  for (j = 0; j < 6; j++) {
    d[j] = v[j * 7];
  }
}

//
// File trailer for diag.cpp
//
// [EOF]
//
