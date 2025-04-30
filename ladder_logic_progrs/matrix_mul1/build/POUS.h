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
__DECLARE_ARRAY_TYPE(__ARRAY_OF_DINT_9,DINT,[9])
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
// FUNCTION_BLOCK ELEMENT_SELECTOR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M)
  __DECLARE_VAR(UINT,INDEX)
  __DECLARE_VAR(DINT,OUT)

  // FB private variables - TEMP, private and located variables

} ELEMENT_SELECTOR;

void ELEMENT_SELECTOR_init__(ELEMENT_SELECTOR *data__, BOOL retain);
// Code part
void ELEMENT_SELECTOR_body__(ELEMENT_SELECTOR *data__);
// FUNCTION_BLOCK MM_FB
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M0)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M1)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M2)
  __DECLARE_VAR(DINT,CHECK_SUM)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(BOOL,FINISHED)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,J)
  __DECLARE_VAR(INT,K)
  __DECLARE_VAR(DINT,SUM)

} MM_FB;

void MM_FB_init__(MM_FB *data__, BOOL retain);
// Code part
void MM_FB_body__(MM_FB *data__);
// PROGRAM MATRIX_MUL
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M_A)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M_B)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M_C)
  __DECLARE_VAR(UINT,I)
  __DECLARE_VAR(UINT,J)
  __DECLARE_VAR(UINT,K)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(UINT,INDEX_A)
  __DECLARE_VAR(UINT,INDEX_B)
  __DECLARE_VAR(UINT,INDEX_C)
  __DECLARE_VAR(DINT,ELEMENT_A)
  __DECLARE_VAR(DINT,ELEMENT_B)
  __DECLARE_VAR(DINT,ELEMENT_C)
  __DECLARE_VAR(DINT,CHECK)
  __DECLARE_VAR(BOOL,RUN_FLAG)
  __DECLARE_VAR(BOOL,RUN_STATUS)
  ELEMENT_SELECTOR ELEMENT_SELECTOR0;
  ELEMENT_SELECTOR ELEMENT_SELECTOR1;
  ELEMENT_SELECTOR ELEMENT_SELECTOR2;
  ELEMENT_SELECTOR ELEMENT_SELECTOR3;
  MM_FB MM_FB0;

} MATRIX_MUL;

void MATRIX_MUL_init__(MATRIX_MUL *data__, BOOL retain);
// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__);
// FUNCTION_BLOCK ELEMENT_SETTER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_DINT_9,M)
  __DECLARE_VAR(UINT,INDEX)
  __DECLARE_VAR(DINT,VALUE)
  __DECLARE_VAR(DINT,OUT)

  // FB private variables - TEMP, private and located variables

} ELEMENT_SETTER;

void ELEMENT_SETTER_init__(ELEMENT_SETTER *data__, BOOL retain);
// Code part
void ELEMENT_SETTER_body__(ELEMENT_SETTER *data__);
#endif //__POUS_H
