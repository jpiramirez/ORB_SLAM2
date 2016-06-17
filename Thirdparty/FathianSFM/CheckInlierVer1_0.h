//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CheckInlierVer1_0.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 10-Jun-2016 15:59:19
//
#ifndef __CHECKINLIERVER1_0_H__
#define __CHECKINLIERVER1_0_H__

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "CheckInlierVer1_0_types.h"

// Function Declarations
extern void CheckInlierVer1_0(const double qSolBest[4], const double m1Orig[21],
  const double m2Orig[21], const double m1Check[3], const double m2Check[3],
  double *residu, double *residues);

#endif

//
// File trailer for CheckInlierVer1_0.h
//
// [EOF]
//
