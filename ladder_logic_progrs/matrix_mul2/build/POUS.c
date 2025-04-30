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
    static const __ARRAY_OF_DINT_9 temp = {{0,0,0,0,0,0,0,0,0}};
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





void MM_FB_init__(MM_FB *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_DINT_9 temp = {{1,2,3,4,5,6,7,8,9}};
    __SET_VAR(data__->,M0,,temp);
  }
  {
    static const __ARRAY_OF_DINT_9 temp = {{1,2,3,4,5,6,7,8,9}};
    __SET_VAR(data__->,M1,,temp);
  }
  {
    static const __ARRAY_OF_DINT_9 temp = {{0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,M2,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->J,0,retain)
  __INIT_VAR(data__->K,0,retain)
  __INIT_VAR(data__->SUM,0,retain)
  __INIT_VAR(data__->CHECK_SUM,0,retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->FINISHED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->A,0,retain)
}

// Code part
void MM_FB_body__(MM_FB *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->FINISHED,))) {
    if ((((__GET_VAR(data__->K,) < __GET_VAR(data__->N,)) && (__GET_VAR(data__->J,) < __GET_VAR(data__->N,))) && (__GET_VAR(data__->I,) < __GET_VAR(data__->N,)))) {
      __SET_VAR(data__->,SUM,,(__GET_VAR(data__->SUM,) + (__GET_VAR(data__->M0,.table[(((__GET_VAR(data__->I,) * __GET_VAR(data__->N,)) + __GET_VAR(data__->K,))) - (0)]) * __GET_VAR(data__->M1,.table[(((__GET_VAR(data__->K,) * __GET_VAR(data__->N,)) + __GET_VAR(data__->J,))) - (0)]))));
      __SET_VAR(data__->,K,,(__GET_VAR(data__->K,) + 1));
    } else if (((__GET_VAR(data__->J,) < __GET_VAR(data__->N,)) && (__GET_VAR(data__->I,) < __GET_VAR(data__->N,)))) {
      __SET_VAR(data__->,M2,.table[(((__GET_VAR(data__->I,) * __GET_VAR(data__->N,)) + __GET_VAR(data__->J,))) - (0)],__GET_VAR(data__->SUM,));
      __SET_VAR(data__->,SUM,,0);
      __SET_VAR(data__->,K,,0);
      __SET_VAR(data__->,J,,(__GET_VAR(data__->J,) + 1));
    } else if ((__GET_VAR(data__->I,) < __GET_VAR(data__->N,))) {
      __SET_VAR(data__->,J,,0);
      __SET_VAR(data__->,K,,0);
      __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) + 1));
    } else if ((__GET_VAR(data__->I,) >= __GET_VAR(data__->N,))) {
      __SET_VAR(data__->,FINISHED,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,SUM,,0);
      __SET_VAR(data__->,CHECK_SUM,,0);
      /* FOR ... */
      __SET_VAR(data__->,A,,0);
      {
        int __do_increment = 0;
        while( __GET_VAR(data__->A,) < ((__GET_VAR(data__->N,) * __GET_VAR(data__->N,)) - 1) ) {
          if(__do_increment){
            /* BY ... (of FOR loop) */
            __SET_VAR(data__->,A,,(__GET_VAR(data__->A,) + 1));
          } else __do_increment = 1;
          __SET_VAR(data__->,CHECK_SUM,,(__GET_VAR(data__->CHECK_SUM,) + __GET_VAR(data__->M2,.table[(__GET_VAR(data__->A,)) - (0)])));
        }
      } /* END_FOR */;
    };
  };

  goto __end;

__end:
  return;
} // MM_FB_body__() 





void MATRIX_MUL_init__(MATRIX_MUL *data__, BOOL retain) {
  
  {
    static const __ARRAY_OF_DINT_9 temp = {{1,2,3,4,5,6,7,8,9}};
    __SET_VAR(data__->,M_A,,temp);
  }
  {
    static const __ARRAY_OF_DINT_9 temp = {{1,2,3,4,5,6,7,8,9}};
    __SET_VAR(data__->,M_B,,temp);
  }
  {
    static const __ARRAY_OF_DINT_9 temp = {{0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,M_C,,temp);
  }__INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->J,0,retain)
  __INIT_VAR(data__->K,0,retain)
  __INIT_VAR(data__->N,3,retain)
  __INIT_VAR(data__->CHECK,0,retain)
  __INIT_VAR(data__->CURRENT_SUM,0,retain)
  __INIT_VAR(data__->RUN_FLAG,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RUN_STATUS,__BOOL_LITERAL(FALSE),retain)
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR0,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR1,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR2,retain);
  ELEMENT_SELECTOR_init__(&data__->ELEMENT_SELECTOR3,retain);
  MM_FB_init__(&data__->MM_FB0,retain);
}

// Code part
void MATRIX_MUL_body__(MATRIX_MUL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->MM_FB0.,M0,,__GET_VAR(data__->M_A,));
  __SET_VAR(data__->MM_FB0.,M1,,__GET_VAR(data__->M_B,));
  __SET_VAR(data__->MM_FB0.,M2,,__GET_VAR(data__->M_C,));
  __SET_VAR(data__->MM_FB0.,I,,__GET_VAR(data__->I,));
  __SET_VAR(data__->MM_FB0.,J,,__GET_VAR(data__->J,));
  __SET_VAR(data__->MM_FB0.,K,,__GET_VAR(data__->K,));
  __SET_VAR(data__->MM_FB0.,SUM,,__GET_VAR(data__->CURRENT_SUM,));
  __SET_VAR(data__->MM_FB0.,N,,__GET_VAR(data__->N,));
  MM_FB_body__(&data__->MM_FB0);
  __SET_VAR(data__->,M_A,,__GET_VAR(data__->MM_FB0.M0));
  __SET_VAR(data__->,M_B,,__GET_VAR(data__->MM_FB0.M1));
  __SET_VAR(data__->,M_C,,__GET_VAR(data__->MM_FB0.M2));
  __SET_VAR(data__->,I,,__GET_VAR(data__->MM_FB0.I));
  __SET_VAR(data__->,J,,__GET_VAR(data__->MM_FB0.J));
  __SET_VAR(data__->,K,,__GET_VAR(data__->MM_FB0.K));
  __SET_VAR(data__->,CURRENT_SUM,,__GET_VAR(data__->MM_FB0.SUM));
  __SET_VAR(data__->,RUN_STATUS,,__GET_VAR(data__->MM_FB0.FINISHED,));
  __SET_VAR(data__->,CHECK,,__GET_VAR(data__->MM_FB0.CHECK_SUM,));
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





void ELEMENT_SETTER_init__(ELEMENT_SETTER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_DINT_9 temp = {{1,2,3,4,5,6,7,8,9}};
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





