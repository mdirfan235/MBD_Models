/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Powertrain_ECU_SIL.h
 *
 * Code generated for Simulink model 'Powertrain_ECU_SIL'.
 *
 * Model version                  : 1.136
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sat Aug  1 19:07:27 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Powertrain_ECU_SIL_h_
#define Powertrain_ECU_SIL_h_
#ifndef Powertrain_ECU_SIL_COMMON_INCLUDES_
#define Powertrain_ECU_SIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Powertrain_ECU_SIL_COMMON_INCLUDES_ */

#include "Powertrain_ECU_SIL_types.h"
#include <string.h>
#include "rtGetInf.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T FilterCoefficient;            /* '<S41>/Filter Coefficient' */
  real_T SumI4;                        /* '<S30>/SumI4' */
  real_T RateLimiter;                  /* '<S2>/Rate Limiter' */
  real_T Set_spd;                      /* '<Root>/Chart' */
  real_T Cruise_enable;                /* '<Root>/Chart' */
  boolean_T NOT;                       /* '<S2>/NOT' */
} B_Powertrain_ECU_SIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T PrevY;                        /* '<S2>/Rate Limiter' */
  real_T LastMajorTime;                /* '<S2>/Rate Limiter' */
  uint8_T is_active_c1_Powertrain_ECU_SIL;/* '<Root>/Chart' */
  uint8_T is_c1_Powertrain_ECU_SIL;    /* '<Root>/Chart' */
  boolean_T PrevLimited;               /* '<S2>/Rate Limiter' */
  boolean_T EnabledSubsystem_MODE;     /* '<Root>/Enabled Subsystem' */
} DW_Powertrain_ECU_SIL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S33>/Filter' */
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
} X_Powertrain_ECU_SIL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S33>/Filter' */
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
} XDot_Powertrain_ECU_SIL_T;

/* State disabled  */
typedef struct {
  boolean_T Filter_CSTATE;             /* '<S33>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S38>/Integrator' */
} XDis_Powertrain_ECU_SIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Filter_Reset_ZCE;         /* '<S33>/Filter' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S38>/Integrator' */
} PrevZCX_Powertrain_ECU_SIL_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Vehicle_spd_kmhr;             /* '<Root>/Vehicle speed km//hr' */
  real_T Driver_Brake_Pedal;           /* '<Root>/Brakepedal_pct' */
  real_T CruiseONOFFswitch;            /* '<Root>/Cruise_Master_SW' */
  real_T Cruisesetting;                /* '<Root>/Cruise_setting' */
  real_T Driver_Accelerator_Pedal;     /* '<Root>/Driver_Accelerator_pedal' */
} ExtU_Powertrain_ECU_SIL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Accelerator_command;          /* '<Root>/Accelerator_command' */
} ExtY_Powertrain_ECU_SIL_T;

/* Real-time Model Data Structure */
struct tag_RTM_Powertrain_ECU_SIL_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Powertrain_ECU_SIL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Powertrain_ECU_SIL_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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

    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_B;

/* Continuous states (default storage) */
extern X_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_X;

/* Disabled states (default storage) */
extern XDis_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_XDis;

/* Block states (default storage) */
extern DW_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_Y;

/* Model entry point functions */
extern void Powertrain_ECU_SIL_initialize(void);
extern void Powertrain_ECU_SIL_step(void);
extern void Powertrain_ECU_SIL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Powertrain_ECU_SIL_T *const Powertrain_ECU_SIL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<S30>/Kb' : Eliminated nontunable gain of 1
 * Block '<S43>/Proportional Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'Powertrain_ECU_SIL'
 * '<S1>'   : 'Powertrain_ECU_SIL/Chart'
 * '<S2>'   : 'Powertrain_ECU_SIL/Enabled Subsystem'
 * '<S3>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller'
 * '<S4>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Anti-windup'
 * '<S5>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/D Gain'
 * '<S6>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/External Derivative'
 * '<S7>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Filter'
 * '<S8>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Filter ICs'
 * '<S9>'   : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/I Gain'
 * '<S10>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Ideal P Gain'
 * '<S11>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Integrator'
 * '<S13>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Integrator ICs'
 * '<S14>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/N Copy'
 * '<S15>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/N Gain'
 * '<S16>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/P Copy'
 * '<S17>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Parallel P Gain'
 * '<S18>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Reset Signal'
 * '<S19>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Saturation'
 * '<S20>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Sum'
 * '<S22>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Sum Fdbk'
 * '<S23>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tracking Mode'
 * '<S24>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/postSat Signal'
 * '<S28>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/preInt Signal'
 * '<S29>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/preSat Signal'
 * '<S30>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Anti-windup/Back Calculation'
 * '<S31>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/External Derivative/Error'
 * '<S33>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Filter/Cont. Filter'
 * '<S34>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S36>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Integrator/Continuous'
 * '<S39>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/N Copy/Disabled'
 * '<S41>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/N Gain/Internal Parameters'
 * '<S42>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Reset Signal/External Reset'
 * '<S45>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Saturation/Enabled'
 * '<S46>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Sum/Sum_PID'
 * '<S48>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S52>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/preInt Signal/Internal PreInt'
 * '<S55>'  : 'Powertrain_ECU_SIL/Enabled Subsystem/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* Powertrain_ECU_SIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
