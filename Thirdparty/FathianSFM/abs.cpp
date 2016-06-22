//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "abs.h"

// Function Definitions

//
// Arguments    : const double x[21]
//                double y[21]
// Return Type  : void
//
void b_abs(const double x[21], double y[21])
{
  int k;
  for (k = 0; k < 21; k++) {
    y[k] = fabs(x[k]);
  }
}

//
// Arguments    : const double x[16]
//                double y[16]
// Return Type  : void
//
void c_abs(const double x[16], double y[16])
{
  int k;
  for (k = 0; k < 16; k++) {
    y[k] = fabs(x[k]);
  }
}

//
// Arguments    : const double x[4]
//                double y[4]
// Return Type  : void
//
void d_abs(const double x[4], double y[4])
{
  int k;
  for (k = 0; k < 4; k++) {
    y[k] = fabs(x[k]);
  }
}

//
// Arguments    : const double x_data[]
//                const int x_size[1]
//                double y_data[]
//                int y_size[1]
// Return Type  : void
//
void e_abs(const double x_data[], const int x_size[1], double y_data[], int
           y_size[1])
{
  int k;
  y_size[0] = (signed char)x_size[0];
  for (k = 0; k < x_size[0]; k++) {
    y_data[k] = fabs(x_data[k]);
  }
}

//
// Arguments    : const double x[5]
//                double y[5]
// Return Type  : void
//
void f_abs(const double x[5], double y[5])
{
  int k;
  for (k = 0; k < 5; k++) {
    y[k] = fabs(x[k]);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
