cmake_minimum_required(VERSION 2.8.12)

project(libFathianSFM)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(FathianSFM SHARED
abs.cpp
bsxfun.cpp
CheckInlierVer1_0.cpp
CheckInlierVer1_0_initialize.cpp
CheckInlierVer1_0_rtwutil.cpp
CheckInlierVer1_0_terminate.cpp
CoefsAppendVer1_0.cpp
CoefsVer3_1.cpp
CoefsVer4_0.cpp
diag.cpp
eig.cpp
eml_sort.cpp
FathianSFMVer3_0.cpp
kron.cpp
mldivide.cpp
mrdivide.cpp
power.cpp
qr.cpp
Quat7PtVer3_4.cpp
QuatResidueVer2_0.cpp
rdivide.cpp
rtGetInf.cpp
rtGetNaN.cpp
rt_nonfinite.cpp
sign.cpp
sqrt.cpp
sum.cpp
svd.cpp
)
