#include "s21_func_bits.h"

int __get_bit(int num, int bit) { return (num >> bit) & 1; }

int __get_bit_decimal(s21_decimal *num, int bit) {
  return __get_bit(num->bits[bit / 32], bit % 32);
}

int __get_bit_long_decimal(s21_long_decimal *num, int bit) {
  return __get_bit(num->bits[bit / 32], bit % 32);
}

void __set_bit(int *num, int bit) { *num |= (1 << bit); }

void __set_bit_decimal(s21_decimal *num, int bit) {
  __set_bit(&num->bits[bit / 32], bit % 32);
}

void __set_bit_long_decimal(s21_long_decimal *num, int bit) {
  __set_bit(&num->bits[bit / 32], bit % 32);
}

void __reset_bit(int *num, int bit) { *num &= (~(1 << bit)); }

void __reset_bit_decimal(s21_decimal *num, int bit) {
  __reset_bit(&num->bits[bit / 32], bit % 32);
}

void __reset_bit_long_decimal(s21_long_decimal *num, int bit) {
  __reset_bit(&num->bits[bit / 32], bit % 32);
}

void __print_bit(int num) {
  for (int i = 31; i >= 0; i--) printf("%d", __get_bit(num, i));
}

void __print_bit_decimal(s21_decimal *num) {
  for (int i = 3; i >= 0; i--) {
    __print_bit(num->bits[i]);
    printf(" ");
  }
  printf("\n");
}

void __print_bit_long_decimal(s21_long_decimal *num) {
  __print_bit(num->bits[6]);
  printf("\n");
  for (int i = 5; i >= 0; i--) {
    __print_bit(num->bits[i]);
    printf(" ");
  }
  printf("\n");
}

int __get_exp(int rank) {
  __reset_bit(&rank, 31);
  return (rank >> 16);
}

void __set_exp(int *rank, int exp) {
  int sign = __get_bit(*rank, 31);
  int err = __get_bit(*rank, 0);
  *rank = exp << 16;
  if (sign) __set_bit(rank, 31);
  if (err) __set_bit(rank, 0);
}

void __copy_decimal_to_long_decimal(s21_decimal *decimal,
                                    s21_long_decimal *long_decimal) {
  long_decimal->bits[6] = decimal->bits[3];
  for (int i = 0; i < 3; i++) {
    long_decimal->bits[i] = decimal->bits[i];
  }
}

int __mul_10_module_long_decimal(s21_long_decimal *long_decimal) {
  // ToDo
  int err = 0;
  s21_long_decimal long_decimal_mul_8 = *long_decimal;
  s21_long_decimal long_decimal_mul_2 = *long_decimal;
  s21_long_decimal result = {0};
  result.bits[rank_exp_long_decimal] =
      long_decimal->bits[rank_exp_long_decimal];
  for (int i = rank_exp_long_decimal - 1; i >= 0; i--) {
    for (int j = 31, k = 2; j >= 29; j--, k--) {
      if (__get_bit(long_decimal_mul_8.bits[i], j)) {
        __set_bit(&long_decimal_mul_8.bits[i + 1], k);
      }
    }
    long_decimal_mul_8.bits[i] = long_decimal_mul_8.bits[i] << 3;

    if (__get_bit(long_decimal_mul_2.bits[i], 31)) {
      __set_bit(&long_decimal_mul_2.bits[i + 1], 0);
    }
    long_decimal_mul_2.bits[i] = long_decimal_mul_2.bits[i] << 1;
  }
  __add_module_long_decimal(long_decimal_mul_8, long_decimal_mul_2, &result);
  *long_decimal = result;
}

void __add_module_long_decimal(s21_long_decimal value_1,
                               s21_long_decimal value_2,
                               s21_long_decimal *result) {
  int bit_over = 0;
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  for (int i = 0; i < 196; i++) {
    bit_value_1 = __get_bit_long_decimal(&value_1, i);
    bit_value_2 = __get_bit_long_decimal(&value_2, i);
    if ((bit_value_1 + bit_value_2 + bit_over == 1) ||
        (bit_value_1 + bit_value_2 + bit_over == 3))
      __set_bit_long_decimal(result, i);
    bit_over = bit_value_1 + bit_value_2 + bit_over > 1 ? 1 : 0;
  }
}

void __sub_module_long_decimal(s21_long_decimal value_1,
                               s21_long_decimal value_2,
                               s21_long_decimal *result) {
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  for (int i = 0; i < count_bits_module_long_decimal; i++) {
    bit_value_1 = __get_bit_long_decimal(&value_1, i);
    bit_value_2 = __get_bit_long_decimal(&value_2, i);
    if ((bit_value_1 - bit_value_2) < 0) {
      int j = i;
      while (!(__get_bit_long_decimal(&value_1, j))) {
        __set_bit_long_decimal(&value_1, j);
        j++;
      }
      __reset_bit_long_decimal(&value_1, j);
      __reset_bit_long_decimal(&value_2, i);
    }
    bit_value_1 = __get_bit_long_decimal(&value_1, i);
    bit_value_2 = __get_bit_long_decimal(&value_2, i);
    if ((bit_value_1 - bit_value_2) == 1) __set_bit_long_decimal(result, i);
    if ((bit_value_1 - bit_value_2) == 0) __reset_bit_long_decimal(result, i);
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

void __change_exp_down(s21_long_decimal *long_value) {
  int exp = __get_exp(long_value->bits[rank_exp_long_decimal]);
  char str[len_str_max] = {0};
  __set_exp(&long_value->bits[rank_exp_long_decimal], 1);
  s21_long_decimal_to_str(long_value, str);

  str[strlen(str) - 1] = '\0';
  for (int i = 0; i < rank_exp_long_decimal; i++) long_value->bits[i] = 0;
  exp--;
  s21_str_to_long_decimal(long_value, str);
  __set_exp(&long_value->bits[rank_exp_long_decimal], exp);
}

int __long_decimal_to_decimal(s21_long_decimal *long_value,
                              s21_decimal *value) {
  int err = 0;

  err = __check_value_long_decimal_to_decimal(*long_value);
  if (!err) {
    __change_value_long_decimal_to_decimal(long_value);
    // copy value long decimal to decimal
    value->bits[rank_exp_decimal] = long_value->bits[rank_exp_long_decimal];
    for (int i = 2; i >= 0; i--) {
      value->bits[i] = long_value->bits[i];
    }
  }
  return err;
}

int __check_value_long_decimal_to_decimal(s21_long_decimal long_value) {
  int err = 0;
  int diff_exp = 0;
  s21_long_decimal long_decimal_max = {0};
  char str_max[len_str_max] = max_decimal;
  int i = count_bits_module_long_decimal;
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  s21_str_to_long_decimal(&long_decimal_max, str_max);
  diff_exp = __get_exp(long_value.bits[rank_exp_long_decimal]) -
             __get_exp(long_decimal_max.bits[rank_exp_long_decimal]);
  while (diff_exp > 0) {
    __change_exp_down(&long_value);
    diff_exp--;
  }
  do {
    i--;
    bit_value_1 = __get_bit_long_decimal(&long_value, i);
    bit_value_2 = __get_bit_long_decimal(&long_decimal_max, i);
  } while ((bit_value_1 == bit_value_2) && (i != 0));
  if (bit_value_1 > bit_value_2) {
    err = 1;
  }
  return err;
}

void __change_value_long_decimal_to_decimal(s21_long_decimal *long_value) {
  int exp = __get_exp(long_value->bits[rank_exp_long_decimal]);
  char str[len_str_max] = {0};
  // отбрасываем не значимую часть числа
  s21_long_decimal_to_str(long_value, str);
  __set_exp(&long_value->bits[rank_exp_long_decimal], 1);
  while ((long_value->bits[3]) || (long_value->bits[4]) ||
         (long_value->bits[5])) {
    str[strlen(str) - 1] = '\0';
    for (int i = 0; i < rank_exp_long_decimal; i++) long_value->bits[i] = 0;
    s21_str_to_long_decimal(long_value, str);
    exp--;
  }
  if (long_value->bits[0] || long_value->bits[1] || long_value->bits[2]) {
    __set_exp(&long_value->bits[rank_exp_long_decimal], exp);
  } else {
    __set_exp(&long_value->bits[rank_exp_long_decimal], 0);
    __reset_bit_long_decimal(long_value, sign_bit_long_decimal);
  }
}