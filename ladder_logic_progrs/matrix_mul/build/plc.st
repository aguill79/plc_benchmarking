TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


FUNCTION_BLOCK element_selector
  VAR_IN_OUT
    array1 : ARRAY [0..3] OF DINT;
  END_VAR
  VAR_INPUT
    index : INT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR

  out := array1[index];
END_FUNCTION_BLOCK

PROGRAM matrix_mul
  VAR
    m_A : ARRAY [0..3] OF DINT := [1, 2, 3, 4];
    m_B : ARRAY [0..3] OF DINT := [1, 2, 3, 4];
    m_C : ARRAY [0..3] OF DINT := [0, 0, 0, 0];
  END_VAR
  VAR
    element_a : DINT;
    element_b : DINT;
    element_c : DINT;
  END_VAR
  VAR
    element_selector0 : element_selector;
  END_VAR

  element_selector0(array1 := m_A, index := 0);
  element_a := element_selector0.out;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION
