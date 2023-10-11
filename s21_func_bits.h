#ifndef S21_FUNC_BITS
#define S21_FUNC_BITS

#include <stdio.h>

#include "s21_decimal.h"

// ToDo - Generic

int __get_bit(int num, int bit);
int __get_bit_decimal(s21_decimal *num, int bit);
int __get_bit_long_decimal(s21_long_decimal *num, int bit);

void __set_bit(int *num, int bit);
void __set_bit_decimal(s21_decimal *num, int bit);
void __set_bit_long_decimal(s21_long_decimal *num, int bit);

void __reset_bit(int *num, int bit);
void __reset_bit_decimal(s21_decimal *num, int bit);
void __reset_bit_long_decimal(s21_long_decimal *num, int bit);

void __print_bit(int num);
void __print_bit_decimal(s21_decimal *num);
void __print_bit_long_decimal(s21_long_decimal *num);

// ToDo - __get_exp
// int __get_exp(int )

void __copy_decimal_to_long_decimal(s21_decimal *decimal,
                                    s21_long_decimal *long_decimal);

#endif