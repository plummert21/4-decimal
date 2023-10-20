#ifndef S21_FUNC_STR_H
#define S21_FUNC_STR_H

#include "s21_decimal.h"

void s21_str_to_decimal(s21_decimal *num, char *str);
void s21_decimal_to_str(s21_decimal *num, char *str);
void s21_str_to_long_decimal(s21_long_decimal *num, char *str);
void s21_long_decimal_to_str(s21_long_decimal *num, char *str);
void s21_print_str(char *str);

void __div_str(char *str, size_t tmp_len);
void __del_zero(char *str);

void __init_str(char *str);
void __pow_2_to_str(char *str, int pow);
void __sum_strings_10(char *str1, char *str2, char *sum_str);
void __dot_incert_to_str(int exp, char *str);

#endif