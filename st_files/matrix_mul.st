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

FUNCTION_BLOCK mm_fb
  VAR_IN_OUT
    m0 : matrix;
    m1 : matrix;
    m2 : matrix;
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
    run_status AT %IX0.1 : BOOL := false;
  END_VAR
  VAR
    element_selector0 : element_selector;
    element_selector1 : element_selector;
    element_selector2 : element_selector;
    element_selector3 : element_selector;
    mm_fb0 : mm_fb;
  END_VAR

  mm_fb0(m0 := m_A, m1 := m_B, m2 := m_C, n := 2);
  run_status := mm_fb0.finished;
  check := mm_fb0.check_sum;
  element_selector0(M := m_C, index := 0);
  element_selector1(M := m_C, index := 1);
  element_selector2(M := m_C, index := 2);
  element_selector3(M := m_C, index := 3);
END_PROGRAM

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


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : matrix_mul;
  END_RESOURCE
END_CONFIGURATION

(*DBG:char md5[] = "ac85ffeed9f26d372ca4a7d68c9b6953";*)
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
(*DBG:extern MATRIX_MUL RES0__INSTANCE0;*)
(*DBG:*)
(*DBG:static const struct {*)
(*DBG:    void *ptr;*)
(*DBG:    __IEC_types_enum type;*)
(*DBG:} debug_vars[] = {*)
(*DBG:    {&(RES0__INSTANCE0.I), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.J), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.K), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.N), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INDEX_A), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INDEX_B), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INDEX_C), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_A), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_B), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_C), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.CHECK), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.RUN_FLAG), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.RUN_STATUS), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR0.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR0.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR0.INDEX), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR0.OUT), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR1.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR1.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR1.INDEX), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR1.OUT), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR2.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR2.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR2.INDEX), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR2.OUT), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR3.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR3.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR3.INDEX), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_SELECTOR3.OUT), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.I), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.J), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.K), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.SUM), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.CHECK_SUM), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.N), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.MM_FB0.FINISHED), BOOL_ENUM},*)
(*DBG:};*)
(*DBG:*)
(*DBG:#define VAR_COUNT               38*)
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
(*DBG:    case INT_ENUM:*)
(*DBG:        return sizeof(INT);*)
(*DBG:    case DINT_ENUM:*)
(*DBG:        return sizeof(DINT);*)
(*DBG:    case BOOL_ENUM:*)
(*DBG:        return sizeof(BOOL);*)
(*DBG:    case UINT_ENUM:*)
(*DBG:        return sizeof(UINT);*)
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
(*DBG:    case INT_ENUM:*)
(*DBG:        return (void *)&((__IEC_INT_t *) ptr)->value;*)
(*DBG:    case DINT_ENUM:*)
(*DBG:        return (void *)&((__IEC_DINT_t *) ptr)->value;*)
(*DBG:    case BOOL_ENUM:*)
(*DBG:        return (void *)&((__IEC_BOOL_t *) ptr)->value;*)
(*DBG:    case UINT_ENUM:*)
(*DBG:        return (void *)&((__IEC_UINT_t *) ptr)->value;*)
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
(*DBG:        case INT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_INT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_INT_t *) ptr)->value = *((INT *) val);*)
(*DBG:            ((__IEC_INT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case DINT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_DINT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_DINT_t *) ptr)->value = *((DINT *) val);*)
(*DBG:            ((__IEC_DINT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case BOOL_ENUM: {*)
(*DBG:            memcpy(&((__IEC_BOOL_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_BOOL_t *) ptr)->value = *((BOOL *) val);*)
(*DBG:            ((__IEC_BOOL_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case UINT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_UINT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_UINT_t *) ptr)->value = *((UINT *) val);*)
(*DBG:            ((__IEC_UINT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        default:*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:    } else {*)
(*DBG:        switch (debug_vars[idx].type) {*)
(*DBG:        case INT_ENUM:*)
(*DBG:            ((__IEC_INT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case DINT_ENUM:*)
(*DBG:            ((__IEC_DINT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case BOOL_ENUM:*)
(*DBG:            ((__IEC_BOOL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case UINT_ENUM:*)
(*DBG:            ((__IEC_UINT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
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