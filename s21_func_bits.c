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
  __sum_module_long_decimal(long_decimal_mul_8, long_decimal_mul_2, &result);
  *long_decimal = result;
}

int __sum_module_long_decimal(s21_long_decimal value_1,
                              s21_long_decimal value_2,
                              s21_long_decimal *result) {
  __print_bit_long_decimal(result);
  __print_bit_long_decimal(&value_1);
  __print_bit_long_decimal(&value_2);
  int bit_over = 0;
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  int err = 0;
  for (int i = 0; i < 196; i++) {
    bit_value_1 = __get_bit_long_decimal(&value_1, i);
    bit_value_2 = __get_bit_long_decimal(&value_2, i);
    if ((bit_value_1 + bit_value_2 + bit_over == 1) ||
        (bit_value_1 + bit_value_2 + bit_over == 3))
      __set_bit_long_decimal(result, i);
    bit_over = bit_value_1 + bit_value_2 + bit_over > 1 ? 1 : 0;
  }
  // bit_value_1 = __get_bit_long_decimal(&value_1, 95);
  // bit_value_2 = __get_bit_long_decimal(&value_2, 95);
  // if (bit_value_1 + bit_value_2 + bit_over == 1)
  //   __set_bit_long_decimal(result, 95);
  // bit_over = bit_value_1 + bit_value_2 + bit_over > 1 ? 1 : 0;
  // err = bit_value_1 + bit_value_2 + bit_over > 1 ? 1 : 0;
  __print_bit_long_decimal(result);
  return err;
}