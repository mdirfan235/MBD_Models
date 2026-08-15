/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Body_ECU.c
 *
 * Code generated for Simulink model 'Body_ECU'.
 *
 * Model version                  : 1.137
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Mon Aug 10 00:23:01 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Body_ECU.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Body_ECU_private.h"

/* Block signals (default storage) */
B_Body_ECU_T Body_ECU_B;

/* Block states (default storage) */
DW_Body_ECU_T Body_ECU_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Body_ECU_T Body_ECU_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Body_ECU_T Body_ECU_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Body_ECU_T Body_ECU_Y;

/* Real-time model */
static RT_MODEL_Body_ECU_T Body_ECU_M_;
RT_MODEL_Body_ECU_T *const Body_ECU_M = &Body_ECU_M_;

/* Model step function */
void Body_ECU_step(void)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S2>/Interrupts'
   */
  /* Inport: '<Root>/Wheel speed' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Body_ECU_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (Body_ECU_U.Wheel_RPS_Interrupts));
  if (zcEvent != NO_ZCEVENT) {
    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<S2>/Data Store Read1'
     */
    Body_ECU_B.Add = Body_ECU_DW.Count + 1.0;

    /* DataStoreWrite: '<S2>/Data Store Write' */
    Body_ECU_DW.Count = Body_ECU_B.Add;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Brake position'
   *  Logic: '<Root>/AND'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   *  Switch: '<Root>/Switch'
   */
  if ((60.0 * Body_ECU_B.Add <= 700.0) && (Body_ECU_U.Brake_posn_V > 10.0)) {
    /* Outport: '<Root>/Right Indicator light' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<Root>/Steering Position'
     *  RelationalOperator: '<Root>/Relational Operator3'
     *  Switch: '<Root>/Switch1'
     */
    Body_ECU_Y.RightIndicatorlight = (Body_ECU_U.Steering_position_V > 90.0F);

    /* Outport: '<Root>/Left Indicator light' incorporates:
     *  Inport: '<Root>/Steering Position'
     *  RelationalOperator: '<Root>/Relational Operator2'
     *  Switch: '<Root>/Switch'
     */
    Body_ECU_Y.LeftIndicatorlight = (Body_ECU_U.Steering_position_V <
      Body_ECU_ConstB.Gain1);
  } else {
    /* Outport: '<Root>/Right Indicator light' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Switch: '<Root>/Switch1'
     */
    Body_ECU_Y.RightIndicatorlight = 0.0;

    /* Outport: '<Root>/Left Indicator light' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Switch: '<Root>/Switch'
     */
    Body_ECU_Y.LeftIndicatorlight = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem1' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Body_ECU_PrevZCX.TriggeredSubsystem1_Trig_ZCE,
                     ((real_T)((Body_ECU_DW.clockTickCounter < 1) &&
    (Body_ECU_DW.clockTickCounter >= 0))));
  if (zcEvent != NO_ZCEVENT) {
    /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Body_ECU_DW.Count = 0.0;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem1' */

  /* Update for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  if (Body_ECU_DW.clockTickCounter >= 9) {
    Body_ECU_DW.clockTickCounter = 0;
  } else {
    Body_ECU_DW.clockTickCounter++;
  }

  /* End of Update for DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Body_ECU_M->Timing.t[0] =
    ((time_T)(++Body_ECU_M->Timing.clockTick0)) * Body_ECU_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.11s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.11, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Body_ECU_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Body_ECU_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Body_ECU_M->solverInfo,
                          &Body_ECU_M->Timing.simTimeStep);
    rtsiSetTPtr(&Body_ECU_M->solverInfo, &rtmGetTPtr(Body_ECU_M));
    rtsiSetStepSizePtr(&Body_ECU_M->solverInfo, &Body_ECU_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Body_ECU_M->solverInfo, (&rtmGetErrorStatus
      (Body_ECU_M)));
    rtsiSetRTModelPtr(&Body_ECU_M->solverInfo, Body_ECU_M);
  }

  rtsiSetSimTimeStep(&Body_ECU_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Body_ECU_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Body_ECU_M->solverInfo, false);
  rtsiSetSolverName(&Body_ECU_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Body_ECU_M, &Body_ECU_M->Timing.tArray[0]);
  Body_ECU_M->Timing.stepSize0 = 0.11;
  Body_ECU_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
  Body_ECU_PrevZCX.TriggeredSubsystem1_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void Body_ECU_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
