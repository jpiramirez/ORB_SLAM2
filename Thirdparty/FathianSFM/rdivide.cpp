//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rdivide.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "rdivide.h"

// Function Definitions

//
// Arguments    : const double x[14]
//                double y
//                double z[14]
// Return Type  : void
//
void b_rdivide(const double x[14], double y, double z[14])
{
  int i;
  for (i = 0; i < 14; i++) {
    z[i] = x[i] / y;
  }
}

//
// Arguments    : const double x[3]
//                double y
//                double z[3]
// Return Type  : void
//
void rdivide(const double x[3], double y, double z[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    z[i] = x[i] / y;
  }
}

//
// File trailer for rdivide.cpp
//
// [EOF]
//
