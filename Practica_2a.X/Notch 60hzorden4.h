/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.13 and Signal Processing Toolbox 9.1.
 * Generated on: 24-Mar-2023 10:52:11
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
     0.6891427607528,                 0,                 0 
  },
  {
                   1,    1.419133025919,                 1 
  },
  {
     0.6891427607528,                 0,                 0 
  },
  {
                   1,    1.419133025919,                 1 
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
                   1,    1.500213001995,   0.6615935420864 
  },
  {
                   1,                 0,                 0 
  },
  {
                   1,    0.381513719092,   0.3744482215401 
  },
  {
                   1,                 0,                 0 
  }
};