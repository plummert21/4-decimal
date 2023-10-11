#include "s21_func_bits.h"

int __get_bit(int num, int bit) { return (num >> bit) & 1; }

int __get_bit_decimal(s21_decimal *num, int bit) {
  return __get_bit(num->bits[bit / 32], bit);
}

void __set_bit(int *num, int bit) { *num |= (1 << bit); }

void __set_bit_decimal(s21_decimal *num, int bit) {
  __set_bit(&num->bits[bit / 32], bit % 32);
}

void __reset_bit(int *num, int bit) { *num &= (~(1 << bit)); }

void __reset_bit_decimal(s21_decimal *num, int bit) {
  __reset_bit(&num->bits[bit / 32], bit % 32);
}

void __print_bit(int num) {
  for (int i = 31; i > -1; i--) printf("%d", __get_bit(num, i));
}

void __print_bit_decimal(s21_decimal *num) {
  for (int i = 3; i > -1; i--) {
    __print_bit(num->bits[i]);
    printf(" ");
  }
  printf("\n");
}