#include <stdio.h>

#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal num1 = {0};
  s21_decimal num2 = {0};
  s21_long_decimal num3 = {0};
  s21_long_decimal num4 = {0};
  int exp1 = 0;
  int exp2 = 0;
  int exp3 = 0;
  int exp4 = 0;
  char str1[len_str_max] = "-0.0000000000000000000000000001";
  char str2[len_str_max] = "-7922816251426433759354395032.5";
  char str3[len_str_max] = {0};
  char str4[len_str_max] = {0};
  s21_str_to_dec(&num1, str1);
  s21_str_to_dec(&num2, str2);
  __print_bit_decimal(&num1);
  __print_bit_decimal(&num2);
  exp1 = __get_exp(num1.bits[rank_exp_decimal]);
  exp2 = __get_exp(num2.bits[rank_exp_decimal]);
  printf("exp = %d\nexp = %d\n", exp1, exp2);
  __copy_decimal_to_long_decimal(&num1, &num3);
  __copy_decimal_to_long_decimal(&num2, &num4);
  __print_bit_long_decimal(&num3);
  __print_bit_long_decimal(&num4);
  exp3 = __get_exp(num3.bits[rank_exp_long_decimal]);
  exp4 = __get_exp(num4.bits[rank_exp_long_decimal]);
  printf("exp = %d\nexp = %d\n", exp3, exp4);
  s21_dec_to_str(&num1, str3);
  s21_dec_to_str(&num2, str4);
  s21_print_str(str3);
  s21_print_str(str4);
  int compare = __compare_sign_decimal(&num1, &num2);
  printf("%d\n", compare);
  return 0;
}