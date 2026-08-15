/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Powertrain_ECU_SIL.c
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

#include "Powertrain_ECU_SIL.h"
#include "rtwtypes.h"
#include "Powertrain_ECU_SIL_private.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Powertrain_ECU_SIL_IN_ACTIVE   ((uint8_T)1U)
#define Powertrain_ECU_SIL_IN_OFF      ((uint8_T)2U)
#define Powertrain_ECU_SIL_IN_READY    ((uint8_T)3U)
#define Powertrain_ECU_SIL_IN_STANDBY  ((uint8_T)4U)

/* Block signals (default storage) */
B_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_B;

/* Continuous states */
X_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_X;

/* Disabled State Vector */
XDis_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_XDis;

/* Block states (default storage) */
DW_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_Y;

/* Real-time model */
static RT_MODEL_Powertrain_ECU_SIL_T Powertrain_ECU_SIL_M_;
RT_MODEL_Powertrain_ECU_SIL_T *const Powertrain_ECU_SIL_M =
  &Powertrain_ECU_SIL_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Powertrain_ECU_SIL_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Powertrain_ECU_SIL_step();
  Powertrain_ECU_SIL_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Powertrain_ECU_SIL_step();
  Powertrain_ECU_SIL_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Powertrain_ECU_SIL_step(void)
{
  real_T riseValLimit;
  real_T rtb_Sum;
  real_T rtb_Switch;
  boolean_T didZcEventOccur;
  if (rtmIsMajorTimeStep(Powertrain_ECU_SIL_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Powertrain_ECU_SIL_M->solverInfo,
                          ((Powertrain_ECU_SIL_M->Timing.clockTick0+1)*
      Powertrain_ECU_SIL_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Powertrain_ECU_SIL_M)) {
    Powertrain_ECU_SIL_M->Timing.t[0] = rtsiGetT
      (&Powertrain_ECU_SIL_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Powertrain_ECU_SIL_M) &&
      Powertrain_ECU_SIL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Chart: '<Root>/Chart' incorporates:
     *  Inport: '<Root>/Brakepedal_pct'
     *  Inport: '<Root>/Cruise_Master_SW'
     *  Inport: '<Root>/Cruise_setting'
     *  Inport: '<Root>/Vehicle speed km//hr'
     */
    if (Powertrain_ECU_SIL_DW.is_active_c1_Powertrain_ECU_SIL == 0) {
      Powertrain_ECU_SIL_DW.is_active_c1_Powertrain_ECU_SIL = 1U;
      Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL = Powertrain_ECU_SIL_IN_OFF;
    } else {
      switch (Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL) {
       case Powertrain_ECU_SIL_IN_ACTIVE:
        if (((Powertrain_ECU_SIL_U.CruiseONOFFswitch == 1.0) &&
             (Powertrain_ECU_SIL_U.Cruisesetting == 0.0)) ||
            (Powertrain_ECU_SIL_U.Driver_Brake_Pedal > 0.0)) {
          Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL =
            Powertrain_ECU_SIL_IN_STANDBY;
        } else if (Powertrain_ECU_SIL_U.CruiseONOFFswitch == 0.0) {
          Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL =
            Powertrain_ECU_SIL_IN_OFF;
        } else {
          Powertrain_ECU_SIL_B.Cruise_enable = 1.0;
        }
        break;

       case Powertrain_ECU_SIL_IN_OFF:
        if ((Powertrain_ECU_SIL_U.CruiseONOFFswitch == 1.0) &&
            (Powertrain_ECU_SIL_U.Cruisesetting == 1.0) &&
            (Powertrain_ECU_SIL_U.Vehicle_spd_kmhr > 20.0)) {
          Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL =
            Powertrain_ECU_SIL_IN_READY;
          Powertrain_ECU_SIL_B.Set_spd = Powertrain_ECU_SIL_U.Vehicle_spd_kmhr;
          Powertrain_ECU_SIL_B.Cruise_enable = 0.0;
        } else {
          Powertrain_ECU_SIL_B.Cruise_enable = 0.0;
        }
        break;

       case Powertrain_ECU_SIL_IN_READY:
        Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL =
          Powertrain_ECU_SIL_IN_ACTIVE;
        break;

       default:
        /* case IN_STANDBY: */
        if ((Powertrain_ECU_SIL_U.CruiseONOFFswitch == 1.0) &&
            (Powertrain_ECU_SIL_U.Cruisesetting == 2.0)) {
          Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL =
            Powertrain_ECU_SIL_IN_ACTIVE;
        } else if (Powertrain_ECU_SIL_U.CruiseONOFFswitch == 0.0) {
          Powertrain_ECU_SIL_DW.is_c1_Powertrain_ECU_SIL =
            Powertrain_ECU_SIL_IN_OFF;
        } else {
          Powertrain_ECU_SIL_B.Cruise_enable = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&Powertrain_ECU_SIL_M->solverInfo)) {
      if (Powertrain_ECU_SIL_B.Cruise_enable > 0.0) {
        if (!Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE) {
          (void) memset(&(Powertrain_ECU_SIL_XDis.Filter_CSTATE), 0,
                        2*sizeof(boolean_T));

          /* InitializeConditions for Integrator: '<S33>/Filter' */
          Powertrain_ECU_SIL_X.Filter_CSTATE = 0.0;

          /* InitializeConditions for Integrator: '<S38>/Integrator' */
          Powertrain_ECU_SIL_X.Integrator_CSTATE = 0.0;

          /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
          Powertrain_ECU_SIL_DW.LastMajorTime = (rtInf);
          Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE = true;
        }
      } else {
        if (((Powertrain_ECU_SIL_M->Timing.clockTick1) * 1.0) == rtmGetTStart
            (Powertrain_ECU_SIL_M)) {
          (void) memset(&(Powertrain_ECU_SIL_XDis.Filter_CSTATE), 1,
                        2*sizeof(boolean_T));
        }

        if (Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE) {
          (void) memset(&(Powertrain_ECU_SIL_XDis.Filter_CSTATE), 1,
                        2*sizeof(boolean_T));
          Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Inport: '<Root>/Vehicle speed km//hr'
     */
    rtb_Switch = Powertrain_ECU_SIL_B.Set_spd -
      Powertrain_ECU_SIL_U.Vehicle_spd_kmhr;

    /* DeadZone: '<S2>/Dead Zone' */
    if (rtb_Switch > 0.5) {
      rtb_Switch -= 0.5;
    } else if (rtb_Switch >= -0.5) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch -= -0.5;
    }

    /* End of DeadZone: '<S2>/Dead Zone' */
    if (rtmIsMajorTimeStep(Powertrain_ECU_SIL_M) &&
        Powertrain_ECU_SIL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Logic: '<S2>/NOT' */
      Powertrain_ECU_SIL_B.NOT = !(Powertrain_ECU_SIL_B.Cruise_enable != 0.0);
    }

    /* Integrator: '<S33>/Filter' incorporates:
     *  Integrator: '<S38>/Integrator'
     */
    if (rtsiIsModeUpdateTimeStep(&Powertrain_ECU_SIL_M->solverInfo)) {
      didZcEventOccur = (Powertrain_ECU_SIL_B.NOT &&
                         (Powertrain_ECU_SIL_PrevZCX.Filter_Reset_ZCE !=
                          POS_ZCSIG));
      Powertrain_ECU_SIL_PrevZCX.Filter_Reset_ZCE = Powertrain_ECU_SIL_B.NOT;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        Powertrain_ECU_SIL_X.Filter_CSTATE = 0.0;
      }

      didZcEventOccur = (Powertrain_ECU_SIL_B.NOT &&
                         (Powertrain_ECU_SIL_PrevZCX.Integrator_Reset_ZCE !=
                          POS_ZCSIG));
      Powertrain_ECU_SIL_PrevZCX.Integrator_Reset_ZCE = Powertrain_ECU_SIL_B.NOT;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        Powertrain_ECU_SIL_X.Integrator_CSTATE = 0.0;
      }
    }

    /* Gain: '<S41>/Filter Coefficient' incorporates:
     *  Gain: '<S31>/Derivative Gain'
     *  Integrator: '<S33>/Filter'
     *  Sum: '<S33>/SumD'
     */
    Powertrain_ECU_SIL_B.FilterCoefficient = (0.0 * rtb_Switch -
      Powertrain_ECU_SIL_X.Filter_CSTATE) * 100.0;

    /* Sum: '<S47>/Sum' incorporates:
     *  Integrator: '<S38>/Integrator'
     */
    rtb_Sum = (rtb_Switch + Powertrain_ECU_SIL_X.Integrator_CSTATE) +
      Powertrain_ECU_SIL_B.FilterCoefficient;

    /* Saturate: '<S45>/Saturation' */
    if (rtb_Sum > 100.0) {
      /* Saturate: '<S45>/Saturation' */
      Powertrain_ECU_SIL_B.RateLimiter = 100.0;
    } else if (rtb_Sum < 0.0) {
      /* Saturate: '<S45>/Saturation' */
      Powertrain_ECU_SIL_B.RateLimiter = 0.0;
    } else {
      /* Saturate: '<S45>/Saturation' */
      Powertrain_ECU_SIL_B.RateLimiter = rtb_Sum;
    }

    /* End of Saturate: '<S45>/Saturation' */

    /* Sum: '<S30>/SumI4' incorporates:
     *  Gain: '<S35>/Integral Gain'
     *  Sum: '<S30>/SumI2'
     */
    Powertrain_ECU_SIL_B.SumI4 = (Powertrain_ECU_SIL_B.RateLimiter - rtb_Sum) +
      0.5 * rtb_Switch;

    /* RateLimiter: '<S2>/Rate Limiter' incorporates:
     *  Saturate: '<S2>/Saturation'
     */
    if (!(Powertrain_ECU_SIL_DW.LastMajorTime == (rtInf))) {
      rtb_Sum = Powertrain_ECU_SIL_M->Timing.t[0];
      rtb_Switch = rtb_Sum - Powertrain_ECU_SIL_DW.LastMajorTime;
      if (Powertrain_ECU_SIL_DW.LastMajorTime == rtb_Sum) {
        if (Powertrain_ECU_SIL_DW.PrevLimited) {
          /* Saturate: '<S45>/Saturation' incorporates:
           *  RateLimiter: '<S2>/Rate Limiter'
           */
          Powertrain_ECU_SIL_B.RateLimiter = Powertrain_ECU_SIL_DW.PrevY;
        }
      } else {
        riseValLimit = rtb_Switch * 25.0;
        rtb_Sum = Powertrain_ECU_SIL_B.RateLimiter - Powertrain_ECU_SIL_DW.PrevY;
        if (rtb_Sum > riseValLimit) {
          /* Saturate: '<S45>/Saturation' incorporates:
           *  RateLimiter: '<S2>/Rate Limiter'
           */
          Powertrain_ECU_SIL_B.RateLimiter = Powertrain_ECU_SIL_DW.PrevY +
            riseValLimit;
          didZcEventOccur = true;
        } else {
          rtb_Switch *= -40.0;
          if (rtb_Sum < rtb_Switch) {
            /* Saturate: '<S45>/Saturation' incorporates:
             *  RateLimiter: '<S2>/Rate Limiter'
             */
            Powertrain_ECU_SIL_B.RateLimiter = Powertrain_ECU_SIL_DW.PrevY +
              rtb_Switch;
            didZcEventOccur = true;
          } else {
            didZcEventOccur = false;
          }
        }

        if (rtsiIsModeUpdateTimeStep(&Powertrain_ECU_SIL_M->solverInfo)) {
          Powertrain_ECU_SIL_DW.PrevLimited = didZcEventOccur;
        }
      }
    }

    /* End of RateLimiter: '<S2>/Rate Limiter' */
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Switch: '<Root>/Switch' */
  if (Powertrain_ECU_SIL_B.Cruise_enable > 0.0) {
    /* Outport: '<Root>/Accelerator_command' */
    Powertrain_ECU_SIL_Y.Accelerator_command = Powertrain_ECU_SIL_B.RateLimiter;
  } else {
    /* Outport: '<Root>/Accelerator_command' incorporates:
     *  Inport: '<Root>/Driver_Accelerator_pedal'
     */
    Powertrain_ECU_SIL_Y.Accelerator_command =
      Powertrain_ECU_SIL_U.Driver_Accelerator_Pedal;
  }

  /* End of Switch: '<Root>/Switch' */
  if (rtmIsMajorTimeStep(Powertrain_ECU_SIL_M)) {
    /* Update for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE) {
      /* Update for RateLimiter: '<S2>/Rate Limiter' */
      Powertrain_ECU_SIL_DW.PrevY = Powertrain_ECU_SIL_B.RateLimiter;
      Powertrain_ECU_SIL_DW.LastMajorTime = Powertrain_ECU_SIL_M->Timing.t[0];
    }

    /* End of Update for SubSystem: '<Root>/Enabled Subsystem' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Powertrain_ECU_SIL_M)) {
    rt_ertODEUpdateContinuousStates(&Powertrain_ECU_SIL_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Powertrain_ECU_SIL_M->Timing.clockTick0;
    Powertrain_ECU_SIL_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Powertrain_ECU_SIL_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Powertrain_ECU_SIL_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Powertrain_ECU_SIL_derivatives(void)
{
  XDot_Powertrain_ECU_SIL_T *_rtXdot;
  _rtXdot = ((XDot_Powertrain_ECU_SIL_T *) Powertrain_ECU_SIL_M->derivs);

  /* Derivatives for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  if (Powertrain_ECU_SIL_DW.EnabledSubsystem_MODE) {
    /* Derivatives for Integrator: '<S33>/Filter' */
    _rtXdot->Filter_CSTATE = Powertrain_ECU_SIL_B.FilterCoefficient;

    /* Derivatives for Integrator: '<S38>/Integrator' */
    _rtXdot->Integrator_CSTATE = Powertrain_ECU_SIL_B.SumI4;
  } else {
    {
      real_T *dx;
      int_T i1;
      dx = &(((XDot_Powertrain_ECU_SIL_T *) Powertrain_ECU_SIL_M->derivs)
             ->Filter_CSTATE);
      for (i1=0; i1 < 2; i1++) {
        dx[i1] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model initialize function */
void Powertrain_ECU_SIL_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Powertrain_ECU_SIL_M->solverInfo,
                          &Powertrain_ECU_SIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&Powertrain_ECU_SIL_M->solverInfo, &rtmGetTPtr
                (Powertrain_ECU_SIL_M));
    rtsiSetStepSizePtr(&Powertrain_ECU_SIL_M->solverInfo,
                       &Powertrain_ECU_SIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&Powertrain_ECU_SIL_M->solverInfo,
                 &Powertrain_ECU_SIL_M->derivs);
    rtsiSetContStatesPtr(&Powertrain_ECU_SIL_M->solverInfo, (real_T **)
                         &Powertrain_ECU_SIL_M->contStates);
    rtsiSetNumContStatesPtr(&Powertrain_ECU_SIL_M->solverInfo,
      &Powertrain_ECU_SIL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Powertrain_ECU_SIL_M->solverInfo,
      &Powertrain_ECU_SIL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Powertrain_ECU_SIL_M->solverInfo,
      &Powertrain_ECU_SIL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Powertrain_ECU_SIL_M->solverInfo,
      &Powertrain_ECU_SIL_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Powertrain_ECU_SIL_M->solverInfo, (boolean_T**)
      &Powertrain_ECU_SIL_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Powertrain_ECU_SIL_M->solverInfo, (&rtmGetErrorStatus
      (Powertrain_ECU_SIL_M)));
    rtsiSetRTModelPtr(&Powertrain_ECU_SIL_M->solverInfo, Powertrain_ECU_SIL_M);
  }

  rtsiSetSimTimeStep(&Powertrain_ECU_SIL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Powertrain_ECU_SIL_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Powertrain_ECU_SIL_M->solverInfo, false);
  Powertrain_ECU_SIL_M->intgData.y = Powertrain_ECU_SIL_M->odeY;
  Powertrain_ECU_SIL_M->intgData.f[0] = Powertrain_ECU_SIL_M->odeF[0];
  Powertrain_ECU_SIL_M->intgData.f[1] = Powertrain_ECU_SIL_M->odeF[1];
  Powertrain_ECU_SIL_M->intgData.f[2] = Powertrain_ECU_SIL_M->odeF[2];
  Powertrain_ECU_SIL_M->contStates = ((X_Powertrain_ECU_SIL_T *)
    &Powertrain_ECU_SIL_X);
  Powertrain_ECU_SIL_M->contStateDisabled = ((XDis_Powertrain_ECU_SIL_T *)
    &Powertrain_ECU_SIL_XDis);
  Powertrain_ECU_SIL_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Powertrain_ECU_SIL_M->solverInfo, (void *)
                    &Powertrain_ECU_SIL_M->intgData);
  rtsiSetSolverName(&Powertrain_ECU_SIL_M->solverInfo,"ode3");
  rtmSetTPtr(Powertrain_ECU_SIL_M, &Powertrain_ECU_SIL_M->Timing.tArray[0]);
  Powertrain_ECU_SIL_M->Timing.stepSize0 = 1.0;
  Powertrain_ECU_SIL_PrevZCX.Filter_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Powertrain_ECU_SIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* InitializeConditions for Integrator: '<S33>/Filter' */
  Powertrain_ECU_SIL_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S38>/Integrator' */
  Powertrain_ECU_SIL_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
  Powertrain_ECU_SIL_DW.LastMajorTime = (rtInf);

  /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model terminate function */
void Powertrain_ECU_SIL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
