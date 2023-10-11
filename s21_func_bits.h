#ifndef S21_FUNC_BITS
#define S21_FUNC_BITS

#include "s21_decimal.h"

int __get_bit(int num, int bit);
int __get_bit_decimal(s21_decimal *num, int bit);

int __set_bit(int num, int bit);
void __set_bit_decimal(s21_decimal *num, int bit);

int __reset_bit(int num, int bit);
void __reset_bit_decimal(s21_decimal *num, int bit);

void __print_bit(int num);
void __print_bit_decimal(s21_decimal *num);

#endif