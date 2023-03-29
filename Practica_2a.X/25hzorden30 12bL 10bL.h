/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.13 and DSP System Toolbox 9.15.
 * Generated on: 23-Mar-2023 17:33:31
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 31
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 * Arithmetic        : fixed
 * Numerator         : s12,12 -> [-5.000000e-01 5.000000e-01)
 * Input             : s10,10 -> [-5.000000e-01 5.000000e-01)
 * Filter Internals  : Full Precision
 *   Output          : s23,22 -> [-1 1)  (auto determined)
 *   Product         : s21,22 -> [-2.500000e-01 2.500000e-01)  (auto determined)
 *   Accumulator     : s23,22 -> [-1 1)  (auto determined)
 *   Round Mode      : No rounding
 *   Overflow Mode   : No overflow
 */

/* General type conversion for MATLAB generated C-code  */
//#include "tmwtypes.h"
#include <stdint.h>

/*
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2022b\extern\include\tmwtypes.h 
 */
#define BL = 31;
const int16_t B[31] = {
      720,   -528,  -1552,  -1552,   -336,   1376,   2384,   1728,   -528,
    -3104,  -4048,  -1840,   3584,  10592,  16480,  18768,  16480,  10592,
     3584,  -1840,  -4048,  -3104,   -528,   1728,   2384,   1376,   -336,
    -1552,  -1552,   -528,    720
};