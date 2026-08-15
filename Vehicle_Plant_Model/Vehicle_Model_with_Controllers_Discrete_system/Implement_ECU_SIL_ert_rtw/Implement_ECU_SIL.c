/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Implement_ECU_SIL.c
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
#include "rtwtypes.h"
#include "Implement_ECU_SIL_private.h"

/* Block states (default storage) */
DW_Implement_ECU_SIL_T Implement_ECU_SIL_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Implement_ECU_SIL_T Implement_ECU_SIL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Implement_ECU_SIL_T Implement_ECU_SIL_Y;

/* Real-time model */
static RT_MODEL_Implement_ECU_SIL_T Implement_ECU_SIL_M_;
RT_MODEL_Implement_ECU_SIL_T *const Implement_ECU_SIL_M = &Implement_ECU_SIL_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Model step function */
void Implement_ECU_SIL_step(void)
{
  real_T DiscreteTransferFcn_tmp;
  real_T rtb_DeadZone;
  real_T rtb_FilterCoefficient;
  real_T rtb_rad;
  real_T tmp;
  int8_T tmp_0;
  int8_T tmp_1;

  /* Gain: '<Root>/deg2rad' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Inport: '<Root>/Steering_wheel_angle'
   */
  rtb_rad = 0.017453292519943295 * Implement_ECU_SIL_U.Steering_wheel_angle;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  DiscreteTransferFcn_tmp = (rtb_rad -
    Implement_ECU_SIL_DW.DiscreteTransferFcn_states) / 0.02;

  /* Sum: '<Root>/Sum' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
   *  Gain: '<Root>/Kd'
   *  Gain: '<Root>/Krtc'
   *  Inport: '<Root>/Driver_torque'
   *  Inport: '<Root>/Motor_output_torque'
   *  Inport: '<Root>/Vehicle_speed_kph'
   *  Lookup_n-D: '<Root>/Speed to Gain map'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Add'
   */
  rtb_rad = ((Implement_ECU_SIL_U.Drivertorque * look1_binlxpw
              (Implement_ECU_SIL_U.Vehicle_spd_kmhr,
               Implement_ECU_SIL_ConstP.SpeedtoGainmap_bp01Data,
               Implement_ECU_SIL_ConstP.SpeedtoGainmap_tableData, 18U) - 2.5 *
              rtb_rad) - (0.0 * Implement_ECU_SIL_DW.DiscreteTransferFcn_states
              + DiscreteTransferFcn_tmp) * 0.8) -
    Implement_ECU_SIL_U.Assist_driver_torque;

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S33>/Filter'
   *  Gain: '<S31>/Derivative Gain'
   *  Sum: '<S33>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_rad - Implement_ECU_SIL_DW.Filter_DSTATE) *
    100.0;

  /* Sum: '<S47>/Sum' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  rtb_DeadZone = (rtb_rad + Implement_ECU_SIL_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S45>/Saturation' incorporates:
   *  DeadZone: '<S30>/DeadZone'
   */
  if (rtb_DeadZone > 1.0) {
    tmp = 1.0;
    rtb_DeadZone--;
  } else {
    if (rtb_DeadZone < 0.0) {
      tmp = 0.0;
    } else {
      tmp = rtb_DeadZone;
    }

    if (rtb_DeadZone >= 0.0) {
      rtb_DeadZone = 0.0;
    }
  }

  /* Outport: '<Root>/EPS_Motor_Control' incorporates:
   *  Gain: '<Root>/Gain'
   *  Saturate: '<S45>/Saturation'
   */
  Implement_ECU_SIL_Y.EPS_Motor_Control = 12.0 * tmp;

  /* Gain: '<S35>/Integral Gain' */
  rtb_rad *= 5.0;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  Implement_ECU_SIL_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

  /* Update for DiscreteIntegrator: '<S33>/Filter' */
  Implement_ECU_SIL_DW.Filter_DSTATE += 0.001 * rtb_FilterCoefficient;

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Clamping_zero'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant2'
   *  RelationalOperator: '<S28>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S28>/Clamping_zero'
   *  Constant: '<S28>/Constant3'
   *  Constant: '<S28>/Constant4'
   *  RelationalOperator: '<S28>/fix for DT propagation issue1'
   */
  if (rtb_rad > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Clamping_zero'
   *  Constant: '<S28>/Constant1'
   *  Logic: '<S28>/AND3'
   *  RelationalOperator: '<S28>/Equal1'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  Switch: '<S28>/Switch1'
   *  Switch: '<S28>/Switch2'
   */
  if ((rtb_DeadZone != 0.0) && (tmp_0 == tmp_1)) {
    rtb_rad = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Switch: '<S28>/Switch'
   */
  Implement_ECU_SIL_DW.Integrator_DSTATE += 0.001 * rtb_rad;
}

/* Model initialize function */
void Implement_ECU_SIL_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Implement_ECU_SIL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
