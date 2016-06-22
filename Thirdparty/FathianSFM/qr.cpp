//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qr.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "qr.h"
#include "mldivide.h"
#include "CheckInlierVer1_0_rtwutil.h"

// Function Declarations
static void b_eml_matlab_zlarf(int m, int n, int iv0, double tau, double C[1225],
  int ic0, double work[35]);
static double b_eml_matlab_zlarfg();
static void eml_matlab_zlarf(int m, int n, int iv0, double tau, double C[1225],
  int ic0, double work[35]);
static double eml_matlab_zlarfg(int n, double *alpha1, double x[1225], int ix0);
static void eml_xgeqrf(double A[1225], double tau[35]);
static double eml_xnrm2(int n, const double x[1225], int ix0);
static void eml_xscal(int n, double a, double x[1225], int ix0);
static void eml_xungqr(double A[1225], const double tau[35]);

// Function Definitions

//
// Arguments    : int m
//                int n
//                int iv0
//                double tau
//                double C[1225]
//                int ic0
//                double work[35]
// Return Type  : void
//
static void b_eml_matlab_zlarf(int m, int n, int iv0, double tau, double C[1225],
  int ic0, double work[35])
{
  int lastv;
  int i;
  int lastc;
  boolean_T exitg2;
  int ia;
  int32_T exitg1;
  int i17;
  int jy;
  int ix;
  double c;
  int j;
  if (tau != 0.0) {
    lastv = m;
    i = iv0 + m;
    while ((lastv > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      i = ic0 + (lastc - 1) * 35;
      ia = i;
      do {
        exitg1 = 0;
        if (ia <= (i + lastv) - 1) {
          if (C[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    if (lastc == 0) {
    } else {
      for (i = 1; i <= lastc; i++) {
        work[i - 1] = 0.0;
      }

      i = 0;
      i17 = ic0 + 35 * (lastc - 1);
      for (jy = ic0; jy <= i17; jy += 35) {
        ix = iv0;
        c = 0.0;
        j = (jy + lastv) - 1;
        for (ia = jy; ia <= j; ia++) {
          c += C[ia - 1] * C[ix - 1];
          ix++;
        }

        work[i] += c;
        i++;
      }
    }

    if (-tau == 0.0) {
    } else {
      i = ic0 - 1;
      jy = 0;
      for (j = 1; j <= lastc; j++) {
        if (work[jy] != 0.0) {
          c = work[jy] * -tau;
          ix = iv0;
          i17 = lastv + i;
          for (ia = i; ia + 1 <= i17; ia++) {
            C[ia] += C[ix - 1] * c;
            ix++;
          }
        }

        jy++;
        i += 35;
      }
    }
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double b_eml_matlab_zlarfg()
{
  return 0.0;
}

//
// Arguments    : int m
//                int n
//                int iv0
//                double tau
//                double C[1225]
//                int ic0
//                double work[35]
// Return Type  : void
//
static void eml_matlab_zlarf(int m, int n, int iv0, double tau, double C[1225],
  int ic0, double work[35])
{
  int lastv;
  int i;
  int lastc;
  boolean_T exitg2;
  int ia;
  int32_T exitg1;
  int i16;
  int jy;
  int ix;
  double c;
  int j;
  if (tau != 0.0) {
    lastv = m;
    i = iv0 + m;
    while ((lastv > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      i = ic0 + (lastc - 1) * 35;
      ia = i;
      do {
        exitg1 = 0;
        if (ia <= (i + lastv) - 1) {
          if (C[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    if (lastc == 0) {
    } else {
      for (i = 1; i <= lastc; i++) {
        work[i - 1] = 0.0;
      }

      i = 0;
      i16 = ic0 + 35 * (lastc - 1);
      for (jy = ic0; jy <= i16; jy += 35) {
        ix = iv0;
        c = 0.0;
        j = (jy + lastv) - 1;
        for (ia = jy; ia <= j; ia++) {
          c += C[ia - 1] * C[ix - 1];
          ix++;
        }

        work[i] += c;
        i++;
      }
    }

    if (-tau == 0.0) {
    } else {
      i = ic0 - 1;
      jy = 0;
      for (j = 1; j <= lastc; j++) {
        if (work[jy] != 0.0) {
          c = work[jy] * -tau;
          ix = iv0;
          i16 = lastv + i;
          for (ia = i; ia + 1 <= i16; ia++) {
            C[ia] += C[ix - 1] * c;
            ix++;
          }
        }

        jy++;
        i += 35;
      }
    }
  }
}

//
// Arguments    : int n
//                double *alpha1
//                double x[1225]
//                int ix0
// Return Type  : double
//
static double eml_matlab_zlarfg(int n, double *alpha1, double x[1225], int ix0)
{
  double tau;
  double xnorm;
  int knt;
  int i14;
  int k;
  tau = 0.0;
  if (n <= 0) {
  } else {
    xnorm = eml_xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          i14 = (ix0 + n) - 2;
          for (k = ix0; k <= i14; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = rt_hypotd_snf(*alpha1, eml_xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        i14 = (ix0 + n) - 2;
        for (k = ix0; k <= i14; k++) {
          x[k - 1] *= *alpha1;
        }

        for (k = 1; k <= knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        i14 = (ix0 + n) - 2;
        for (k = ix0; k <= i14; k++) {
          x[k - 1] *= *alpha1;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

//
// Arguments    : double A[1225]
//                double tau[35]
// Return Type  : void
//
static void eml_xgeqrf(double A[1225], double tau[35])
{
  double work[35];
  int i;
  int i_i;
  double atmp;
  memset(&work[0], 0, 35U * sizeof(double));
  for (i = 0; i < 35; i++) {
    i_i = i + i * 35;
    if (i + 1 < 35) {
      atmp = A[i_i];
      tau[i] = eml_matlab_zlarfg(35 - i, &atmp, A, i_i + 2);
    } else {
      atmp = A[i_i];
      tau[34] = b_eml_matlab_zlarfg();
    }

    A[i_i] = atmp;
    if (i + 1 < 35) {
      atmp = A[i_i];
      A[i_i] = 1.0;
      eml_matlab_zlarf(35 - i, 34 - i, i_i + 1, tau[i], A, (i + (i + 1) * 35) +
                       1, work);
      A[i_i] = atmp;
    }
  }
}

//
// Arguments    : int n
//                const double x[1225]
//                int ix0
// Return Type  : double
//
static double eml_xnrm2(int n, const double x[1225], int ix0)
{
  double y;
  double scale;
  int kend;
  int k;
  double absxk;
  double t;
  y = 0.0;
  if (n < 1) {
  } else if (n == 1) {
    y = fabs(x[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

//
// Arguments    : int n
//                double a
//                double x[1225]
//                int ix0
// Return Type  : void
//
static void eml_xscal(int n, double a, double x[1225], int ix0)
{
  int i15;
  int k;
  i15 = (ix0 + n) - 1;
  for (k = ix0; k <= i15; k++) {
    x[k - 1] *= a;
  }
}

//
// Arguments    : double A[1225]
//                const double tau[35]
// Return Type  : void
//
static void eml_xungqr(double A[1225], const double tau[35])
{
  int itau;
  double work[35];
  int i;
  int iaii;
  int j;
  itau = 34;
  memset(&work[0], 0, 35U * sizeof(double));
  for (i = 34; i > -1; i += -1) {
    iaii = i + i * 35;
    if (i + 1 < 35) {
      A[iaii] = 1.0;
      b_eml_matlab_zlarf(35 - i, 34 - i, iaii + 1, tau[itau], A, iaii + 36, work);
    }

    if (i + 1 < 35) {
      eml_xscal(34 - i, -tau[itau], A, iaii + 2);
    }

    A[iaii] = 1.0 - tau[itau];
    for (j = 1; j <= i; j++) {
      A[iaii - j] = 0.0;
    }

    itau--;
  }
}

//
// Arguments    : const double A[1225]
//                double Q[1225]
//                double R[1225]
// Return Type  : void
//
void qr(const double A[1225], double Q[1225], double R[1225])
{
  double b_A[1225];
  double tau[35];
  int j;
  int i;
  memcpy(&b_A[0], &A[0], 1225U * sizeof(double));
  eml_xgeqrf(b_A, tau);
  for (j = 0; j < 35; j++) {
    for (i = 0; i + 1 <= j + 1; i++) {
      R[i + 35 * j] = b_A[i + 35 * j];
    }

    for (i = j + 1; i + 1 < 36; i++) {
      R[i + 35 * j] = 0.0;
    }
  }

  eml_xungqr(b_A, tau);
  for (j = 0; j < 35; j++) {
    memcpy(&Q[35 * j], &b_A[35 * j], 35U * sizeof(double));
  }
}

//
// File trailer for qr.cpp
//
// [EOF]
//
