/*
 * Controller0.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controller0".
 *
 * Model version              : 1.15
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Sun Jul  5 16:07:39 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller0.h"
#include "rtwtypes.h"
#include <string.h>
#include "Controller0_private.h"

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
  real_T rtb_Switch2;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Brake position'
   *  Inport: '<Root>/Wheel speed'
   *  Logic: '<Root>/AND'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if ((Controller0_P.Gain_Gain * Controller0_U.Wheelspeed <=
       Controller0_P.Constant_Value) && (Controller0_U.Brake_posn_V >=
       Controller0_P.Constant1_Value)) {
    rtb_Switch2 = Controller0_P.Constant4_Value;
  } else {
    rtb_Switch2 = Controller0_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Switch: '<Root>/Switch1' */
  if (rtb_Switch2 > Controller0_P.Switch1_Threshold) {
    /* Outport: '<Root>/Right Indicator light' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<Root>/Steering Position'
     *  RelationalOperator: '<Root>/Relational Operator3'
     */
    Controller0_Y.RightIndicatorlight = (Controller0_U.Steering_position_V >=
      Controller0_P.Constant2_Value);
  } else {
    /* Outport: '<Root>/Right Indicator light' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Controller0_Y.RightIndicatorlight = Controller0_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch' */
  if (rtb_Switch2 > Controller0_P.Switch_Threshold) {
    /* Outport: '<Root>/Left Indicator light' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<Root>/Steering Position'
     *  RelationalOperator: '<Root>/Relational Operator2'
     */
    Controller0_Y.LeftIndicatorlight = (Controller0_U.Steering_position_V <
      Controller0_P.Constant2_Value);
  } else {
    /* Outport: '<Root>/Left Indicator light' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Controller0_Y.LeftIndicatorlight = Controller0_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Controller0_M->rtwLogInfo,
                      (&Controller0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [2.0s, 0.0s] */
    if ((rtmGetTFinal(Controller0_M)!=-1) &&
        !((rtmGetTFinal(Controller0_M)-Controller0_M->Timing.taskTime0) >
          Controller0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controller0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controller0_M->Timing.clockTick0)) {
    ++Controller0_M->Timing.clockTickH0;
  }

  Controller0_M->Timing.taskTime0 = Controller0_M->Timing.clockTick0 *
    Controller0_M->Timing.stepSize0 + Controller0_M->Timing.clockTickH0 *
    Controller0_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Controller0_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Controller0_M, 0,
                sizeof(RT_MODEL_Controller0_T));
  rtmSetTFinal(Controller0_M, 100.0);
  Controller0_M->Timing.stepSize0 = 2.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Controller0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controller0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controller0_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controller0_M->rtwLogInfo, "");
    rtliSetLogX(Controller0_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controller0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controller0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controller0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Controller0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Controller0_M->rtwLogInfo, 1);
    rtliSetLogY(Controller0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Controller0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Controller0_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&Controller0_U, 0, sizeof(ExtU_Controller0_T));

  /* external outputs */
  (void)memset(&Controller0_Y, 0, sizeof(ExtY_Controller0_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Controller0_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Controller0_M), Controller0_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Controller0_M)));
}

/* Model terminate function */
void Controller0_terminate(void)
{
  /* (no terminate code required) */
}
