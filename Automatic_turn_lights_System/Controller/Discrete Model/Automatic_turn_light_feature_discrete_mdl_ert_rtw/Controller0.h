/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller0.h
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

#ifndef Controller0_h_
#define Controller0_h_
#ifndef Controller0_COMMON_INCLUDES_
#define Controller0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* Controller0_COMMON_INCLUDES_ */

#include "Controller0_types.h"
#include "rt_zcfcn.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S2>/Add' */
} B_Controller0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Count;                        /* '<S1>/Data Store Memory' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
} DW_Controller0_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem1_Trig_ZCE;/* '<S1>/Triggered Subsystem1' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
} PrevZCX_Controller0_T;

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

/* Real-time Model Data Structure */
struct tag_RTM_Controller0_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Controller0_T Controller0_B;

/* Block states (default storage) */
extern DW_Controller0_T Controller0_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Controller0_T Controller0_PrevZCX;

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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<Root>/Left Indicator Light1' : Unused code path elimination
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
 * '<Root>' : 'Controller0'
 * '<S1>'   : 'Controller0/Interrupt to RPS1'
 * '<S2>'   : 'Controller0/Interrupt to RPS1/Triggered Subsystem'
 * '<S3>'   : 'Controller0/Interrupt to RPS1/Triggered Subsystem1'
 */
#endif                                 /* Controller0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
