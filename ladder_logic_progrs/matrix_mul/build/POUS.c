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





void ELEMENT_SELECTOR_init__(ELEMENT_SELECTOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_DINT_4 temp = {{0,0,0,0}};
    __SET_VAR(data__->,ARRAY1,,temp);
  }
  __INIT_VAR(data__->INDEX,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void ELEMENT_SELECTOR_body__(ELEMENT_SELECTOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,OUT,,__GET_VAR(data__->ARRAY1,.table[(__GET_VAR(data__->INDEX,)) - (0)]));

  goto __end;

__end:
  return;
} // ELEMENT_SELECTOR_body__() 





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
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR0,retain);
}

// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->ELEMENT_SELECTOR0.,ARRAY1,,__GET_VAR(data__->M_A,));
  __SET_VAR(data__->ELEMENT_SELECTOR0.,INDEX,,0);
  ELEMENT_SELECTOR_body__(&data__->ELEMENT_SELECTOR0);
  __SET_VAR(data__->,M_A,,__GET_VAR(data__->ELEMENT_SELECTOR0.ARRAY1));
  __SET_VAR(data__->,ELEMENT_A,,__GET_VAR(data__->ELEMENT_SELECTOR0.OUT,));

  goto __end;

__end:
  return;
} // MATRIX_MUL_body__() 





