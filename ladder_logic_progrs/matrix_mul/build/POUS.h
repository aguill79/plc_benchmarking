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
__DECLARE_ARRAY_TYPE(__ARRAY_OF_DINT_4,DINT,[4])
// FUNCTION_BLOCK ELEMENT_SELECTOR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_DINT_4,ARRAY1)
  __DECLARE_VAR(INT,INDEX)
  __DECLARE_VAR(DINT,OUT)

  // FB private variables - TEMP, private and located variables

} ELEMENT_SELECTOR;

void ELEMENT_SELECTOR_init__(ELEMENT_SELECTOR *data__, BOOL retain);
// Code part
void ELEMENT_SELECTOR_body__(ELEMENT_SELECTOR *data__);
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
  ELEMENT_SELECTOR ELEMENT_SELECTOR0;

} MATRIX_MUL;

void MATRIX_MUL_init__(MATRIX_MUL *data__, BOOL retain);
// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__);
#endif //__POUS_H
