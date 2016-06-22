//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mrdivide.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "mrdivide.h"

// Function Definitions

//
// Arguments    : double A[16]
//                const double B[16]
// Return Type  : void
//
void mrdivide(double A[16], const double B[16])
{
  double b_A[16];
  signed char ipiv[4];
  int k;
  int j;
  int c;
  int kBcol;
  int ix;
  double temp;
  double s;
  int i;
  int jp;
  int jAcol;
  memcpy(&b_A[0], &B[0], sizeof(double) << 4);
  for (k = 0; k < 4; k++) {
    ipiv[k] = (signed char)(1 + k);
  }

  for (j = 0; j < 3; j++) {
    c = j * 5;
    kBcol = 0;
    ix = c;
    temp = fabs(b_A[c]);
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        kBcol = k - 1;
        temp = s;
      }
    }

    if (b_A[c + kBcol] != 0.0) {
      if (kBcol != 0) {
        ipiv[j] = (signed char)((j + kBcol) + 1);
        ix = j;
        kBcol += j;
        for (k = 0; k < 4; k++) {
          temp = b_A[ix];
          b_A[ix] = b_A[kBcol];
          b_A[kBcol] = temp;
          ix += 4;
          kBcol += 4;
        }
      }

      k = (c - j) + 4;
      for (i = c + 1; i + 1 <= k; i++) {
        b_A[i] /= b_A[c];
      }
    }

    jp = c;
    jAcol = c + 4;
    for (kBcol = 1; kBcol <= 3 - j; kBcol++) {
      temp = b_A[jAcol];
      if (b_A[jAcol] != 0.0) {
        ix = c + 1;
        k = (jp - j) + 8;
        for (i = 5 + jp; i + 1 <= k; i++) {
          b_A[i] += b_A[ix] * -temp;
          ix++;
        }
      }

      jAcol += 4;
      jp += 4;
    }
  }

  for (j = 0; j < 4; j++) {
    jp = j << 2;
    jAcol = j << 2;
    for (k = 1; k <= j; k++) {
      kBcol = (k - 1) << 2;
      if (b_A[(k + jAcol) - 1] != 0.0) {
        for (i = 0; i < 4; i++) {
          A[i + jp] -= b_A[(k + jAcol) - 1] * A[i + kBcol];
        }
      }
    }

    temp = 1.0 / b_A[j + jAcol];
    for (i = 0; i < 4; i++) {
      A[i + jp] *= temp;
    }
  }

  for (j = 3; j > -1; j += -1) {
    jp = j << 2;
    jAcol = (j << 2) - 1;
    for (k = j + 2; k < 5; k++) {
      kBcol = (k - 1) << 2;
      if (b_A[k + jAcol] != 0.0) {
        for (i = 0; i < 4; i++) {
          A[i + jp] -= b_A[k + jAcol] * A[i + kBcol];
        }
      }
    }
  }

  for (kBcol = 2; kBcol > -1; kBcol += -1) {
    if (ipiv[kBcol] != kBcol + 1) {
      jp = ipiv[kBcol] - 1;
      for (jAcol = 0; jAcol < 4; jAcol++) {
        temp = A[jAcol + (kBcol << 2)];
        A[jAcol + (kBcol << 2)] = A[jAcol + (jp << 2)];
        A[jAcol + (jp << 2)] = temp;
      }
    }
  }
}

//
// File trailer for mrdivide.cpp
//
// [EOF]
//
