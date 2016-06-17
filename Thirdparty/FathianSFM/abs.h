/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 17-Jun-2016 14:24:41
 */

#ifndef __ABS_H__
#define __ABS_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "recoverSFM_types.h"

/* Function Declarations */
extern void b_abs(const double x[16], double y[16]);
extern void c_abs(const double x[4], double y[4]);
extern void d_abs(const double x_data[], const int x_size[1], double y_data[],
                  int y_size[1]);
extern void e_abs(const double x[5], double y[5]);
extern void f_abs(const double x[35], double y[35]);
extern void g_abs(const double x[21], double y[21]);

#endif

/*
 * File trailer for abs.h
 *
 * [EOF]
 */
