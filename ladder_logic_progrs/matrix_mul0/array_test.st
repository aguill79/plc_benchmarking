FUNCTION_BLOCK element_selector
  VAR_INPUT
    array1 : ARRAY [0..3] OF DINT;
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
    element_a AT %QD0 : DINT;
    element_b AT %QD1 : DINT;
    element_c AT %QD2 : DINT;
  END_VAR
  VAR
    element_selector0 : element_selector;
  END_VAR

  element_selector0(array1 := m_A, index := 1);
  element_a := element_selector0.out;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION
