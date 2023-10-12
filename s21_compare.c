#include "s21_compare.h"

int __compare_sign_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // return 0 - false, 4 - true
  int result = 0;
  int sign_value_1 = __get_bit_decimal(value_1, sign_bit_decimal);
  int sign_value_2 = __get_bit_decimal(value_2, sign_bit_decimal);
  if (sign_value_1 == sign_value_2) {
    result = 4;
  }
  return result;
}

int __compare_exp_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // return 0 - false, 2 - true
  return 0;
}

int __compare_module_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // return 0 - false, 1 - true
  return 0;
}

int __compare_sign_long_decimal(s21_long_decimal *value_1,
                                s21_long_decimal *value_2) {
  // return 0 - false, 4 - true
  return 0;
}

int __compare_exp_long_decimal(s21_long_decimal *value_1,
                               s21_long_decimal *value_2) {
  // return 0 - false, 2 - true
  return 0;
}

int __compare_module_long_decimal(s21_long_decimal *value_1,
                                  s21_long_decimal *value_2) {
  // return 0 - false, 1 - true
  return 0;
}