/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller0.c
 *
 * Code generated for Simulink model 'Controller0'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sun Jul  5 16:35:26 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller0.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_Controller0_T Controller0_B;

/* Block states (default storage) */
DW_Controller0_T Controller0_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Controller0_T Controller0_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Controller0_T Controller0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller0_T Controller0_Y;

/* Real-time model */
static RT_MODEL_Controller0_T Controller0_M_;
RT_MODEL_Controller0_T *const Controller0_M = &Controller0_M_;

/* Model step function */
void Controller0_step(void)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  /* Inport: '<Root>/Wheel speed' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Controller0_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (Controller0_U.Wheelspeed));
  if (zcEvent != NO_ZCEVENT) {
    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<S2>/Data Store Read1'
     */
    Controller0_B.Add = Controller0_DW.Count + 1.0;

    /* DataStoreWrite: '<S2>/Data Store Write' */
    Controller0_DW.Count = Controller0_B.Add;
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
  if ((60.0 * Controller0_B.Add <= 700.0) && (Controller0_U.Brake_posn_V >= 2.5))
  {
    /* Outport: '<Root>/Right Indicator light' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<Root>/Steering Position'
     *  RelationalOperator: '<Root>/Relational Operator3'
     */
    Controller0_Y.RightIndicatorlight = (Controller0_U.Steering_position_V >=
      2.5F);

    /* Outport: '<Root>/Left Indicator light' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<Root>/Steering Position'
     *  RelationalOperator: '<Root>/Relational Operator2'
     */
    Controller0_Y.LeftIndicatorlight = (Controller0_U.Steering_position_V < 2.5F);
  } else {
    /* Outport: '<Root>/Right Indicator light' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Controller0_Y.RightIndicatorlight = 0.0;

    /* Outport: '<Root>/Left Indicator light' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Controller0_Y.LeftIndicatorlight = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem1' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Controller0_PrevZCX.TriggeredSubsystem1_Trig_ZCE,
                     ((real_T)((Controller0_DW.clockTickCounter < 1) &&
    (Controller0_DW.clockTickCounter >= 0))));
  if (zcEvent != NO_ZCEVENT) {
    /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Controller0_DW.Count = 0.0;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem1' */

  /* Update for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  if (Controller0_DW.clockTickCounter >= 9) {
    Controller0_DW.clockTickCounter = 0;
  } else {
    Controller0_DW.clockTickCounter++;
  }

  /* End of Update for DiscretePulseGenerator: '<S1>/Pulse Generator' */
}

/* Model initialize function */
void Controller0_initialize(void)
{
  Controller0_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
  Controller0_PrevZCX.TriggeredSubsystem1_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void Controller0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
