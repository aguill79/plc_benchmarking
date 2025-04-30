PROGRAM FLOPS
  VAR
    product AT %MD0 : REAL := 1.0;
    count AT %QW0 : INT := 0;
    num_ops AT %QW1 : INT := 200;
    run_flag AT %IX0.0 : BOOL := false;
    reset AT %QX0.1 : BOOL := true;
    run_status AT %QX0.0 : BOOL := false;
  END_VAR
  VAR
    _TMP_MUL2_ENO : BOOL;
    _TMP_MUL2_OUT : REAL;
    _TMP_SUB7_ENO : BOOL;
    _TMP_SUB7_OUT : INT;
    _TMP_GT12_ENO : BOOL;
    _TMP_GT12_OUT : BOOL;
    _TMP_MOVE15_ENO : BOOL;
    _TMP_MOVE15_OUT : REAL;
    _TMP_LE18_ENO : BOOL;
    _TMP_LE18_OUT : BOOL;
    _TMP_MOVE28_ENO : BOOL;
    _TMP_MOVE28_OUT : INT;
  END_VAR

  _TMP_MUL2_OUT := MUL(EN := run_flag, IN1 := product, IN2 := 5.0, ENO => _TMP_MUL2_ENO);
  IF _TMP_MUL2_ENO THEN
      product := _TMP_MUL2_OUT;
  END_IF;
  _TMP_SUB7_OUT := SUB(EN := run_flag, IN1 := count, IN2 := 1, ENO => _TMP_SUB7_ENO);
  IF _TMP_SUB7_ENO THEN
      count := _TMP_SUB7_OUT;
  END_IF;
  _TMP_GT12_OUT := GT(EN := run_flag, IN1 := product, IN2 := 5000.0, ENO => _TMP_GT12_ENO);
  _TMP_MOVE15_OUT := MOVE(EN := _TMP_GT12_OUT, IN := 1.0, ENO => _TMP_MOVE15_ENO);
  IF _TMP_MOVE15_ENO THEN
      product := _TMP_MOVE15_OUT;
  END_IF;
  _TMP_LE18_OUT := LE(EN := run_flag, IN1 := count, IN2 := 1, ENO => _TMP_LE18_ENO);
  IF _TMP_LE18_OUT THEN
    run_flag := FALSE; (*reset*)
  END_IF;
  _TMP_MOVE28_OUT := MOVE(EN := NOT(run_flag) AND reset, IN := num_ops, ENO => _TMP_MOVE28_ENO);
  IF _TMP_MOVE28_ENO THEN
      count := _TMP_MOVE28_OUT;
  END_IF;
  IF _TMP_MOVE28_ENO THEN
    reset := FALSE; (*reset*)
  END_IF;
  run_status := _TMP_MUL2_ENO;
  IF _TMP_LE18_OUT THEN
    run_status := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#5ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : FLOPS;
  END_RESOURCE
END_CONFIGURATION
