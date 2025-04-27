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
    static const __ARRAY_OF_DINT_4 temp = {{1,2,3,4}};
    __SET_VAR(data__->,M,,temp);
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

  __SET_VAR(data__->,OUT,,__GET_VAR(data__->M,.table[(__GET_VAR(data__->INDEX,)) - (0)]));

  goto __end;

__end:
  return;
} // ELEMENT_SELECTOR_body__() 





void ELEMENT_SETTER_init__(ELEMENT_SETTER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_DINT_4 temp = {{1,2,3,4}};
    __SET_VAR(data__->,M,,temp);
  }
  __INIT_VAR(data__->INDEX,0,retain)
  __INIT_VAR(data__->VALUE,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void ELEMENT_SETTER_body__(ELEMENT_SETTER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,M,.table[(__GET_VAR(data__->INDEX,)) - (0)],__GET_VAR(data__->VALUE,));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->M,.table[(__GET_VAR(data__->INDEX,)) - (0)]));

  goto __end;

__end:
  return;
} // ELEMENT_SETTER_body__() 





static inline BOOL __MATRIX_MUL_GE__BOOL__UINT1(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GE48_ENO,);
  __res = GE__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GE48_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_MUL__UINT__UINT2(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL43_ENO,);
  __res = MUL__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL43_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_ADD__UINT__UINT3(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD42_ENO,);
  __res = ADD__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD42_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_MUL__UINT__UINT4(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL6_ENO,);
  __res = MUL__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL6_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_ADD__UINT__UINT5(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD5_ENO,);
  __res = ADD__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD5_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_MUL__UINT__UINT6(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL19_ENO,);
  __res = MUL__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL19_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_ADD__UINT__UINT7(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD18_ENO,);
  __res = ADD__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD18_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_ADD__UINT__UINT8(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD46_ENO,);
  __res = ADD__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD46_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_MOVE__UINT__UINT9(BOOL EN,
  UINT IN,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE49_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE49_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_ADD__UINT__UINT10(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD30_ENO,);
  __res = ADD__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD30_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __MATRIX_MUL_GE__BOOL__UINT11(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GE34_ENO,);
  __res = GE__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GE34_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_MOVE__UINT__UINT12(BOOL EN,
  UINT IN,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE40_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE40_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MATRIX_MUL_ADD__UINT__UINT13(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD58_ENO,);
  __res = ADD__UINT__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD58_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __MATRIX_MUL_GE__BOOL__UINT14(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  MATRIX_MUL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GE52_ENO,);
  __res = GE__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GE52_ENO,,__TMP_ENO);
  return __res;
}

static inline DINT __MATRIX_MUL_MUL__DINT__DINT15(BOOL EN,
  UINT __PARAM_COUNT,
  DINT IN1,
  DINT IN2,
  MATRIX_MUL *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL68_ENO,);
  __res = MUL__DINT__DINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL68_ENO,,__TMP_ENO);
  return __res;
}

static inline DINT __MATRIX_MUL_ADD__DINT__DINT16(BOOL EN,
  UINT __PARAM_COUNT,
  DINT IN1,
  DINT IN2,
  MATRIX_MUL *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD69_ENO,);
  __res = ADD__DINT__DINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD69_ENO,,__TMP_ENO);
  return __res;
}

static inline DINT __MATRIX_MUL_MOVE__DINT__DINT17(BOOL EN,
  DINT IN,
  MATRIX_MUL *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE71_ENO,);
  __res = MOVE__DINT__DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE71_ENO,,__TMP_ENO);
  return __res;
}

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
    static const __ARRAY_OF_DINT_4 temp = {{1,2,3,4}};
    __SET_VAR(data__->,M_C,,temp);
  }__INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->J,0,retain)
  __INIT_VAR(data__->K,0,retain)
  __INIT_VAR(data__->N,2,retain)
  __INIT_VAR(data__->INDEX_A,0,retain)
  __INIT_VAR(data__->INDEX_B,0,retain)
  __INIT_VAR(data__->INDEX_C,0,retain)
  __INIT_VAR(data__->ELEMENT_A,0,retain)
  __INIT_VAR(data__->ELEMENT_B,0,retain)
  __INIT_VAR(data__->ELEMENT_C,0,retain)
  __INIT_VAR(data__->CHECK,0,retain)
  __INIT_VAR(data__->RUN_FLAG,__BOOL_LITERAL(TRUE),retain)
  ELEMENT_SELECTOR_init__(&data__->INPUT_MATRICES0,retain);
  ELEMENT_SELECTOR_init__(&data__->INPUT_MATRICES1,retain);
  ELEMENT_SETTER_init__(&data__->ELEMENT_SETTER0,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR0,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR1,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR2,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR3,retain);
  __INIT_VAR(data__->_TMP_GE48_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE48_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL43_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL43_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD42_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD42_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL6_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL6_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD5_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD5_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL19_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL19_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD18_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD18_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD46_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD46_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE49_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE49_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD30_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD30_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GE34_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE34_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE40_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE40_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD58_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD58_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GE52_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE52_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL68_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL68_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD69_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD69_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE71_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE71_OUT,0,retain)
}

// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->INPUT_MATRICES0.,M,,__GET_VAR(data__->M_A,));
  __SET_VAR(data__->INPUT_MATRICES0.,INDEX,,__GET_VAR(data__->INDEX_A,));
  ELEMENT_SELECTOR_body__(&data__->INPUT_MATRICES0);
  __SET_VAR(data__->,ELEMENT_A,,__GET_VAR(data__->INPUT_MATRICES0.OUT,));
  __SET_VAR(data__->INPUT_MATRICES1.,M,,__GET_VAR(data__->M_B,));
  __SET_VAR(data__->INPUT_MATRICES1.,INDEX,,__GET_VAR(data__->INDEX_B,));
  ELEMENT_SELECTOR_body__(&data__->INPUT_MATRICES1);
  __SET_VAR(data__->,ELEMENT_B,,__GET_VAR(data__->INPUT_MATRICES1.OUT,));
  __SET_VAR(data__->,_TMP_GE48_OUT,,__MATRIX_MUL_GE__BOOL__UINT1(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->K,),
    (UINT)__GET_VAR(data__->N,),
    data__));
  __SET_VAR(data__->ELEMENT_SETTER0.,EN,,__GET_VAR(data__->_TMP_GE48_OUT,));
  __SET_VAR(data__->ELEMENT_SETTER0.,M,,__GET_VAR(data__->M_C,));
  __SET_VAR(data__->ELEMENT_SETTER0.,INDEX,,__GET_VAR(data__->INDEX_C,));
  __SET_VAR(data__->ELEMENT_SETTER0.,VALUE,,__GET_VAR(data__->ELEMENT_C,));
  ELEMENT_SETTER_body__(&data__->ELEMENT_SETTER0);
  __SET_VAR(data__->,M_C,,__GET_VAR(data__->ELEMENT_SETTER0.M));
  if (__GET_VAR(data__->ELEMENT_SETTER0.ENO,)) {
    __SET_VAR(data__->,CHECK,,__GET_VAR(data__->ELEMENT_SETTER0.OUT,));
  };
  __SET_VAR(data__->,_TMP_MUL43_OUT,,__MATRIX_MUL_MUL__UINT__UINT2(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->I,),
    (UINT)__GET_VAR(data__->N,),
    data__));
  __SET_VAR(data__->,_TMP_ADD42_OUT,,__MATRIX_MUL_ADD__UINT__UINT3(
    (BOOL)__GET_VAR(data__->_TMP_MUL43_ENO,),
    (UINT)2,
    (UINT)__GET_VAR(data__->_TMP_MUL43_OUT,),
    (UINT)__GET_VAR(data__->K,),
    data__));
  if (__GET_VAR(data__->_TMP_ADD42_ENO,)) {
    __SET_VAR(data__->,INDEX_A,,__GET_VAR(data__->_TMP_ADD42_OUT,));
  };
  __SET_VAR(data__->,_TMP_MUL6_OUT,,__MATRIX_MUL_MUL__UINT__UINT4(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->K,),
    (UINT)__GET_VAR(data__->N,),
    data__));
  __SET_VAR(data__->,_TMP_ADD5_OUT,,__MATRIX_MUL_ADD__UINT__UINT5(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->_TMP_MUL6_OUT,),
    (UINT)__GET_VAR(data__->J,),
    data__));
  __SET_VAR(data__->,INDEX_B,,__GET_VAR(data__->_TMP_ADD5_OUT,));
  __SET_VAR(data__->,_TMP_MUL19_OUT,,__MATRIX_MUL_MUL__UINT__UINT6(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->I,),
    (UINT)__GET_VAR(data__->N,),
    data__));
  __SET_VAR(data__->,_TMP_ADD18_OUT,,__MATRIX_MUL_ADD__UINT__UINT7(
    (BOOL)__GET_VAR(data__->_TMP_MUL19_ENO,),
    (UINT)2,
    (UINT)__GET_VAR(data__->_TMP_MUL19_OUT,),
    (UINT)__GET_VAR(data__->J,),
    data__));
  if (__GET_VAR(data__->_TMP_ADD18_ENO,)) {
    __SET_VAR(data__->,INDEX_C,,__GET_VAR(data__->_TMP_ADD18_OUT,));
  };
  __SET_VAR(data__->,_TMP_ADD46_OUT,,__MATRIX_MUL_ADD__UINT__UINT8(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->K,),
    (UINT)1,
    data__));
  if (__GET_VAR(data__->_TMP_ADD46_ENO,)) {
    __SET_VAR(data__->,K,,__GET_VAR(data__->_TMP_ADD46_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE49_OUT,,__MATRIX_MUL_MOVE__UINT__UINT9(
    (BOOL)__GET_VAR(data__->_TMP_GE48_OUT,),
    (UINT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE49_ENO,)) {
    __SET_VAR(data__->,K,,__GET_VAR(data__->_TMP_MOVE49_OUT,));
  };
  __SET_VAR(data__->,_TMP_ADD30_OUT,,__MATRIX_MUL_ADD__UINT__UINT10(
    (BOOL)__GET_VAR(data__->_TMP_MOVE49_ENO,),
    (UINT)2,
    (UINT)__GET_VAR(data__->J,),
    (UINT)1,
    data__));
  if (__GET_VAR(data__->_TMP_ADD30_ENO,)) {
    __SET_VAR(data__->,J,,__GET_VAR(data__->_TMP_ADD30_OUT,));
  };
  __SET_VAR(data__->,_TMP_GE34_OUT,,__MATRIX_MUL_GE__BOOL__UINT11(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->J,),
    (UINT)__GET_VAR(data__->N,),
    data__));
  __SET_VAR(data__->,_TMP_MOVE40_OUT,,__MATRIX_MUL_MOVE__UINT__UINT12(
    (BOOL)__GET_VAR(data__->_TMP_GE34_OUT,),
    (UINT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE40_ENO,)) {
    __SET_VAR(data__->,J,,__GET_VAR(data__->_TMP_MOVE40_OUT,));
  };
  __SET_VAR(data__->,_TMP_ADD58_OUT,,__MATRIX_MUL_ADD__UINT__UINT13(
    (BOOL)__GET_VAR(data__->_TMP_MOVE40_ENO,),
    (UINT)2,
    (UINT)__GET_VAR(data__->I,),
    (UINT)1,
    data__));
  if (__GET_VAR(data__->_TMP_ADD58_ENO,)) {
    __SET_VAR(data__->,I,,__GET_VAR(data__->_TMP_ADD58_OUT,));
  };
  __SET_VAR(data__->,_TMP_GE52_OUT,,__MATRIX_MUL_GE__BOOL__UINT14(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (UINT)__GET_VAR(data__->I,),
    (UINT)__GET_VAR(data__->N,),
    data__));
  if (__GET_VAR(data__->_TMP_GE52_OUT,)) {
    __SET_VAR(data__->,RUN_FLAG,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,_TMP_MUL68_OUT,,__MATRIX_MUL_MUL__DINT__DINT15(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (DINT)__GET_VAR(data__->ELEMENT_A,),
    (DINT)__GET_VAR(data__->ELEMENT_B,),
    data__));
  __SET_VAR(data__->,_TMP_ADD69_OUT,,__MATRIX_MUL_ADD__DINT__DINT16(
    (BOOL)__GET_VAR(data__->_TMP_MUL68_ENO,),
    (UINT)2,
    (DINT)__GET_VAR(data__->_TMP_MUL68_OUT,),
    (DINT)__GET_VAR(data__->ELEMENT_C,),
    data__));
  if (__GET_VAR(data__->_TMP_ADD69_ENO,)) {
    __SET_VAR(data__->,ELEMENT_C,,__GET_VAR(data__->_TMP_ADD69_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE71_OUT,,__MATRIX_MUL_MOVE__DINT__DINT17(
    (BOOL)__GET_VAR(data__->ELEMENT_SETTER0.ENO,),
    (DINT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE71_ENO,)) {
    __SET_VAR(data__->,ELEMENT_C,,__GET_VAR(data__->_TMP_MOVE71_OUT,));
  };
  __SET_VAR(data__->ELEMENT_SELECTOR0.,M,,__GET_VAR(data__->M_C,));
  __SET_VAR(data__->ELEMENT_SELECTOR0.,INDEX,,0);
  ELEMENT_SELECTOR_body__(&data__->ELEMENT_SELECTOR0);
  __SET_VAR(data__->ELEMENT_SELECTOR1.,M,,__GET_VAR(data__->M_C,));
  __SET_VAR(data__->ELEMENT_SELECTOR1.,INDEX,,1);
  ELEMENT_SELECTOR_body__(&data__->ELEMENT_SELECTOR1);
  __SET_VAR(data__->ELEMENT_SELECTOR2.,M,,__GET_VAR(data__->M_C,));
  __SET_VAR(data__->ELEMENT_SELECTOR2.,INDEX,,2);
  ELEMENT_SELECTOR_body__(&data__->ELEMENT_SELECTOR2);
  __SET_VAR(data__->ELEMENT_SELECTOR3.,M,,__GET_VAR(data__->M_C,));
  __SET_VAR(data__->ELEMENT_SELECTOR3.,INDEX,,3);
  ELEMENT_SELECTOR_body__(&data__->ELEMENT_SELECTOR3);

  goto __end;

__end:
  return;
} // MATRIX_MUL_body__() 





