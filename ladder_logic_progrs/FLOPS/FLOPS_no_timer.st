PROGRAM FLOPS
  VAR
    count AT %MD0 : DINT := 0;
    product AT %MD1 : REAL := 1.0;
    run_flag AT %IX0.0 : BOOL := false;
  END_VAR
  VAR
    _TMP_MUL2_ENO : BOOL;
    _TMP_MUL2_OUT : REAL;
    _TMP_ADD7_ENO : BOOL;
    _TMP_ADD7_OUT : DINT;
    _TMP_GT12_ENO : BOOL;
    _TMP_GT12_OUT : BOOL;
    _TMP_MOVE15_ENO : BOOL;
    _TMP_MOVE15_OUT : REAL;
  END_VAR

  _TMP_MUL2_OUT := MUL(EN := run_flag, IN1 := product, IN2 := 5.0, ENO => _TMP_MUL2_ENO);
  IF _TMP_MUL2_ENO THEN
      product := _TMP_MUL2_OUT;
  END_IF;
  _TMP_ADD7_OUT := ADD(EN := _TMP_MUL2_ENO, IN1 := count, IN2 := 1, ENO => _TMP_ADD7_ENO);
  IF _TMP_ADD7_ENO THEN
      count := _TMP_ADD7_OUT;
  END_IF;
  _TMP_GT12_OUT := GT(EN := run_flag, IN1 := product, IN2 := 5000.0, ENO => _TMP_GT12_ENO);
  _TMP_MOVE15_OUT := MOVE(EN := _TMP_GT12_OUT, IN := 1.0, ENO => _TMP_MOVE15_ENO);
  IF _TMP_MOVE15_ENO THEN
      product := _TMP_MOVE15_OUT;
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#1ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : FLOPS;
  END_RESOURCE
END_CONFIGURATION

