#include <stdio.h>

#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"
#include "s21_func_str.h"

int main() {
  s21_decimal num1 = {0};
  s21_decimal num2 = {0};
  char str1[len_str_max] = "5.1";
  char str2[len_str_max] = "5";
  s21_str_to_decimal(&num1, str1);
  s21_str_to_decimal(&num2, str2);
  int greater = s21_is_greater(num1, num2);
  printf("%d\n", greater);
  return 0;
}