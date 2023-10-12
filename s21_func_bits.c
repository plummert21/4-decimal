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

void __copy_decimal_to_long_decimal(s21_decimal *decimal,
                                    s21_long_decimal *long_decimal) {
  long_decimal->bits[6] = decimal->bits[3];
  for (int i = 0; i < 3; i++) {
    long_decimal->bits[i] = decimal->bits[i];
  }
}