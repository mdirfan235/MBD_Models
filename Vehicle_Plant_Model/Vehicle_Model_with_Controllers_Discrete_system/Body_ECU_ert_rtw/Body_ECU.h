/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Body_ECU.h
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

#ifndef Body_ECU_h_
#define Body_ECU_h_
#ifndef Body_ECU_COMMON_INCLUDES_
#define Body_ECU_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* Body_ECU_COMMON_INCLUDES_ */

#include "Body_ECU_types.h"
#include "rt_zcfcn.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S2>/Add' */
} B_Body_ECU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Count;                        /* '<S1>/Data Store Memory' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
} DW_Body_ECU_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem1_Trig_ZCE;/* '<S1>/Triggered Subsystem1' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
} PrevZCX_Body_ECU_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain1;                  /* '<Root>/Gain1' */
} ConstB_Body_ECU_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Steering_position_V;        /* '<Root>/Steering Position' */
  real_T Wheel_RPS_Interrupts;         /* '<Root>/Wheel speed' */
  real_T Brake_posn_V;                 /* '<Root>/Brake position' */
} ExtU_Body_ECU_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T RightIndicatorlight;          /* '<Root>/Right Indicator light' */
  real_T LeftIndicatorlight;           /* '<Root>/Left Indicator light' */
} ExtY_Body_ECU_T;

/* Real-time Model Data Structure */
struct tag_RTM_Body_ECU_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Body_ECU_T Body_ECU_B;

/* Block states (default storage) */
extern DW_Body_ECU_T Body_ECU_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Body_ECU_T Body_ECU_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_Body_ECU_T Body_ECU_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Body_ECU_T Body_ECU_Y;
extern const ConstB_Body_ECU_T Body_ECU_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Body_ECU_initialize(void);
extern void Body_ECU_step(void);
extern void Body_ECU_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Body_ECU_T *const Body_ECU_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<Root>/Display5' : Unused code path elimination
 * Block '<Root>/Display6' : Unused code path elimination
 * Block '<Root>/Display7' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<Root>/rpm' : Unused code path elimination
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 */

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
 * '<Root>' : 'Body_ECU'
 * '<S1>'   : 'Body_ECU/Interrupt to RPS1'
 * '<S2>'   : 'Body_ECU/Interrupt to RPS1/Triggered Subsystem'
 * '<S3>'   : 'Body_ECU/Interrupt to RPS1/Triggered Subsystem1'
 */
#endif                                 /* Body_ECU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
