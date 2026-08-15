/*
 * Controller0.h
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

#ifndef Controller0_h_
#define Controller0_h_
#ifndef Controller0_COMMON_INCLUDES_
#define Controller0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Controller0_COMMON_INCLUDES_ */

#include "Controller0_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Steering_position_V;        /* '<Root>/Steering Position' */
  real_T Wheelspeed;                   /* '<Root>/Wheel speed' */
  real_T Brake_posn_V;                 /* '<Root>/Brake position' */
} ExtU_Controller0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T RightIndicatorlight;          /* '<Root>/Right Indicator light' */
  real_T LeftIndicatorlight;           /* '<Root>/Left Indicator light' */
} ExtY_Controller0_T;

/* Parameters (default storage) */
struct P_Controller0_T_ {
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 2.5
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 60
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 700
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2.5
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controller0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Controller0_T Controller0_P;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller0_T Controller0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller0_T Controller0_Y;

/* Model entry point functions */
extern void Controller0_initialize(void);
extern void Controller0_step(void);
extern void Controller0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller0_T *const Controller0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller0'
 */
#endif                                 /* Controller0_h_ */
