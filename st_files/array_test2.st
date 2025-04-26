TYPE
  input_matrix : ARRAY [0..3] OF DINT := [1, 2, 3, 4];
  output_matrix : ARRAY [0..3] OF DINT := [0, 0, 0, 0];
END_TYPE

FUNCTION_BLOCK matrix_one
  VAR_INPUT
    index : UINT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR
  VAR_EXTERNAL
    matrix_A : input_matrix;
  END_VAR

  out := matrix_A[index];
END_FUNCTION_BLOCK

FUNCTION_BLOCK matrix_two
  VAR_EXTERNAL
    matrix_B : input_matrix;
  END_VAR
  VAR_INPUT
    index : UINT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR

  out := matrix_B[index];
END_FUNCTION_BLOCK

FUNCTION_BLOCK matrix_output
  VAR_EXTERNAL
    matrix_C : output_matrix;
  END_VAR
  VAR_INPUT
    index : UINT;
    value : DINT;
  END_VAR

  matrix_C[index] := value;
END_FUNCTION_BLOCK

PROGRAM matrix_mul
  VAR
    m_A : input_matrix;
    m_B : input_matrix;
    m_C : output_matrix;
  END_VAR
  VAR
    element_a AT %QD0 : DINT;
    element_b AT %QD1 : DINT;
    element_c AT %QD2 : DINT;
  END_VAR
  VAR
    element_selector0 : matrix_one;
    element_selector1 : matrix_two;
    matrix_C0 : matrix_output;
    _TMP_MUL11_OUT : DINT;
  END_VAR

  element_selector0(index := 0);
  element_a := element_selector0.out;
  element_selector1(index := 1);
  element_b := element_selector1.out;
  _TMP_MUL11_OUT := MUL(element_a, element_b);
  element_c := _TMP_MUL11_OUT;
  matrix_C0(index := 0, value := element_c);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      matrix_A : input_matrix;
      matrix_B : input_matrix;
      matrix_C : output_matrix;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION

