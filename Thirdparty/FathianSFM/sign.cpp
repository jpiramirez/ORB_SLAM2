//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sign.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "sign.h"

// Function Definitions

//
// Arguments    : double x[4]
// Return Type  : void
//
void b_sign(double x[4])
{
  int k;
  for (k = 0; k < 4; k++) {
    if (x[k] < 0.0) {
      x[k] = -1.0;
    } else if (x[k] > 0.0) {
      x[k] = 1.0;
    } else {
      if (x[k] == 0.0) {
        x[k] = 0.0;
      }
    }
  }
}

//
// File trailer for sign.cpp
//
// [EOF]
//
