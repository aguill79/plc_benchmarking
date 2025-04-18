#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM FLOPS
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(DINT,COUNT)
  __DECLARE_VAR(DINT,NUM_OPS)
  __DECLARE_VAR(REAL,PRODUCT)
  __DECLARE_VAR(BOOL,RUN_FLAG)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,RUN_STATUS)
  __DECLARE_VAR(BOOL,_TMP_MUL2_ENO)
  __DECLARE_VAR(REAL,_TMP_MUL2_OUT)
  __DECLARE_VAR(BOOL,_TMP_SUB7_ENO)
  __DECLARE_VAR(DINT,_TMP_SUB7_OUT)
  __DECLARE_VAR(BOOL,_TMP_GT12_ENO)
  __DECLARE_VAR(BOOL,_TMP_GT12_OUT)
  __DECLARE_VAR(BOOL,_TMP_MOVE15_ENO)
  __DECLARE_VAR(REAL,_TMP_MOVE15_OUT)
  __DECLARE_VAR(BOOL,_TMP_LE18_ENO)
  __DECLARE_VAR(BOOL,_TMP_LE18_OUT)
  __DECLARE_VAR(BOOL,_TMP_MOVE28_ENO)
  __DECLARE_VAR(DINT,_TMP_MOVE28_OUT)

} FLOPS;

void FLOPS_init__(FLOPS *data__, BOOL retain);
// Code part
void FLOPS_body__(FLOPS *data__);
#endif //__POUS_H
