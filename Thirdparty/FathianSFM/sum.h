/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 17-Jun-2016 14:24:41
 */

#ifndef __SUM_H__
#define __SUM_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "recoverSFM_types.h"

/* Function Declarations */
extern double b_sum(const double x[4]);
extern double c_sum(const double x_data[], const int x_size[1]);
extern double d_sum(const double x[5]);
extern double e_sum(const boolean_T x[14]);
extern double f_sum(const double x[35]);
extern double g_sum(const double x[21]);
extern void sum(const double x[16], double y[4]);

#endif

/*
 * File trailer for sum.h
 *
 * [EOF]
 */
