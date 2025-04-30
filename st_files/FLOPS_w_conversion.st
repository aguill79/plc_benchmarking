PROGRAM FLOPS
  VAR
    product AT %MD0 : REAL := 1.0;
    count AT %QW0 : INT := 0;
    num_ops AT %QW1 : INT := 200;
    converted_result AT %QW2 : INT := 200;
    run_flag AT %IX0.0 : BOOL := false;
    reset AT %QX0.1 : BOOL := true;
    run_status AT %QX0.0 : BOOL := false;
  END_VAR
  VAR
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
    _TMP_MUL2_ENO : BOOL;
    _TMP_MUL2_OUT : REAL;
    _TMP_REAL_TO_INT34_OUT : INT;
  END_VAR

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
  _TMP_MUL2_OUT := MUL(EN := run_flag, IN1 := product, IN2 := 5.0, ENO => _TMP_MUL2_ENO);
  run_status := _TMP_MUL2_ENO;
  IF _TMP_LE18_OUT THEN
    run_status := FALSE; (*reset*)
  END_IF;
  IF _TMP_MUL2_ENO THEN
      product := _TMP_MUL2_OUT;
  END_IF;
  _TMP_REAL_TO_INT34_OUT := REAL_TO_INT(product);
  converted_result := _TMP_REAL_TO_INT34_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#5ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : FLOPS;
  END_RESOURCE
END_CONFIGURATION

(*DBG:char md5[] = "2374d24125fafb65912b58201b18b5c2";*)
(*DBG:/**)
(*DBG: * This file is part of OpenPLC Runtime*)
(*DBG: **)
(*DBG: * Copyright (C) 2023 Autonomy, GP Orcullo*)
(*DBG: * Based on the work by GP Orcullo on Beremiz for uC*)
(*DBG: **)
(*DBG: * This program is free software; you can redistribute it and/or*)
(*DBG: * modify it under the terms of the GNU General Public License*)
(*DBG: * as published by the Free Software Foundation; either version 2*)
(*DBG: * of the License, or (at your option) any later version.*)
(*DBG: **)
(*DBG: * This program is distributed in the hope that it will be useful,*)
(*DBG: * but WITHOUT ANY WARRANTY; without even the implied warranty of*)
(*DBG: * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*)
(*DBG: * GNU General Public License for more details.*)
(*DBG: **)
(*DBG: * You should have received a copy of the GNU General Public License*)
(*DBG: * along with this program; If not, see <http://www.gnu.org/licenses/>.*)
(*DBG: **)
(*DBG: */*)
(*DBG:*)
(*DBG:#include <stdbool.h>*)
(*DBG:*)
(*DBG:#include "iec_types_all.h"*)
(*DBG:#include "POUS.h"*)
(*DBG:*)
(*DBG:#define SAME_ENDIANNESS      0*)
(*DBG:#define REVERSE_ENDIANNESS   1*)
(*DBG:*)
(*DBG:uint8_t endianness;*)
(*DBG:*)
(*DBG:*)
(*DBG:extern FLOPS RES0__INSTANCE0;*)
(*DBG:*)
(*DBG:static const struct {*)
(*DBG:    void *ptr;*)
(*DBG:    __IEC_types_enum type;*)
(*DBG:} debug_vars[] = {*)
(*DBG:    {&(RES0__INSTANCE0.PRODUCT), REAL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.COUNT), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.NUM_OPS), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.CONVERTED_RESULT), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.RUN_FLAG), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.RESET), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.RUN_STATUS), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_SUB7_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_SUB7_OUT), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_GT12_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_GT12_OUT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE15_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE15_OUT), REAL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_LE18_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_LE18_OUT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE28_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE28_OUT), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MUL2_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MUL2_OUT), REAL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_REAL_TO_INT34_OUT), INT_ENUM},*)
(*DBG:};*)
(*DBG:*)
(*DBG:#define VAR_COUNT               20*)
(*DBG:*)
(*DBG:uint16_t get_var_count(void)*)
(*DBG:{*)
(*DBG:    return VAR_COUNT;*)
(*DBG:}*)
(*DBG:*)
(*DBG:size_t get_var_size(size_t idx)*)
(*DBG:{*)
(*DBG:    if (idx >= VAR_COUNT)*)
(*DBG:    {*)
(*DBG:        return 0;*)
(*DBG:    }*)
(*DBG:    switch (debug_vars[idx].type) {*)
(*DBG:    case BOOL_ENUM:*)
(*DBG:        return sizeof(BOOL);*)
(*DBG:    case REAL_ENUM:*)
(*DBG:        return sizeof(REAL);*)
(*DBG:    case INT_ENUM:*)
(*DBG:        return sizeof(INT);*)
(*DBG:    default:*)
(*DBG:        return 0;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void *get_var_addr(size_t idx)*)
(*DBG:{*)
(*DBG:    void *ptr = debug_vars[idx].ptr;*)
(*DBG:*)
(*DBG:    switch (debug_vars[idx].type) {*)
(*DBG:    case BOOL_ENUM:*)
(*DBG:        return (void *)&((__IEC_BOOL_t *) ptr)->value;*)
(*DBG:    case REAL_ENUM:*)
(*DBG:        return (void *)&((__IEC_REAL_t *) ptr)->value;*)
(*DBG:    case INT_ENUM:*)
(*DBG:        return (void *)&((__IEC_INT_t *) ptr)->value;*)
(*DBG:    default:*)
(*DBG:        return 0;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void force_var(size_t idx, bool forced, void *val)*)
(*DBG:{*)
(*DBG:    void *ptr = debug_vars[idx].ptr;*)
(*DBG:*)
(*DBG:    if (forced) {*)
(*DBG:        size_t var_size = get_var_size(idx);*)
(*DBG:        switch (debug_vars[idx].type) {*)
(*DBG:        case BOOL_ENUM: {*)
(*DBG:            memcpy(&((__IEC_BOOL_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_BOOL_t *) ptr)->value = *((BOOL *) val);*)
(*DBG:            ((__IEC_BOOL_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case REAL_ENUM: {*)
(*DBG:            memcpy(&((__IEC_REAL_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_REAL_t *) ptr)->value = *((REAL *) val);*)
(*DBG:            ((__IEC_REAL_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case INT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_INT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_INT_t *) ptr)->value = *((INT *) val);*)
(*DBG:            ((__IEC_INT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        default:*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:    } else {*)
(*DBG:        switch (debug_vars[idx].type) {*)
(*DBG:        case BOOL_ENUM:*)
(*DBG:            ((__IEC_BOOL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case REAL_ENUM:*)
(*DBG:            ((__IEC_REAL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case INT_ENUM:*)
(*DBG:            ((__IEC_INT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        default:*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void swap_bytes(void *ptr, size_t size) *)
(*DBG:{*)
(*DBG:    uint8_t *bytePtr = (uint8_t *)ptr;*)
(*DBG:    size_t i;*)
(*DBG:    for (i = 0; i < size / 2; ++i) *)
(*DBG:    {*)
(*DBG:        uint8_t temp = bytePtr[i];*)
(*DBG:        bytePtr[i] = bytePtr[size - 1 - i];*)
(*DBG:        bytePtr[size - 1 - i] = temp;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void trace_reset(void)*)
(*DBG:{*)
(*DBG:    for (size_t i=0; i < VAR_COUNT; i++) *)
(*DBG:    {*)
(*DBG:        force_var(i, false, 0);*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void set_trace(size_t idx, bool forced, void *val)*)
(*DBG:{*)
(*DBG:    if (idx >= 0 && idx < VAR_COUNT) *)
(*DBG:    {*)
(*DBG:        if (endianness == REVERSE_ENDIANNESS)*)
(*DBG:        {*)
(*DBG:            // Aaaaarghhhh... Stupid AVR is Big Endian.*)
(*DBG:            swap_bytes(val, get_var_size(idx));*)
(*DBG:        }*)
(*DBG:*)
(*DBG:        force_var(idx, forced, val);*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void set_endianness(uint8_t value)*)
(*DBG:{*)
(*DBG:    if (value == SAME_ENDIANNESS || value == REVERSE_ENDIANNESS)*)
(*DBG:    {*)
(*DBG:        endianness = value;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)