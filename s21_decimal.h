#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} s21_long_decimal;

#define max_decimal "79228162514264337593543950335"
#define min_decimal 1e-29
#define len_str_max 70
#define sign_bit_decimal 127
#define sign_bit_long_decimal 223
#define rank_exp_decimal 3
#define rank_exp_long_decimal 6
#define count_bits_module_decimal 96
#define count_bits_module_long_decimal 192

#include "s21_compare.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

// Арифметические операторы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Операторы сравнение
int s21_is_less(s21_decimal value_1, s21_decimal value_2);              // +
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);     // +
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);           // +
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);  // +
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);             // +
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);         // +

// Преобразователи
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Другие функции
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif
