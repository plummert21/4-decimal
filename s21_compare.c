#include "s21_compare.h"

int __compare_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // if return 7 - ident value_1 and value_2
  int result = -1;
  int compare_sign = __compare_sign_decimal(value_1, value_2);
  int compare_exp = __compare_exp_decimal(value_1, value_2);
  int compare_module = __compare_module_decimal(value_1, value_2);
  int compare = compare_sign | compare_exp | compare_module;
  return compare;
}

int __compare_sign_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // return 0 - false, 4 - true
  int result = 0;
  int sign_value_1 = __get_bit_decimal(value_1, sign_bit_decimal);
  int sign_value_2 = __get_bit_decimal(value_2, sign_bit_decimal);
  if (sign_value_1 == sign_value_2) {
    __set_bit(&result, compare_sign_bit);
  }
  return result;
}

int __compare_exp_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // return 0 - false, 2 - true
  int result = 0;
  int exp_value_1 = __get_exp(value_1->bits[rank_exp_decimal]);
  int exp_value_2 = __get_exp(value_2->bits[rank_exp_decimal]);
  if (exp_value_1 == exp_value_2) {
    __set_bit(&result, compare_exp_bit);
  }
  return result;
}

int __compare_module_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  // return 0 - false, 1 - true
  int result = 0;
  int i = 96;
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  do {
    i--;
    bit_value_1 = __get_bit_decimal(value_1, i);
    bit_value_2 = __get_bit_decimal(value_2, i);
  } while ((bit_value_1 == bit_value_2) && (i != 0));
  result = bit_value_1 != bit_value_2 ? 0 : 1;
  return result;
}

int __compare_long_decimal(s21_long_decimal *value_1,
                           s21_long_decimal *value_2) {
  // if return 7 - ident value_1 and value_2
  int result = -1;
  int compare_sign = __compare_sign_long_decimal(value_1, value_2);
  int compare_exp = __compare_exp_long_decimal(value_1, value_2);
  int compare_module = __compare_module_long_decimal(value_1, value_2);
  int compare = compare_sign | compare_exp | compare_module;
  return compare;
}

int __compare_sign_long_decimal(s21_long_decimal *value_1,
                                s21_long_decimal *value_2) {
  // return 0 - false, 4 - true
  int result = 0;
  int sign_value_1 = __get_bit_long_decimal(value_1, sign_bit_long_decimal);
  int sign_value_2 = __get_bit_long_decimal(value_2, sign_bit_long_decimal);
  if (sign_value_1 == sign_value_2) {
    __set_bit(&result, compare_sign_bit);
  }
  return result;
}

int __compare_exp_long_decimal(s21_long_decimal *value_1,
                               s21_long_decimal *value_2) {
  // return 0 - false, 2 - true
  int result = 0;
  int exp_value_1 = __get_exp(value_1->bits[rank_exp_long_decimal]);
  int exp_value_2 = __get_exp(value_2->bits[rank_exp_long_decimal]);
  if (exp_value_1 == exp_value_2) {
    __set_bit(&result, compare_exp_bit);
  }
  return result;
}

int __compare_module_long_decimal(s21_long_decimal *value_1,
                                  s21_long_decimal *value_2) {
  // return 0 - false, 1 - true
  int result = 0;
  int i = 192;
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  do {
    i--;
    bit_value_1 = __get_bit_long_decimal(value_1, i);
    bit_value_2 = __get_bit_long_decimal(value_2, i);
  } while ((bit_value_1 == bit_value_2) && (i != 0));
  result = bit_value_1 != bit_value_2 ? 0 : 1;
  return result;
}

void __pre_compare_module_long_decimal(s21_decimal *value_1,
                                       s21_decimal *value_2,
                                       s21_long_decimal *long_value_1,
                                       s21_long_decimal *long_value_2) {
  int exp_value_1 = __get_exp(value_1->bits[rank_exp_decimal]);
  int exp_value_2 = __get_exp(value_2->bits[rank_exp_decimal]);
  __copy_decimal_to_long_decimal(value_1, long_value_1);
  __copy_decimal_to_long_decimal(value_2, long_value_2);
  int diff_exp = exp_value_1 - exp_value_2;
  if (diff_exp < 0) {
    __change_exp_up(long_value_1, diff_exp);
  } else {
    __change_exp_up(long_value_2, diff_exp);
  }
}

void __change_exp_up(s21_long_decimal *long_value, int diff_exp) {
  char str[len_str_max] = {0};
  for (int i = 0; i < diff_exp; i++) {
    __mul_10_module_long_decimal(long_value);
  }
  long_value->bits[rank_exp_long_decimal] += (diff_exp << 16);
  s21_long_decimal_to_str(long_value, str);
}