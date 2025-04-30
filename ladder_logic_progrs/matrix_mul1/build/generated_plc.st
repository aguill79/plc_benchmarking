TYPE
  in_matrix : ARRAY [0..8] OF DINT := [1, 2, 3, 4, 5, 6, 7, 8, 9];
  out_matrix : ARRAY [0..8] OF DINT := [0, 0, 0, 0, 0, 0, 0, 0, 0];
END_TYPE

FUNCTION_BLOCK element_selector
  VAR_INPUT
    M : in_matrix;
    index : UINT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR

  out := M[index];
END_FUNCTION_BLOCK

FUNCTION_BLOCK mm_fb
  VAR_IN_OUT
    m0 : in_matrix;
    m1 : in_matrix;
    m2 : out_matrix;
  END_VAR
  VAR
    i : INT;
    j : INT;
    k : INT;
    sum : DINT;
  END_VAR
  VAR_OUTPUT
    check_sum : DINT;
  END_VAR
  VAR_INPUT
    n : INT;
  END_VAR
  VAR_OUTPUT
    finished : BOOL := false;
  END_VAR

  for i:= 0 to n-1 do
    for j := 0 to n-1 do
      sum := 0;
      for k := 0 to n-1 do
        sum := sum + m0[i*n+k] * m1[k*n+j];
      end_for;
      m2[i*n+j] := sum;
    end_for;
  end_for;

  if i >= n-1 then
    finished := true;
    
    sum := 0;
    check_sum := 0;
    
    for j := 0 to n*n-1 do
      check_sum := check_sum + m2[j];
    end_for;
  end_if;
END_FUNCTION_BLOCK

PROGRAM matrix_mul
  VAR
    m_A : in_matrix;
    m_B : in_matrix;
    m_C : out_matrix;
  END_VAR
  VAR
    i AT %QW0 : UINT := 0;
    j AT %QW1 : UINT := 0;
    k AT %QW2 : UINT := 0;
    n AT %QW3 : UINT := 2;
    index_A AT %QW4 : UINT;
    index_B AT %QW5 : UINT;
    index_C AT %QW6 : UINT;
    element_a AT %MD0 : DINT;
    element_b AT %MD1 : DINT;
    element_c AT %MD2 : DINT;
    check AT %MD3 : DINT;
    run_flag AT %IX0.0 : BOOL := true;
    run_status AT %IX0.1 : BOOL := false;
  END_VAR
  VAR
    element_selector0 : element_selector;
    element_selector1 : element_selector;
    element_selector2 : element_selector;
    element_selector3 : element_selector;
    mm_fb0 : mm_fb;
  END_VAR

  mm_fb0(m0 := m_A, m1 := m_B, m2 := m_C, n := 3);
  run_status := mm_fb0.finished;
  check := mm_fb0.check_sum;
  element_selector0(M := m_C, index := 0);
  element_selector1(M := m_C, index := 1);
  element_selector2(M := m_C, index := 2);
  element_selector3(M := m_C, index := 3);
END_PROGRAM

FUNCTION_BLOCK element_setter
  VAR_IN_OUT
    M : in_matrix;
  END_VAR
  VAR_INPUT
    index : UINT;
    value : DINT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR

  M[index] := value;
  out := M[index];
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION
