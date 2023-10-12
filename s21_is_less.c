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
    // ToDo - знаки равны, экспоненты равны, сравниваем модули (не забыть про
    // положительные и отрицаельные числа)
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
    // ToDo - знаки равны, экспоненты не равны. Переводим в лонг-децимал,
    // нормализуем, сравниваем модули лонг_децимал.
    s21_long_decimal long_value_1 = {0};
    s21_long_decimal long_value_2 = {0};
    int exp_value_1 = __get_exp(value_1.bits[rank_exp_decimal]);
    int exp_value_2 = __get_exp(value_2.bits[rank_exp_decimal]);
    __copy_decimal_to_long_decimal(&value_1, &long_value_1);
    __copy_decimal_to_long_decimal(&value_2, &long_value_2);
    int diff_exp = exp_value_1 - exp_value_2;
    if (diff_exp < 0) {
      // Нормализуем value_1
    } else {
      // Нормализуем value_2
    }
  }
  return result;
}