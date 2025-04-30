TYPE
  matrix : ARRAY [0..3] OF DINT := [1, 2, 3, 4];
END_TYPE

FUNCTION_BLOCK element_selector
  VAR_INPUT
    M : matrix;
    index : UINT;
  END_VAR
  VAR_OUTPUT
    out : DINT;
  END_VAR

  out := M[index];
END_FUNCTION_BLOCK

FUNCTION_BLOCK element_setter
  VAR_IN_OUT
    M : matrix;
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

PROGRAM matrix_mul
  VAR
    m_A : matrix := [1, 2, 3, 4];
    m_B : matrix := [1, 2, 3, 4];
    m_C : matrix;
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
  END_VAR
  VAR
    input_matrices0 : element_selector;
    input_matrices1 : element_selector;
    element_setter0 : element_setter;
    element_selector0 : element_selector;
    element_selector1 : element_selector;
    element_selector2 : element_selector;
    element_selector3 : element_selector;
    _TMP_GE48_ENO : BOOL;
    _TMP_GE48_OUT : BOOL;
    _TMP_MUL43_ENO : BOOL;
    _TMP_MUL43_OUT : UINT;
    _TMP_ADD42_ENO : BOOL;
    _TMP_ADD42_OUT : UINT;
    _TMP_MUL6_ENO : BOOL;
    _TMP_MUL6_OUT : UINT;
    _TMP_ADD5_ENO : BOOL;
    _TMP_ADD5_OUT : UINT;
    _TMP_MUL19_ENO : BOOL;
    _TMP_MUL19_OUT : UINT;
    _TMP_ADD18_ENO : BOOL;
    _TMP_ADD18_OUT : UINT;
    _TMP_ADD46_ENO : BOOL;
    _TMP_ADD46_OUT : UINT;
    _TMP_MOVE49_ENO : BOOL;
    _TMP_MOVE49_OUT : UINT;
    _TMP_ADD30_ENO : BOOL;
    _TMP_ADD30_OUT : UINT;
    _TMP_GE34_ENO : BOOL;
    _TMP_GE34_OUT : BOOL;
    _TMP_MOVE40_ENO : BOOL;
    _TMP_MOVE40_OUT : UINT;
    _TMP_ADD58_ENO : BOOL;
    _TMP_ADD58_OUT : UINT;
    _TMP_GE52_ENO : BOOL;
    _TMP_GE52_OUT : BOOL;
    _TMP_MUL68_ENO : BOOL;
    _TMP_MUL68_OUT : DINT;
    _TMP_ADD69_ENO : BOOL;
    _TMP_ADD69_OUT : DINT;
    _TMP_MOVE71_ENO : BOOL;
    _TMP_MOVE71_OUT : DINT;
  END_VAR

  input_matrices0(M := m_A, index := index_A);
  element_a := input_matrices0.out;
  input_matrices1(M := m_B, index := index_B);
  element_b := input_matrices1.out;
  _TMP_GE48_OUT := GE(EN := run_flag, IN1 := k, IN2 := n, ENO => _TMP_GE48_ENO);
  element_setter0(EN := _TMP_GE48_OUT, M := m_C, index := index_C, value := element_c);
  IF element_setter0.ENO THEN
      check := element_setter0.out;
  END_IF;
  _TMP_MUL43_OUT := MUL(EN := run_flag, IN1 := i, IN2 := n, ENO => _TMP_MUL43_ENO);
  _TMP_ADD42_OUT := ADD(EN := _TMP_MUL43_ENO, IN1 := _TMP_MUL43_OUT, IN2 := k, ENO => _TMP_ADD42_ENO);
  IF _TMP_ADD42_ENO THEN
      index_A := _TMP_ADD42_OUT;
  END_IF;
  _TMP_MUL6_OUT := MUL(EN := run_flag, IN1 := k, IN2 := n, ENO => _TMP_MUL6_ENO);
  _TMP_ADD5_OUT := ADD(IN1 := _TMP_MUL6_OUT, IN2 := j, ENO => _TMP_ADD5_ENO);
  index_B := _TMP_ADD5_OUT;
  _TMP_MUL19_OUT := MUL(EN := run_flag, IN1 := i, IN2 := n, ENO => _TMP_MUL19_ENO);
  _TMP_ADD18_OUT := ADD(EN := _TMP_MUL19_ENO, IN1 := _TMP_MUL19_OUT, IN2 := j, ENO => _TMP_ADD18_ENO);
  IF _TMP_ADD18_ENO THEN
      index_C := _TMP_ADD18_OUT;
  END_IF;
  _TMP_ADD46_OUT := ADD(EN := run_flag, IN1 := k, IN2 := 1, ENO => _TMP_ADD46_ENO);
  IF _TMP_ADD46_ENO THEN
      k := _TMP_ADD46_OUT;
  END_IF;
  _TMP_MOVE49_OUT := MOVE(EN := _TMP_GE48_OUT, IN := 0, ENO => _TMP_MOVE49_ENO);
  IF _TMP_MOVE49_ENO THEN
      k := _TMP_MOVE49_OUT;
  END_IF;
  _TMP_ADD30_OUT := ADD(EN := _TMP_MOVE49_ENO, IN1 := j, IN2 := 1, ENO => _TMP_ADD30_ENO);
  IF _TMP_ADD30_ENO THEN
      j := _TMP_ADD30_OUT;
  END_IF;
  _TMP_GE34_OUT := GE(EN := run_flag, IN1 := j, IN2 := n, ENO => _TMP_GE34_ENO);
  _TMP_MOVE40_OUT := MOVE(EN := _TMP_GE34_OUT, IN := 0, ENO => _TMP_MOVE40_ENO);
  IF _TMP_MOVE40_ENO THEN
      j := _TMP_MOVE40_OUT;
  END_IF;
  _TMP_ADD58_OUT := ADD(EN := _TMP_MOVE40_ENO, IN1 := i, IN2 := 1, ENO => _TMP_ADD58_ENO);
  IF _TMP_ADD58_ENO THEN
      i := _TMP_ADD58_OUT;
  END_IF;
  _TMP_GE52_OUT := GE(EN := run_flag, IN1 := i, IN2 := n, ENO => _TMP_GE52_ENO);
  IF _TMP_GE52_OUT THEN
    run_flag := FALSE; (*reset*)
  END_IF;
  _TMP_MUL68_OUT := MUL(EN := run_flag, IN1 := element_a, IN2 := element_b, ENO => _TMP_MUL68_ENO);
  _TMP_ADD69_OUT := ADD(EN := _TMP_MUL68_ENO, IN1 := _TMP_MUL68_OUT, IN2 := element_c, ENO => _TMP_ADD69_ENO);
  IF _TMP_ADD69_ENO THEN
      element_c := _TMP_ADD69_OUT;
  END_IF;
  _TMP_MOVE71_OUT := MOVE(EN := element_setter0.ENO, IN := 0, ENO => _TMP_MOVE71_ENO);
  IF _TMP_MOVE71_ENO THEN
      element_c := _TMP_MOVE71_OUT;
  END_IF;
  element_selector0(M := m_C, index := 0);
  element_selector1(M := m_C, index := 1);
  element_selector2(M := m_C, index := 2);
  element_selector3(M := m_C, index := 3);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#3s,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION
