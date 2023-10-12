#include "s21_decimal.h"
#include "s21_func_bits.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 2;
  int sign_value_1 = __get_bit_decimal(&value_1, sign_bit_decimal);
  int sign_value_2 = __get_bit_decimal(&value_2, sign_bit_decimal);
  if (sign_value_1 == sign_value_2) {
    // ToDo - перевод в long_decimal
    // ToDo - нормализация long_decimal
    // ToDo - сравнение модулей long_decimal
  } else {
    result = sign_value_1 > sign_value_2 ? 1 : 0;
  }
  return result;
}