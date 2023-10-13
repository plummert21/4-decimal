#include "s21_compare.h"
#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  int compare = 0;
  s21_long_decimal long_value_1 = {0};
  s21_long_decimal long_value_2 = {0};
  __pre_compare_module_long_decimal(&value_1, &value_2, &long_value_1,
                                    &long_value_2);
  compare = __compare_long_decimal(&long_value_1, &long_value_2);
  if (compare == 7) result++;
  return result;
}
