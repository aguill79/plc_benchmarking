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
    element_a : DINT;
    element_b : DINT;
    element_c : DINT;
  END_VAR
  VAR
    element_selector0 : matrix_one;
    element_selector1 : matrix_two;
    matrix_C0 : matrix_output;
  END_VAR
  VAR
    current_time : ULINT;
  END_VAR
  VAR
    start_time : DT;
    stop_time : DT;
  END_VAR
  VAR
    elapsed_time : LREAL;
  END_VAR
  VAR
    rec_time : BOOL := true;
    RTC0 : RTC;
    RTC1 : RTC;
    _TMP_MUL11_OUT : DINT;
    _TMP_DT_TO_LREAL30_OUT : LREAL;
    _TMP_DT_TO_LREAL21_OUT : LREAL;
    _TMP_SUB25_OUT : LREAL;
    _TMP_INT_TO_DT35_OUT : DT;
    _TMP_MOVE29_OUT : DT;
    _TMP_INT_TO_DT14_OUT : DT;
    _TMP_MOVE19_OUT : DT;
  END_VAR

  element_selector0(index := 0);
  element_a := element_selector0.out;
  element_selector1(index := 1);
  element_b := element_selector1.out;
  _TMP_MUL11_OUT := MUL(element_a, element_b);
  element_c := _TMP_MUL11_OUT;
  RTC0(EN := rec_time);
  IF RTC0.ENO THEN
      start_time := RTC0.CDT;
  END_IF;
  _TMP_DT_TO_LREAL30_OUT := DT_TO_LREAL(stop_time);
  _TMP_DT_TO_LREAL21_OUT := DT_TO_LREAL(start_time);
  _TMP_SUB25_OUT := SUB(_TMP_DT_TO_LREAL30_OUT, _TMP_DT_TO_LREAL21_OUT);
  elapsed_time := _TMP_SUB25_OUT;
  RTC1(EN := rec_time);
  IF RTC1.ENO THEN
      stop_time := RTC1.CDT;
  END_IF;
  _TMP_INT_TO_DT35_OUT := INT_TO_DT(0);
  _TMP_MOVE29_OUT := MOVE(_TMP_INT_TO_DT35_OUT);
  start_time := _TMP_MOVE29_OUT;
  _TMP_INT_TO_DT14_OUT := INT_TO_DT(0);
  _TMP_MOVE19_OUT := MOVE(_TMP_INT_TO_DT14_OUT);
  stop_time := _TMP_MOVE19_OUT;
  matrix_C0(index := 0, value := element_c);
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
