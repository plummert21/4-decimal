#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  int compare = 0;
  s21_long_decimal long_value_1 = {0};
  s21_long_decimal long_value_2 = {0};
  s21_long_decimal long_result = {0};
  __pre_compare_module_long_decimal(&value_1, &value_2, &long_value_1,
                                    &long_value_2);
  compare = __compare_long_decimal(&long_value_1, &long_value_2);
  if (__get_bit(compare, compare_sign_bit)) {
    long_result.bits[rank_exp_long_decimal] =
        long_value_1.bits[rank_exp_long_decimal];
    __add_module_long_decimal(long_value_1, long_value_2, &long_result);
    err = __long_decimal_to_decimal(&long_result, result);
  } else {
    int sign_value_1 = __get_bit_decimal(&value_1, sign_bit_decimal);
    int sign_value_2 = __get_bit_decimal(&value_2, sign_bit_decimal);
    int sign_result = -1;
    __reset_bit_decimal(&value_1, sign_bit_decimal);
    __reset_bit_decimal(&value_2, sign_bit_decimal);
    if (s21_is_less(value_1, value_2)) {
      sign_result = sign_value_2;
    } else {
      sign_result = sign_value_1;
    }
    err = s21_sub(value_1, value_2, result);
    if (sign_result) {
      __set_bit_decimal(result, sign_bit_decimal);
    } else {
      __reset_bit_decimal(result, sign_bit_decimal);
    }
  }
  return err;
}