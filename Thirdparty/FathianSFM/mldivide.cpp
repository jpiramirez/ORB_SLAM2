//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 17-Jun-2016 15:28:53
//

// Include Files
#include "rt_nonfinite.h"
#include "CheckInlierVer1_0.h"
#include "FathianSFMVer3_0.h"
#include "QuatResidueVer2_0.h"
#include "mldivide.h"
#include "CheckInlierVer1_0_rtwutil.h"

// Function Declarations
static double b_eml_xnrm2(int n, const double x[144], int ix0);
static void eml_xgeqp3(double A[144], double tau[4], int jpvt[4]);
static void eml_xswap(double x[144], int ix0, int iy0);

// Function Definitions

//
// Arguments    : int n
//                const double x[144]
//                int ix0
// Return Type  : double
//
static double b_eml_xnrm2(int n, const double x[144], int ix0)
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
// Arguments    : double A[144]
//                double tau[4]
//                int jpvt[4]
// Return Type  : void
//
static void eml_xgeqp3(double A[144], double tau[4], int jpvt[4])
{
  double work[4];
  int i18;
  double vn1[4];
  double vn2[4];
  int k;
  int j;
  double smax;
  double temp2;
  int pvt;
  double absxk;
  double t;
  int i;
  int i_i;
  int ix;
  int i_ip1;
  int lastv;
  int lastc;
  boolean_T exitg2;
  int32_T exitg1;
  int ijA;
  for (i18 = 0; i18 < 4; i18++) {
    jpvt[i18] = 1 + i18;
    work[i18] = 0.0;
  }

  k = 1;
  for (j = 0; j < 4; j++) {
    smax = 0.0;
    temp2 = 2.2250738585072014E-308;
    for (pvt = k; pvt <= k + 35; pvt++) {
      absxk = fabs(A[pvt - 1]);
      if (absxk > temp2) {
        t = temp2 / absxk;
        smax = 1.0 + smax * t * t;
        temp2 = absxk;
      } else {
        t = absxk / temp2;
        smax += t * t;
      }
    }

    smax = temp2 * sqrt(smax);
    vn1[j] = smax;
    vn2[j] = vn1[j];
    k += 36;
  }

  for (i = 0; i < 4; i++) {
    i_i = i + i * 36;
    pvt = 1;
    if (4 - i > 1) {
      ix = i;
      smax = vn1[i];
      for (k = 2; k <= 4 - i; k++) {
        ix++;
        if (vn1[ix] > smax) {
          pvt = k;
          smax = vn1[ix];
        }
      }
    }

    pvt = (i + pvt) - 1;
    if (pvt + 1 != i + 1) {
      eml_xswap(A, 1 + 36 * pvt, 1 + 36 * i);
      k = jpvt[pvt];
      jpvt[pvt] = jpvt[i];
      jpvt[i] = k;
      vn1[pvt] = vn1[i];
      vn2[pvt] = vn2[i];
    }

    absxk = A[i_i];
    temp2 = 0.0;
    smax = b_eml_xnrm2(35 - i, A, i_i + 2);
    if (smax != 0.0) {
      smax = rt_hypotd_snf(A[i_i], smax);
      if (A[i_i] >= 0.0) {
        smax = -smax;
      }

      if (fabs(smax) < 1.0020841800044864E-292) {
        pvt = 0;
        do {
          pvt++;
          i18 = (i_i - i) + 36;
          for (k = i_i + 1; k + 1 <= i18; k++) {
            A[k] *= 9.9792015476736E+291;
          }

          smax *= 9.9792015476736E+291;
          absxk *= 9.9792015476736E+291;
        } while (!(fabs(smax) >= 1.0020841800044864E-292));

        smax = rt_hypotd_snf(absxk, b_eml_xnrm2(35 - i, A, i_i + 2));
        if (absxk >= 0.0) {
          smax = -smax;
        }

        temp2 = (smax - absxk) / smax;
        absxk = 1.0 / (absxk - smax);
        i18 = (i_i - i) + 36;
        for (k = i_i + 1; k + 1 <= i18; k++) {
          A[k] *= absxk;
        }

        for (k = 1; k <= pvt; k++) {
          smax *= 1.0020841800044864E-292;
        }

        absxk = smax;
      } else {
        temp2 = (smax - A[i_i]) / smax;
        absxk = 1.0 / (A[i_i] - smax);
        i18 = (i_i - i) + 36;
        for (k = i_i + 1; k + 1 <= i18; k++) {
          A[k] *= absxk;
        }

        absxk = smax;
      }
    }

    tau[i] = temp2;
    A[i_i] = absxk;
    if (i + 1 < 4) {
      absxk = A[i_i];
      A[i_i] = 1.0;
      i_ip1 = (i + (i + 1) * 36) + 1;
      if (tau[i] != 0.0) {
        lastv = 36 - i;
        pvt = (i_i - i) + 35;
        while ((lastv > 0) && (A[pvt] == 0.0)) {
          lastv--;
          pvt--;
        }

        lastc = 3 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          pvt = i_ip1 + (lastc - 1) * 36;
          j = pvt;
          do {
            exitg1 = 0;
            if (j <= (pvt + lastv) - 1) {
              if (A[j - 1] != 0.0) {
                exitg1 = 1;
              } else {
                j++;
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
          for (pvt = 1; pvt <= lastc; pvt++) {
            work[pvt - 1] = 0.0;
          }

          pvt = 0;
          i18 = i_ip1 + 36 * (lastc - 1);
          for (k = i_ip1; k <= i18; k += 36) {
            ix = i_i;
            smax = 0.0;
            ijA = (k + lastv) - 1;
            for (j = k; j <= ijA; j++) {
              smax += A[j - 1] * A[ix];
              ix++;
            }

            work[pvt] += smax;
            pvt++;
          }
        }

        if (-tau[i] == 0.0) {
        } else {
          pvt = i_ip1 - 1;
          k = 0;
          for (j = 1; j <= lastc; j++) {
            if (work[k] != 0.0) {
              smax = work[k] * -tau[i];
              ix = i_i;
              i18 = lastv + pvt;
              for (ijA = pvt; ijA + 1 <= i18; ijA++) {
                A[ijA] += A[ix] * smax;
                ix++;
              }
            }

            k++;
            pvt += 36;
          }
        }
      }

      A[i_i] = absxk;
    }

    for (j = i + 1; j + 1 < 5; j++) {
      pvt = (i + 36 * j) + 1;
      if (vn1[j] != 0.0) {
        smax = fabs(A[i + 36 * j]) / vn1[j];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        temp2 = vn1[j] / vn2[j];
        temp2 = smax * (temp2 * temp2);
        if (temp2 <= 1.4901161193847656E-8) {
          smax = 0.0;
          temp2 = 2.2250738585072014E-308;
          k = (pvt - i) + 35;
          while (pvt + 1 <= k) {
            absxk = fabs(A[pvt]);
            if (absxk > temp2) {
              t = temp2 / absxk;
              smax = 1.0 + smax * t * t;
              temp2 = absxk;
            } else {
              t = absxk / temp2;
              smax += t * t;
            }

            pvt++;
          }

          smax = temp2 * sqrt(smax);
          vn1[j] = smax;
          vn2[j] = vn1[j];
        } else {
          vn1[j] *= sqrt(smax);
        }
      }
    }
  }
}

//
// Arguments    : double x[144]
//                int ix0
//                int iy0
// Return Type  : void
//
static void eml_xswap(double x[144], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 36; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

//
// Arguments    : const double A[144]
//                const double B_data[]
//                double Y[4]
// Return Type  : void
//
void mldivide(const double A[144], const double B_data[], double Y[4])
{
  double b_A[144];
  int jpvt[4];
  double tau[4];
  int rankR;
  double tol;
  double b_B_data[36];
  int i;
  int j;
  memcpy(&b_A[0], &A[0], 144U * sizeof(double));
  eml_xgeqp3(b_A, tau, jpvt);
  rankR = 0;
  tol = 36.0 * fabs(b_A[0]) * 2.2204460492503131E-16;
  while ((rankR < 4) && (fabs(b_A[rankR + 36 * rankR]) >= tol)) {
    rankR++;
  }

  memcpy(&b_B_data[0], &B_data[0], 36U * sizeof(double));
  for (i = 0; i < 4; i++) {
    Y[i] = 0.0;
  }

  for (j = 0; j < 4; j++) {
    if (tau[j] != 0.0) {
      tol = b_B_data[j];
      for (i = j + 1; i + 1 < 37; i++) {
        tol += b_A[i + 36 * j] * b_B_data[i];
      }

      tol *= tau[j];
      if (tol != 0.0) {
        b_B_data[j] -= tol;
        for (i = j + 1; i + 1 < 37; i++) {
          b_B_data[i] -= b_A[i + 36 * j] * tol;
        }
      }
    }
  }

  for (i = 0; i + 1 <= rankR; i++) {
    Y[jpvt[i] - 1] = b_B_data[i];
  }

  for (j = rankR - 1; j + 1 > 0; j--) {
    Y[jpvt[j] - 1] /= b_A[j + 36 * j];
    for (i = 0; i + 1 <= j; i++) {
      Y[jpvt[i] - 1] -= Y[jpvt[j] - 1] * b_A[i + 36 * j];
    }
  }
}

//
// File trailer for mldivide.cpp
//
// [EOF]
//
