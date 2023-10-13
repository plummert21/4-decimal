#include <stdio.h>

#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal num1 = {0};
  s21_decimal num2 = {0};
  s21_decimal res = {0};
  int err = 0;
  char str1[len_str_max] = "-5.89765958854";
  char str2[len_str_max] = "-7.01";
  char res_str[len_str_max] = {0};
  s21_str_to_decimal(&num1, str1);
  s21_str_to_decimal(&num2, str2);
  err = s21_add(num1, num2, &res);
  __print_bit_decimal(&res);
  s21_decimal_to_str(&res, res_str);
  s21_print_str(res_str);
  printf("%d\n", err);
  return 0;
}