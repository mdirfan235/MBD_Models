/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Implement_ECU_SIL.h
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

#ifndef Implement_ECU_SIL_h_
#define Implement_ECU_SIL_h_
#ifndef Implement_ECU_SIL_COMMON_INCLUDES_
#define Implement_ECU_SIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* Implement_ECU_SIL_COMMON_INCLUDES_ */

#include "Implement_ECU_SIL_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<Root>/Discrete Transfer Fcn' */
  real_T Filter_DSTATE;                /* '<S33>/Filter' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
} DW_Implement_ECU_SIL_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Vehicle.torquegains
   * Referenced by: '<Root>/Speed to Gain map'
   */
  real_T SpeedtoGainmap_tableData[19];

  /* Expression: Vehicle.speedvalues
   * Referenced by: '<Root>/Speed to Gain map'
   */
  real_T SpeedtoGainmap_bp01Data[19];
} ConstP_Implement_ECU_SIL_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Drivertorque;                 /* '<Root>/Driver_torque' */
  real_T Vehicle_spd_kmhr;             /* '<Root>/Vehicle_speed_kph' */
  real32_T Steering_wheel_angle;       /* '<Root>/Steering_wheel_angle' */
  real_T Assist_driver_torque;         /* '<Root>/Motor_output_torque' */
} ExtU_Implement_ECU_SIL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T EPS_Motor_Control;            /* '<Root>/EPS_Motor_Control' */
} ExtY_Implement_ECU_SIL_T;

/* Real-time Model Data Structure */
struct tag_RTM_Implement_ECU_SIL_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Implement_ECU_SIL_T Implement_ECU_SIL_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Implement_ECU_SIL_T Implement_ECU_SIL_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Implement_ECU_SIL_T Implement_ECU_SIL_Y;

/* Constant parameters (default storage) */
extern const ConstP_Implement_ECU_SIL_T Implement_ECU_SIL_ConstP;

/* Model entry point functions */
extern void Implement_ECU_SIL_initialize(void);
extern void Implement_ECU_SIL_step(void);
extern void Implement_ECU_SIL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Implement_ECU_SIL_T *const Implement_ECU_SIL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<S43>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition4' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'Implement_ECU_SIL'
 * '<S1>'   : 'Implement_ECU_SIL/PID Controller1'
 * '<S2>'   : 'Implement_ECU_SIL/PID Controller1/Anti-windup'
 * '<S3>'   : 'Implement_ECU_SIL/PID Controller1/D Gain'
 * '<S4>'   : 'Implement_ECU_SIL/PID Controller1/External Derivative'
 * '<S5>'   : 'Implement_ECU_SIL/PID Controller1/Filter'
 * '<S6>'   : 'Implement_ECU_SIL/PID Controller1/Filter ICs'
 * '<S7>'   : 'Implement_ECU_SIL/PID Controller1/I Gain'
 * '<S8>'   : 'Implement_ECU_SIL/PID Controller1/Ideal P Gain'
 * '<S9>'   : 'Implement_ECU_SIL/PID Controller1/Ideal P Gain Fdbk'
 * '<S10>'  : 'Implement_ECU_SIL/PID Controller1/Integrator'
 * '<S11>'  : 'Implement_ECU_SIL/PID Controller1/Integrator ICs'
 * '<S12>'  : 'Implement_ECU_SIL/PID Controller1/N Copy'
 * '<S13>'  : 'Implement_ECU_SIL/PID Controller1/N Gain'
 * '<S14>'  : 'Implement_ECU_SIL/PID Controller1/P Copy'
 * '<S15>'  : 'Implement_ECU_SIL/PID Controller1/Parallel P Gain'
 * '<S16>'  : 'Implement_ECU_SIL/PID Controller1/Reset Signal'
 * '<S17>'  : 'Implement_ECU_SIL/PID Controller1/Saturation'
 * '<S18>'  : 'Implement_ECU_SIL/PID Controller1/Saturation Fdbk'
 * '<S19>'  : 'Implement_ECU_SIL/PID Controller1/Sum'
 * '<S20>'  : 'Implement_ECU_SIL/PID Controller1/Sum Fdbk'
 * '<S21>'  : 'Implement_ECU_SIL/PID Controller1/Tracking Mode'
 * '<S22>'  : 'Implement_ECU_SIL/PID Controller1/Tracking Mode Sum'
 * '<S23>'  : 'Implement_ECU_SIL/PID Controller1/Tsamp - Integral'
 * '<S24>'  : 'Implement_ECU_SIL/PID Controller1/Tsamp - Ngain'
 * '<S25>'  : 'Implement_ECU_SIL/PID Controller1/postSat Signal'
 * '<S26>'  : 'Implement_ECU_SIL/PID Controller1/preInt Signal'
 * '<S27>'  : 'Implement_ECU_SIL/PID Controller1/preSat Signal'
 * '<S28>'  : 'Implement_ECU_SIL/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S29>'  : 'Implement_ECU_SIL/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S30>'  : 'Implement_ECU_SIL/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S31>'  : 'Implement_ECU_SIL/PID Controller1/D Gain/Internal Parameters'
 * '<S32>'  : 'Implement_ECU_SIL/PID Controller1/External Derivative/Error'
 * '<S33>'  : 'Implement_ECU_SIL/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'Implement_ECU_SIL/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'Implement_ECU_SIL/PID Controller1/I Gain/Internal Parameters'
 * '<S36>'  : 'Implement_ECU_SIL/PID Controller1/Ideal P Gain/Passthrough'
 * '<S37>'  : 'Implement_ECU_SIL/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'Implement_ECU_SIL/PID Controller1/Integrator/Discrete'
 * '<S39>'  : 'Implement_ECU_SIL/PID Controller1/Integrator ICs/Internal IC'
 * '<S40>'  : 'Implement_ECU_SIL/PID Controller1/N Copy/Disabled'
 * '<S41>'  : 'Implement_ECU_SIL/PID Controller1/N Gain/Internal Parameters'
 * '<S42>'  : 'Implement_ECU_SIL/PID Controller1/P Copy/Disabled'
 * '<S43>'  : 'Implement_ECU_SIL/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'Implement_ECU_SIL/PID Controller1/Reset Signal/Disabled'
 * '<S45>'  : 'Implement_ECU_SIL/PID Controller1/Saturation/Enabled'
 * '<S46>'  : 'Implement_ECU_SIL/PID Controller1/Saturation Fdbk/Disabled'
 * '<S47>'  : 'Implement_ECU_SIL/PID Controller1/Sum/Sum_PID'
 * '<S48>'  : 'Implement_ECU_SIL/PID Controller1/Sum Fdbk/Disabled'
 * '<S49>'  : 'Implement_ECU_SIL/PID Controller1/Tracking Mode/Disabled'
 * '<S50>'  : 'Implement_ECU_SIL/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'Implement_ECU_SIL/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S52>'  : 'Implement_ECU_SIL/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'Implement_ECU_SIL/PID Controller1/postSat Signal/Forward_Path'
 * '<S54>'  : 'Implement_ECU_SIL/PID Controller1/preInt Signal/Internal PreInt'
 * '<S55>'  : 'Implement_ECU_SIL/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* Implement_ECU_SIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
