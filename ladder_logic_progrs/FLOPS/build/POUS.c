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





static inline REAL __FLOPS_MUL__REAL__REAL1(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  FLOPS *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL2_ENO,);
  __res = MUL__REAL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL2_ENO,,__TMP_ENO);
  return __res;
}

static inline DINT __FLOPS_ADD__DINT__DINT2(BOOL EN,
  UINT __PARAM_COUNT,
  DINT IN1,
  DINT IN2,
  FLOPS *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD7_ENO,);
  __res = ADD__DINT__DINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD7_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __FLOPS_GT__BOOL__REAL3(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  FLOPS *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GT12_ENO,);
  __res = GT__BOOL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GT12_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __FLOPS_MOVE__REAL__REAL4(BOOL EN,
  REAL IN,
  FLOPS *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE15_ENO,);
  __res = MOVE__REAL__REAL(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE15_ENO,,__TMP_ENO);
  return __res;
}

void FLOPS_init__(FLOPS *data__, BOOL retain) {
  __INIT_VAR(data__->COUNT,0,retain)
  __INIT_VAR(data__->PRODUCT,1.0,retain)
  __INIT_VAR(data__->RUN_FLAG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL2_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL2_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GT12_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE15_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE15_OUT,0,retain)
}

// Code part
void FLOPS_body__(FLOPS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_MUL2_OUT,,__FLOPS_MUL__REAL__REAL1(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (REAL)__GET_VAR(data__->PRODUCT,),
    (REAL)5.0,
    data__));
  if (__GET_VAR(data__->_TMP_MUL2_ENO,)) {
    __SET_VAR(data__->,PRODUCT,,__GET_VAR(data__->_TMP_MUL2_OUT,));
  };
  __SET_VAR(data__->,_TMP_ADD7_OUT,,__FLOPS_ADD__DINT__DINT2(
    (BOOL)__GET_VAR(data__->_TMP_MUL2_ENO,),
    (UINT)2,
    (DINT)__GET_VAR(data__->COUNT,),
    (DINT)1,
    data__));
  if (__GET_VAR(data__->_TMP_ADD7_ENO,)) {
    __SET_VAR(data__->,COUNT,,__GET_VAR(data__->_TMP_ADD7_OUT,));
  };
  __SET_VAR(data__->,_TMP_GT12_OUT,,__FLOPS_GT__BOOL__REAL3(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (REAL)__GET_VAR(data__->PRODUCT,),
    (REAL)5000.0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE15_OUT,,__FLOPS_MOVE__REAL__REAL4(
    (BOOL)__GET_VAR(data__->_TMP_GT12_OUT,),
    (REAL)1.0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE15_ENO,)) {
    __SET_VAR(data__->,PRODUCT,,__GET_VAR(data__->_TMP_MOVE15_OUT,));
  };

  goto __end;

__end:
  return;
} // FLOPS_body__() 





