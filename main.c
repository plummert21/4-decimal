#include <stdio.h>

#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal num1 = {0};
  s21_decimal num2 = {0};
  s21_long_decimal num3 = {0};
  s21_long_decimal num4 = {0};
  char str1[len_str_max] = "-0.0000000000000000000000000001";
  char str2[len_str_max] = "-7922816251426433759354395032.5";
  char str3[len_str_max] = {0};
  char str4[len_str_max] = {0};
  s21_str_to_dec(&num1, str1);
  s21_str_to_dec(&num2, str2);
  __print_bit_decimal(&num1);
  __print_bit_decimal(&num2);
  __copy_decimal_to_long_decimal(&num1, &num3);
  __copy_decimal_to_long_decimal(&num2, &num4);
  __print_bit_long_decimal(&num3);
  __print_bit_long_decimal(&num4);
  s21_dec_to_str(&num1, str3);
  s21_dec_to_str(&num2, str4);
  s21_print_str(str3);
  s21_print_str(str4);
  return 0;
}