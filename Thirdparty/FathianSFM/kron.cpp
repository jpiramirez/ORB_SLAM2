//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: kron.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "kron.h"

// Function Definitions

//
// Arguments    : const double A_data[]
//                const int A_size[1]
//                const double B[10]
//                double K_data[]
//                int K_size[2]
// Return Type  : void
//
void kron(const double A_data[], const int A_size[1], const double B[10], double
          K_data[], int K_size[2])
{
  int kidx;
  int j2;
  int i1;
  K_size[0] = (signed char)A_size[0];
  K_size[1] = 10;
  kidx = -1;
  for (j2 = 0; j2 < 10; j2++) {
    for (i1 = 1; i1 <= A_size[0]; i1++) {
      kidx++;
      K_data[kidx] = A_data[i1 - 1] * B[j2];
    }
  }
}

//
// File trailer for kron.cpp
//
// [EOF]
//
