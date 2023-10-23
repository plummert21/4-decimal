#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  int sign_value_1 = __get_bit_decimal(&value_1, sign_bit_decimal);
  int sign_value_2 = __get_bit_decimal(&value_2, sign_bit_decimal);
  int sign_result = -1;
  s21_long_decimal long_value_1 = {0};
  s21_long_decimal long_value_2 = {0};
  s21_long_decimal long_result = {0};
  // --1-- меняем знак value_2
  if (sign_value_2) {
    sign_value_2 = 0;
    __reset_bit_decimal(&value_2, sign_bit_decimal);
  } else {
    sign_value_2 = 1;
    __set_bit_decimal(&value_2, sign_bit_decimal);
  }
  // --1-- end
  if (sign_value_1 == sign_value_2) {
    err = s21_add(value_1, value_2, result);
  } else {
    __pre_compare_module_long_decimal(&value_1, &value_2, &long_value_1,
                                      &long_value_2);
    __reset_bit_decimal(&value_1, sign_bit_decimal);
    __reset_bit_decimal(&value_2, sign_bit_decimal);
    // if (s21_is_equal(value_1, value_2)) {
    //   for (int i = 0; i < rank_exp_decimal; i++) result->bits[i] = 0;
    // }
    if (s21_is_less(value_1, value_2)) {
      int tmp = 0;
      for (int i = 0; i <= rank_exp_long_decimal; i++) {
        tmp = long_value_1.bits[i];
        long_value_1.bits[i] = long_value_2.bits[i];
        long_value_2.bits[i] = tmp;
      }
      sign_result =
          __get_bit_long_decimal(&long_value_2, sign_bit_long_decimal);
    } else {
      sign_result =
          __get_bit_long_decimal(&long_value_1, sign_bit_long_decimal);
    }
    long_result.bits[rank_exp_long_decimal] =
        long_value_1.bits[rank_exp_long_decimal];
    __sub_module_long_decimal(long_value_1, long_value_2, &long_result);
    err = __long_decimal_to_decimal(&long_result, result);
  }
  return err;
}