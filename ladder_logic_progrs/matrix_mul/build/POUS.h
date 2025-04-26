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
__DECLARE_ARRAY_TYPE(__ARRAY_OF_DINT_4,DINT,[4])
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
// FUNCTION_BLOCK MATRIX_ONE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,INDEX)
  __DECLARE_VAR(DINT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(__ARRAY_OF_DINT_4,MATRIX_A)

} MATRIX_ONE;

void MATRIX_ONE_init__(MATRIX_ONE *data__, BOOL retain);
// Code part
void MATRIX_ONE_body__(MATRIX_ONE *data__);
// FUNCTION_BLOCK MATRIX_TWO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,INDEX)
  __DECLARE_VAR(DINT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(__ARRAY_OF_DINT_4,MATRIX_B)

} MATRIX_TWO;

void MATRIX_TWO_init__(MATRIX_TWO *data__, BOOL retain);
// Code part
void MATRIX_TWO_body__(MATRIX_TWO *data__);
// FUNCTION_BLOCK MATRIX_OUTPUT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,INDEX)
  __DECLARE_VAR(DINT,VALUE)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(__ARRAY_OF_DINT_4,MATRIX_C)

} MATRIX_OUTPUT;

void MATRIX_OUTPUT_init__(MATRIX_OUTPUT *data__, BOOL retain);
// Code part
void MATRIX_OUTPUT_body__(MATRIX_OUTPUT *data__);
// PROGRAM MATRIX_MUL
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(__ARRAY_OF_DINT_4,M_A)
  __DECLARE_VAR(__ARRAY_OF_DINT_4,M_B)
  __DECLARE_VAR(__ARRAY_OF_DINT_4,M_C)
  __DECLARE_VAR(DINT,ELEMENT_A)
  __DECLARE_VAR(DINT,ELEMENT_B)
  __DECLARE_VAR(DINT,ELEMENT_C)
  MATRIX_ONE ELEMENT_SELECTOR0;
  MATRIX_TWO ELEMENT_SELECTOR1;
  MATRIX_OUTPUT MATRIX_C0;
  __DECLARE_VAR(ULINT,CURRENT_TIME)
  __DECLARE_VAR(DT,START_TIME)
  __DECLARE_VAR(DT,STOP_TIME)
  __DECLARE_VAR(LREAL,ELAPSED_TIME)
  __DECLARE_VAR(BOOL,REC_TIME)
  RTC RTC0;
  RTC RTC1;
  __DECLARE_VAR(DINT,_TMP_MUL11_OUT)
  __DECLARE_VAR(LREAL,_TMP_DT_TO_LREAL30_OUT)
  __DECLARE_VAR(LREAL,_TMP_DT_TO_LREAL21_OUT)
  __DECLARE_VAR(LREAL,_TMP_SUB25_OUT)
  __DECLARE_VAR(DT,_TMP_INT_TO_DT35_OUT)
  __DECLARE_VAR(DT,_TMP_MOVE29_OUT)
  __DECLARE_VAR(DT,_TMP_INT_TO_DT14_OUT)
  __DECLARE_VAR(DT,_TMP_MOVE19_OUT)

} MATRIX_MUL;

void MATRIX_MUL_init__(MATRIX_MUL *data__, BOOL retain);
// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__);
#endif //__POUS_H
