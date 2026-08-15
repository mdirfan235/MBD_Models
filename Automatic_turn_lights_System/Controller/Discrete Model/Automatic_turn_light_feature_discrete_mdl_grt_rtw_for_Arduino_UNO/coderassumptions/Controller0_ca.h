/*
 * File: Controller0_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef CONTROLLER0_CA_H
#define CONTROLLER0_CA_H

/* preprocessor validation checks */
#include "Controller0_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_ChecksTestResults CA_Controller0_Res;
extern CA_PWS_TestResults CA_Controller0_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_Checks CA_Controller0_Exp;
extern CA_Checks CA_Controller0_Act;
extern const int numberOfImportedTypes;
extern const int numberOfNonTunableEnumLiterals;

/* entry point function to run tests */
void Controller0_caRunTests(void);

#endif                                 /* CONTROLLER0_CA_H */
