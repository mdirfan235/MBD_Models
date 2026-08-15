/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Implement_ECU_SIL_data.c
 *
 * Code generated for Simulink model 'Implement_ECU_SIL'.
 *
 * Model version                  : 1.135
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sat Aug  1 18:42:23 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Implement_ECU_SIL.h"

/* Constant parameters (default storage) */
const ConstP_Implement_ECU_SIL_T Implement_ECU_SIL_ConstP = {
  /* Expression: Vehicle.torquegains
   * Referenced by: '<Root>/Speed to Gain map'
   */
  { 1.0, 0.98, 0.95, 0.9, 0.82, 0.74, 0.66, 0.58, 0.5, 0.44, 0.38, 0.34, 0.3,
    0.27, 0.24, 0.22, 0.2, 0.18, 0.16 },

  /* Expression: Vehicle.speedvalues
   * Referenced by: '<Root>/Speed to Gain map'
   */
  { 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 110.0,
    120.0, 130.0, 140.0, 150.0, 160.0, 170.0, 180.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
