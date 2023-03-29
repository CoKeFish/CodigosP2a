/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.13 and Signal Processing Toolbox 9.1.
 * Generated on: 28-Mar-2023 16:49:17
 */

/*
 * Discrete-Time IIR Filter (real)
 * -------------------------------
 * Filter Structure    : Direct-Form II, Second-Order Sections
 * Number of Sections  : 2
 * Stable              : Yes
 * Linear Phase        : No
 */

/* General type conversion for MATLAB generated C-code  */
//#include "tmwtypes.h"
/*
 * Expected path to tmwtypes.h
 * C:\Program Files\MATLAB\R2022b\extern\include\tmwtypes.h
 */
#define MWSPT_NSEC 5
const int NL[MWSPT_NSEC] = { 1,3,1,3,1 };
const double NUM[MWSPT_NSEC][3] = {
        {
                0.8390619836657,                 0,                 0
        },
        {
                1,                -2,                 1
        },
        {
                0.710677371828,                 0,                 0
        },
        {
                1,                -2,                 1
        },
        {
                1,                 0,                 0
        }
};
const int DL[MWSPT_NSEC] = { 1,3,1,3,1 };
const double DEN[MWSPT_NSEC][3] = {
        {
                1,                 0,                 0
        },
        {
                1,   -1.611727096457,   0.7445208382054
        },
        {
                1,                 0,                 0
        },
        {
                1,   -1.365117237239,   0.4775922500725
        },
        {
                1,                 0,                 0
        }
};