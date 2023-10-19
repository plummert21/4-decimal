#include <stdio.h>

#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_decimal res = {0};
  int err = 0;
  char str1[len_str_max] = "79228162514264337593543950335";
  char str2[len_str_max] = "0.1";
  char str_res[len_str_max] = {0};

  s21_str_to_decimal(&val1, str1);
  s21_str_to_decimal(&val2, str2);

  err = s21_add(val1, val2, &res);
  s21_decimal_to_str(&res, str_res);
  s21_print_str(str_res);
  printf("err=%d\n", err);
  return 0;
}