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

static inline INT __FLOPS_SUB__INT__INT__INT2(BOOL EN,
  INT IN1,
  INT IN2,
  FLOPS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_SUB7_ENO,);
  __res = SUB__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_SUB7_ENO,,__TMP_ENO);
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

static inline BOOL __FLOPS_LE__BOOL__INT5(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  FLOPS *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_LE18_ENO,);
  __res = LE__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_LE18_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __FLOPS_MOVE__INT__INT6(BOOL EN,
  INT IN,
  FLOPS *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE28_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE28_ENO,,__TMP_ENO);
  return __res;
}

void FLOPS_init__(FLOPS *data__, BOOL retain) {
  __INIT_VAR(data__->PRODUCT,1.0,retain)
  __INIT_VAR(data__->NUM_OPS,200,retain)
  __INIT_VAR(data__->COUNT,0,retain)
  __INIT_VAR(data__->RUN_FLAG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RUN_STATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL2_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL2_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GT12_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE15_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LE18_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE18_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE28_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE28_OUT,0,retain)
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
  __SET_VAR(data__->,_TMP_SUB7_OUT,,__FLOPS_SUB__INT__INT__INT2(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (INT)__GET_VAR(data__->COUNT,),
    (INT)1,
    data__));
  if (__GET_VAR(data__->_TMP_SUB7_ENO,)) {
    __SET_VAR(data__->,COUNT,,__GET_VAR(data__->_TMP_SUB7_OUT,));
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
  __SET_VAR(data__->,_TMP_LE18_OUT,,__FLOPS_LE__BOOL__INT5(
    (BOOL)__GET_VAR(data__->RUN_FLAG,),
    (UINT)2,
    (INT)__GET_VAR(data__->COUNT,),
    (INT)0,
    data__));
  if (__GET_VAR(data__->_TMP_LE18_OUT,)) {
    __SET_VAR(data__->,RUN_FLAG,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,_TMP_MOVE28_OUT,,__FLOPS_MOVE__INT__INT6(
    (BOOL)(!(__GET_VAR(data__->RUN_FLAG,)) && __GET_VAR(data__->RESET,)),
    (INT)__GET_VAR(data__->NUM_OPS,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE28_ENO,)) {
    __SET_VAR(data__->,COUNT,,__GET_VAR(data__->_TMP_MOVE28_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE28_ENO,)) {
    __SET_VAR(data__->,RESET,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,RUN_STATUS,,__GET_VAR(data__->_TMP_MUL2_ENO,));
  if (__GET_VAR(data__->_TMP_LE18_OUT,)) {
    __SET_VAR(data__->,RUN_STATUS,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // FLOPS_body__() 





