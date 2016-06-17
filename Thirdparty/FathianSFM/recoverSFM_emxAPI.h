/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: recoverSFM_emxAPI.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 17-Jun-2016 14:24:41
 */

#ifndef __RECOVERSFM_EMXAPI_H__
#define __RECOVERSFM_EMXAPI_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "recoverSFM_types.h"

/* Function Declarations */
extern emxArray_boolean_T *emxCreateND_boolean_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int rows,
  int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_boolean_T *emxCreate_boolean_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxInitArray_boolean_T(emxArray_boolean_T **pEmxArray, int
  numDimensions);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for recoverSFM_emxAPI.h
 *
 * [EOF]
 */
