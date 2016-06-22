//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
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

// Function Definitions

//
// Arguments    : const double x[16]
//                double y[4]
// Return Type  : void
//
void b_sum(const double x[16], double y[4])
{
  int ix;
  int iy;
  int i;
  int ixstart;
  double s;
  ix = -1;
  iy = -1;
  for (i = 0; i < 4; i++) {
    ixstart = ix + 1;
    ix++;
    s = x[ixstart];
    for (ixstart = 0; ixstart < 3; ixstart++) {
      ix++;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

//
// Arguments    : const double x[4]
// Return Type  : double
//
double c_sum(const double x[4])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 3; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// Arguments    : const double x_data[]
//                const int x_size[1]
// Return Type  : double
//
double d_sum(const double x_data[], const int x_size[1])
{
  double y;
  int k;
  y = x_data[0];
  for (k = 2; k <= x_size[0]; k++) {
    y += x_data[k - 1];
  }

  return y;
}

//
// Arguments    : const double x[5]
// Return Type  : double
//
double e_sum(const double x[5])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 4; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// Arguments    : const boolean_T x[14]
// Return Type  : double
//
double f_sum(const boolean_T x[14])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 13; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

//
// Arguments    : const double x[21]
// Return Type  : double
//
double sum(const double x[21])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 20; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// File trailer for sum.cpp
//
// [EOF]
//
