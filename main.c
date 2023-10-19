#include <stdio.h>

#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal val = {0};
  s21_long_decimal long_val = {0};
  int err = 0;
  char str[len_str_max] = "7.1";
  char long_str[len_str_max] = {0};

  s21_str_to_decimal(&val, str);
  s21_decimal_to_str(&val, str);
  __print_bit_decimal(&val);
  s21_print_str(str);

  __print_bit_long_decimal(&long_val);
  s21_str_to_long_decimal(&long_val, str);
  s21_long_decimal_to_str(&long_val, str);
  __print_bit_long_decimal(&long_val);
  s21_print_str(str);

  return 0;
}