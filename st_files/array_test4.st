TYPE
  input_matrix : ARRAY [0..3] OF DINT := [1, 2, 3, 4];
  output_matrix : ARRAY [0..3] OF DINT := [0, 0, 0, 0];
END_TYPE

FUNCTION_BLOCK element_selector
  VAR_INPUT
    matrix : input_matrix;
    index : UINT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR

  out := matrix[index];
END_FUNCTION_BLOCK

PROGRAM matrix_mul
  VAR
    m_A : input_matrix;
    m_B : input_matrix;
    m_C : output_matrix;
  END_VAR
  VAR
    element_a AT %MD0 : DINT;
    element_b AT %MD1 : DINT;
  END_VAR
  VAR
    element_c : DINT;
    current_time : ULINT;
    start_time : DT;
    stop_time : DT;
  END_VAR
  VAR
    elapsed_time AT %ML2 : LREAL;
  END_VAR
  VAR
    rec_time : BOOL := true;
    input_matrices0 : element_selector;
    input_matrices1 : element_selector;
  END_VAR

  input_matrices0(matrix := m_A, index := 0);
  element_a := input_matrices0.out;
  input_matrices1(matrix := m_B, index := 1);
  element_b := input_matrices1.out;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      matrix_A : input_matrix;
      matrix_B : input_matrix;
      matrix_C : output_matrix;
    END_VAR
    TASK task0(INTERVAL := T#10ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION

