void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void MATRIX_ONE_init__(MATRIX_ONE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->INDEX,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_EXTERNAL(__ARRAY_OF_DINT_4,MATRIX_A,data__->MATRIX_A,retain)
}

// Code part
void MATRIX_ONE_body__(MATRIX_ONE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,OUT,,__GET_EXTERNAL(data__->MATRIX_A,.table[(__GET_VAR(data__->INDEX,)) - (0)]));

  goto __end;

__end:
  return;
} // MATRIX_ONE_body__() 





void MATRIX_TWO_init__(MATRIX_TWO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(__ARRAY_OF_DINT_4,MATRIX_B,data__->MATRIX_B,retain)
  __INIT_VAR(data__->INDEX,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void MATRIX_TWO_body__(MATRIX_TWO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,OUT,,__GET_EXTERNAL(data__->MATRIX_B,.table[(__GET_VAR(data__->INDEX,)) - (0)]));

  goto __end;

__end:
  return;
} // MATRIX_TWO_body__() 





void MATRIX_OUTPUT_init__(MATRIX_OUTPUT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_EXTERNAL(__ARRAY_OF_DINT_4,MATRIX_C,data__->MATRIX_C,retain)
  __INIT_VAR(data__->INDEX,0,retain)
  __INIT_VAR(data__->VALUE,0,retain)
}

// Code part
void MATRIX_OUTPUT_body__(MATRIX_OUTPUT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,MATRIX_C,.table[(__GET_VAR(data__->INDEX,)) - (0)],__GET_VAR(data__->VALUE,));

  goto __end;

__end:
  return;
} // MATRIX_OUTPUT_body__() 





void MATRIX_MUL_init__(MATRIX_MUL *data__, BOOL retain) {
  
  {
    static const __ARRAY_OF_DINT_4 temp = {{1,2,3,4}};
    __SET_VAR(data__->,M_A,,temp);
  }
  {
    static const __ARRAY_OF_DINT_4 temp = {{1,2,3,4}};
    __SET_VAR(data__->,M_B,,temp);
  }
  {
    static const __ARRAY_OF_DINT_4 temp = {{0,0,0,0}};
    __SET_VAR(data__->,M_C,,temp);
  }__INIT_VAR(data__->ELEMENT_A,0,retain)
  __INIT_VAR(data__->ELEMENT_B,0,retain)
  __INIT_VAR(data__->ELEMENT_C,0,retain)
  MATRIX_ONE_init__(&data__->ELEMENT_SELECTOR0,retain);
  MATRIX_TWO_init__(&data__->ELEMENT_SELECTOR1,retain);
  MATRIX_OUTPUT_init__(&data__->MATRIX_C0,retain);
  __INIT_VAR(data__->CURRENT_TIME,0,retain)
  __INIT_VAR(data__->START_TIME,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->STOP_TIME,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->ELAPSED_TIME,0,retain)
  __INIT_VAR(data__->REC_TIME,__BOOL_LITERAL(TRUE),retain)
  RTC_init__(&data__->RTC0,retain);
  RTC_init__(&data__->RTC1,retain);
  __INIT_VAR(data__->_TMP_MUL11_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DT_TO_LREAL30_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DT_TO_LREAL21_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB25_OUT,0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_DT35_OUT,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->_TMP_MOVE29_OUT,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->_TMP_INT_TO_DT14_OUT,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
  __INIT_VAR(data__->_TMP_MOVE19_OUT,__dt_to_timespec(0, 0, 0, 1, 1, 1970),retain)
}

// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->ELEMENT_SELECTOR0.,INDEX,,0);
  MATRIX_ONE_body__(&data__->ELEMENT_SELECTOR0);
  __SET_VAR(data__->,ELEMENT_A,,__GET_VAR(data__->ELEMENT_SELECTOR0.OUT,));
  __SET_VAR(data__->ELEMENT_SELECTOR1.,INDEX,,1);
  MATRIX_TWO_body__(&data__->ELEMENT_SELECTOR1);
  __SET_VAR(data__->,ELEMENT_B,,__GET_VAR(data__->ELEMENT_SELECTOR1.OUT,));
  __SET_VAR(data__->,_TMP_MUL11_OUT,,MUL__DINT__DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (DINT)__GET_VAR(data__->ELEMENT_A,),
    (DINT)__GET_VAR(data__->ELEMENT_B,)));
  __SET_VAR(data__->,ELEMENT_C,,__GET_VAR(data__->_TMP_MUL11_OUT,));
  __SET_VAR(data__->RTC0.,EN,,__GET_VAR(data__->REC_TIME,));
  RTC_body__(&data__->RTC0);
  if (__GET_VAR(data__->RTC0.ENO,)) {
    __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->RTC0.CDT,));
  };
  __SET_VAR(data__->,_TMP_DT_TO_LREAL30_OUT,,DT_TO_LREAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->STOP_TIME,)));
  __SET_VAR(data__->,_TMP_DT_TO_LREAL21_OUT,,DT_TO_LREAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->START_TIME,)));
  __SET_VAR(data__->,_TMP_SUB25_OUT,,SUB__LREAL__LREAL__LREAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (LREAL)__GET_VAR(data__->_TMP_DT_TO_LREAL30_OUT,),
    (LREAL)__GET_VAR(data__->_TMP_DT_TO_LREAL21_OUT,)));
  __SET_VAR(data__->,ELAPSED_TIME,,__GET_VAR(data__->_TMP_SUB25_OUT,));
  __SET_VAR(data__->RTC1.,EN,,__GET_VAR(data__->REC_TIME,));
  RTC_body__(&data__->RTC1);
  if (__GET_VAR(data__->RTC1.ENO,)) {
    __SET_VAR(data__->,STOP_TIME,,__GET_VAR(data__->RTC1.CDT,));
  };
  __SET_VAR(data__->,_TMP_INT_TO_DT35_OUT,,INT_TO_DT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)0));
  __SET_VAR(data__->,_TMP_MOVE29_OUT,,MOVE__DT__DT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->_TMP_INT_TO_DT35_OUT,)));
  __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->_TMP_MOVE29_OUT,));
  __SET_VAR(data__->,_TMP_INT_TO_DT14_OUT,,INT_TO_DT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)0));
  __SET_VAR(data__->,_TMP_MOVE19_OUT,,MOVE__DT__DT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->_TMP_INT_TO_DT14_OUT,)));
  __SET_VAR(data__->,STOP_TIME,,__GET_VAR(data__->_TMP_MOVE19_OUT,));
  __SET_VAR(data__->MATRIX_C0.,INDEX,,0);
  __SET_VAR(data__->MATRIX_C0.,VALUE,,__GET_VAR(data__->ELEMENT_C,));
  MATRIX_OUTPUT_body__(&data__->MATRIX_C0);

  goto __end;

__end:
  return;
} // MATRIX_MUL_body__() 





