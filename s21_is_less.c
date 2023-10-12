#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = -1;
  int compare = __compare_decimal(&value_1, &value_2);
  if (compare == 7) {
    result = 0;
  } else if (!__get_bit(compare, compare_sign_bit)) {
    // int sign_bit_value_1 = __get_bit_decimal(&value_1, sign_bit_decimal);
    // int sign_bit_value_2 = __get_bit_decimal(&value_2, sign_bit_decimal);
    // result = sign_bit_value_1 > sign_bit_value_2 ? 1 : 0;
    result = __get_bit_decimal(&value_1, sign_bit_decimal) ? 1 : 0;
  } else if (__get_bit(compare, compare_exp_bit)) {
    // ToDo - знаки равны, экспоненты равны, сравниваем модули (не забыть про
    // положительные и отрицаельные числа)
  } else {
    // ToDo - знаки равны, экспоненты не равны. Переводим в лонг-децимал,
    // нормализуем, сравниваем модули лонг_децимал.
  }
  return result;
}