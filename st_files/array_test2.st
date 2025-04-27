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
    m_A AT %MW0 : input_matrix;
  END_VAR
  VAR
    m_B : input_matrix;
    m_C : output_matrix;
  END_VAR
  VAR
    element_a AT %QD0 : INT;
    element_b AT %QD1 : INT;
    element_c AT %QD2 : DINT;
    current_time AT %ML1024 : ULINT;
  END_VAR
  VAR
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
  element_a := input_matrices0.out2;
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

(*DBG:char md5[] = "f3a115eda6fc5796fd2c1878e15952cf";*)
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
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_A), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_B), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELEMENT_C), DINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.CURRENT_TIME), ULINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.START_TIME), DT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.STOP_TIME), DT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ELAPSED_TIME), LREAL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.REC_TIME), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INPUT_MATRICES0.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INPUT_MATRICES0.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INPUT_MATRICES0.INDEX1), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INPUT_MATRICES0.INDEX2), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INPUT_MATRICES0.OUT1), INT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.INPUT_MATRICES0.OUT2), INT_ENUM},*)
(*DBG:};*)
(*DBG:*)
(*DBG:#define VAR_COUNT               14*)
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
(*DBG:    case DT_ENUM:*)
(*DBG:        return sizeof(DT);*)
(*DBG:    case ULINT_ENUM:*)
(*DBG:        return sizeof(ULINT);*)
(*DBG:    case LREAL_ENUM:*)
(*DBG:        return sizeof(LREAL);*)
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
(*DBG:    case DT_ENUM:*)
(*DBG:        return (void *)&((__IEC_DT_t *) ptr)->value;*)
(*DBG:    case ULINT_ENUM:*)
(*DBG:        return (void *)&((__IEC_ULINT_t *) ptr)->value;*)
(*DBG:    case LREAL_ENUM:*)
(*DBG:        return (void *)&((__IEC_LREAL_t *) ptr)->value;*)
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
(*DBG:        case DT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_DT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_DT_t *) ptr)->value = *((DT *) val);*)
(*DBG:            ((__IEC_DT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case ULINT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_ULINT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_ULINT_t *) ptr)->value = *((ULINT *) val);*)
(*DBG:            ((__IEC_ULINT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case LREAL_ENUM: {*)
(*DBG:            memcpy(&((__IEC_LREAL_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_LREAL_t *) ptr)->value = *((LREAL *) val);*)
(*DBG:            ((__IEC_LREAL_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
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
(*DBG:        case DT_ENUM:*)
(*DBG:            ((__IEC_DT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case ULINT_ENUM:*)
(*DBG:            ((__IEC_ULINT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case LREAL_ENUM:*)
(*DBG:            ((__IEC_LREAL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
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