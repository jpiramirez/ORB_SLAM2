/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: recoverSFM.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 17-Jun-2016 14:24:41
 */

#ifndef __RECOVERSFM_H__
#define __RECOVERSFM_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "recoverSFM_types.h"

/* Function Declarations */
extern void recoverSFM(const double K[9], const emxArray_real_T *p1, const
  emxArray_real_T *p2, int maxIter, double tFactor, double Q_data[], int Q_size
  [2], double T_data[], int T_size[2], emxArray_boolean_T *inliers);

#endif

/*
 * File trailer for recoverSFM.h
 *
 * [EOF]
 */
