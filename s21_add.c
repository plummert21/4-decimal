#include "s21_compare.h"
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
  if (__get_bit(compare, 2)) {
    __add_module_long_decimal(long_value_1, long_value_2, &long_result);
    result->bits[rank_exp_decimal] = value_1.bits[rank_exp_decimal];
    // !!!!!!!!!!!!!!!!!!!!!!   ToDo   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // round for big and small value
    for (int i = 2; i >= 0; i--) {
      result->bits[i] = long_result.bits[i];
    }
  } else {
    // ToDo разность если знаки различны
  }
  return err;
}