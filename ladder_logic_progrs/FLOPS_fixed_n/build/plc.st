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


PROGRAM FLOPS
  VAR
    count : DINT := 0;
    num_ops : DINT := 200;
    product : REAL := 1.0;
    run_flag : BOOL := true;
    reset : BOOL := true;
    run_status : BOOL := false;
  END_VAR
  VAR
    start_time : DT;
    stop_time : DT;
    elapsed_time : LREAL;
    record_time : BOOL := true;
    RTC0 : RTC;
    RTC1 : RTC;
    _TMP_MUL2_ENO : BOOL;
    _TMP_MUL2_OUT : REAL;
    _TMP_SUB7_ENO : BOOL;
    _TMP_SUB7_OUT : DINT;
    _TMP_GT12_ENO : BOOL;
    _TMP_GT12_OUT : BOOL;
    _TMP_MOVE15_ENO : BOOL;
    _TMP_MOVE15_OUT : REAL;
    _TMP_LE18_ENO : BOOL;
    _TMP_LE18_OUT : BOOL;
    _TMP_MOVE28_ENO : BOOL;
    _TMP_MOVE28_OUT : DINT;
    _TMP_DT_TO_LREAL37_OUT : LREAL;
    _TMP_DT_TO_LREAL39_OUT : LREAL;
    _TMP_SUB36_OUT : LREAL;
    _TMP_MOVE42_ENO : BOOL;
    _TMP_MOVE42_OUT : BOOL;
  END_VAR

  _TMP_MUL2_OUT := MUL(EN := run_flag, IN1 := product, IN2 := 5.0, ENO => _TMP_MUL2_ENO);
  IF _TMP_MUL2_ENO THEN
      product := _TMP_MUL2_OUT;
  END_IF;
  _TMP_SUB7_OUT := SUB(EN := _TMP_MUL2_ENO, IN1 := count, IN2 := 1, ENO => _TMP_SUB7_ENO);
  IF _TMP_SUB7_ENO THEN
      count := _TMP_SUB7_OUT;
  END_IF;
  _TMP_GT12_OUT := GT(EN := run_flag, IN1 := product, IN2 := 5000.0, ENO => _TMP_GT12_ENO);
  _TMP_MOVE15_OUT := MOVE(EN := _TMP_GT12_OUT, IN := 1.0, ENO => _TMP_MOVE15_ENO);
  IF _TMP_MOVE15_ENO THEN
      product := _TMP_MOVE15_OUT;
  END_IF;
  _TMP_LE18_OUT := LE(EN := run_flag, IN1 := count, IN2 := 0, ENO => _TMP_LE18_ENO);
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
  run_status := _TMP_SUB7_ENO;
  IF _TMP_LE18_OUT THEN
    run_status := FALSE; (*reset*)
  END_IF;
  RTC0(EN := record_time AND run_flag);
  IF RTC0.ENO THEN
      start_time := RTC0.CDT;
  END_IF;
  RTC1(EN := record_time AND run_flag);
  IF RTC1.ENO THEN
      stop_time := RTC1.CDT;
  END_IF;
  _TMP_DT_TO_LREAL37_OUT := DT_TO_LREAL(stop_time);
  _TMP_DT_TO_LREAL39_OUT := DT_TO_LREAL(start_time);
  _TMP_SUB36_OUT := SUB(_TMP_DT_TO_LREAL37_OUT, _TMP_DT_TO_LREAL39_OUT);
  elapsed_time := _TMP_SUB36_OUT;
  _TMP_MOVE42_OUT := MOVE(EN := run_flag, IN := false, ENO => _TMP_MOVE42_ENO);
  IF _TMP_MOVE42_ENO THEN
      record_time := _TMP_MOVE42_OUT;
  END_IF;
  IF _TMP_MOVE28_ENO THEN
    record_time := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : FLOPS;
  END_RESOURCE
END_CONFIGURATION
