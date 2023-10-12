#ifndef S21_COMPARE
#define S21_COMPARE

#include "s21_decimal.h"
#include "s21_func_bits.h"

#define compare_sign_bit 2
#define compare_exp_bit 1
#define compare_module_bit 0

// ToDo - Generic

int __compare_sign_decimal(s21_decimal *value_1, s21_decimal *value_2);
int __compare_exp_decimal(s21_decimal *value_1, s21_decimal *value_2);
int __compare_module_decimal(s21_decimal *value_1, s21_decimal *value_2);

int __compare_sign_long_decimal(s21_long_decimal *value_1,
                                s21_long_decimal *value_2);
int __compare_exp_long_decimal(s21_long_decimal *value_1,
                               s21_long_decimal *value_2);
int __compare_module_long_decimal(s21_long_decimal *value_1,
                                  s21_long_decimal *value_2);

#endif