#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  int sign_value_1 = __get_bit_decimal(&value_1, sign_bit_decimal);
  int sign_value_2 = __get_bit_decimal(&value_2, sign_bit_decimal);
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
    // --------------------    ToDo ------------------------- разность
  }
  return err;
}