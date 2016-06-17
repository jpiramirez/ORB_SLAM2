/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mldivide.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 17-Jun-2016 14:24:41
 */

#ifndef __MLDIVIDE_H__
#define __MLDIVIDE_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "recoverSFM_types.h"

/* Function Declarations */
extern void b_mldivide(const double A[144], const double B_data[], double Y[4]);
extern void c_mldivide(const double A[9], const double B[3], double Y[3]);
extern void mldivide(const double A[9], const double B[21], double Y[21]);

#endif

/*
 * File trailer for mldivide.h
 *
 * [EOF]
 */
