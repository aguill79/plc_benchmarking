TYPE
  input_matrix : ARRAY [0..3] OF INT := [1, 2, 3, 4];
  output_matrix : ARRAY [0..3] OF DINT := [0, 0, 0, 0];
END_TYPE

FUNCTION_BLOCK input_matrices
  VAR_INPUT
    matrix1 : input_matrix;
    matrix2 : input_matrix;
    index1 : UINT;
    index2 : UINT;
  END_VAR
  VAR_OUTPUT
    out1 : INT;
    out2 : INT;
  END_VAR

  out1 := matrix1[index1];
  out2 := matrix2[index2];
END_FUNCTION_BLOCK

PROGRAM matrix_mul
  VAR
    m_A : input_matrix;
    m_B : input_matrix;
    m_C : output_matrix;
  END_VAR
  VAR
    element_a AT %QW0 : INT;
    element_b AT %QW1 : INT;
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
    input_matrices0 : input_matrices;
  END_VAR

  input_matrices0(matrix1 := m_A, matrix2 := m_B, index1 := 0, index2 := 1);
  element_a := input_matrices0.out1;
  element_b := input_matrices0.out2;
END_PROGRAM

FUNCTION_BLOCK matrix_one
  VAR_INPUT
    index : UINT;
  END_VAR
  VAR_OUTPUT
    out : INT;
  END_VAR
  VAR_INPUT
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
    out : INT;
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

