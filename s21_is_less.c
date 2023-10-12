#include "s21_decimal.h"
#include "s21_func_bits.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 2;
  int sign_value_1 = __get_bit_decimal(&value_1, sign_bit_decimal);
  int sign_value_2 = __get_bit_decimal(&value_2, sign_bit_decimal);
  int exp_value_1 = __get_exp(value_1.bits[rank_exp_decimal]);
  int exp_value_2 = __get_exp(value_2.bits[rank_exp_decimal]);
  int diff_exp = exp_value_1 - exp_value_2;
  if (sign_value_1 == sign_value_2) {
    int count_rank = 3;
    if (diff_exp) {
      s21_long_decimal value_1_long;
      s21_long_decimal value_2_long;
      __copy_decimal_to_long_decimal(&value_1, &value_1_long);
      __copy_decimal_to_long_decimal(&value_2, &value_2_long);
      // ToDo - нормализация long_decimal
      count_rank = 6;
    } else {
      // ToDo - сравнение модулей decimal or lond_decimal (в
      // зависимости от значения count_rank).
    }

  } else {
    result = sign_value_1 > sign_value_2 ? 1 : 0;
  }
  return result;
}