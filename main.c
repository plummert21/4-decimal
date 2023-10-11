#include <stdio.h>

#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal num1 = {0};
  s21_decimal num2 = {0};
  char str1[len_str_max] = "-5.13";
  char str2[len_str_max] = "-600.33";
  char str3[len_str_max] = {0};
  char str4[len_str_max] = {0};
  s21_str_to_dec(&num1, str1);
  s21_str_to_dec(&num2, str2);
  __print_bit_decimal(&num1);
  __print_bit_decimal(&num2);
  s21_dec_to_str(&num1, str3);
  s21_dec_to_str(&num2, str4);
  s21_print_str(str3);
  s21_print_str(str4);
  return 0;
}