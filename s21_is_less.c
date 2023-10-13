#include "s21_compare.h"
#include "s21_decimal.h"
#include "s21_func_bits.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = -1;
  int compare = __compare_decimal(&value_1, &value_2);
  if (compare == 7) {
    result = 0;
  } else if (!__get_bit(compare, compare_sign_bit)) {
    result = __get_bit_decimal(&value_1, sign_bit_decimal) ? 1 : 0;
  } else if (__get_bit(compare, compare_exp_bit)) {
    // знаки равны, экспоненты равны, сравниваем модули
    int i = 96;
    int bit_value_1 = 0;
    int bit_value_2 = 0;
    do {
      i--;
      bit_value_1 = __get_bit_decimal(&value_1, i);
      bit_value_2 = __get_bit_decimal(&value_2, i);
    } while ((bit_value_1 == bit_value_2) && (i != 0));
    result = bit_value_1 < bit_value_2 ? 1 : 0;
    if (__get_bit_decimal(&value_1, sign_bit_decimal)) result = !result;
  } else {
    // ToDo - знаки равны, экспоненты не равны. Нормализуем с переводом в лонг
    // децимал, сравниваем модули лонг_децимал.
    s21_long_decimal long_value_1 = {0};
    s21_long_decimal long_value_2 = {0};
    __pre_compare_module_long_decimal(&value_1, &value_2, &long_value_1,
                                      &long_value_2);
  }
  return result;
}