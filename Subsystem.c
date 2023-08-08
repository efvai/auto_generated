/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Aug  8 23:02:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-R
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Subsystem.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Subsystem_step(void)
{
  /* DiscreteIntegrator: '<S5>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE = 0.0;
  }

  if (rtDW.Integrator_PrevResetState != 0) {
    rtDW.Integrator_DSTATE = 0.0;
  }

  /* Outport: '<Root>/2' incorporates:
   *  DiscreteIntegrator: '<S5>/Integrator'
   */
  rtY.u = rtDW.Integrator_DSTATE;

  /* DiscreteIntegrator: '<S4>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_i != 0) {
    rtDW.Integrator_DSTATE_i = 0.0;
  }

  if (rtDW.Integrator_PrevResetState_h != 0) {
    rtDW.Integrator_DSTATE_i = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S5>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S4>/Integrator'
   */
  rtDW.Integrator_IC_LOADING = 0U;
  rtDW.Integrator_DSTATE += 5.0E-7 * rtDW.Integrator_DSTATE_i;
  rtDW.Integrator_PrevResetState = 0;

  /* Update for DiscreteIntegrator: '<S4>/Integrator' incorporates:
   *  Gain: '<S1>/Multiply'
   *  Inport: '<Root>/In1'
   */
  rtDW.Integrator_IC_LOADING_i = 0U;
  rtDW.Integrator_DSTATE_i += 5437.9 * rtU.In1 * 5.0E-7;
  rtDW.Integrator_PrevResetState_h = 0;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S5>/Integrator' */
  rtDW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Integrator' */
  rtDW.Integrator_IC_LOADING_i = 1U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
