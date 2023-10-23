#ifndef S21_FUNC_BITS
#define S21_FUNC_BITS

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

int __get_exp(int rank);
void __set_exp(int *rank, int exp);

void __copy_decimal_to_long_decimal(s21_decimal *decimal,
                                    s21_long_decimal *long_decimal);

int __mul_10_module_long_decimal(s21_long_decimal *long_decimal);
void __add_module_long_decimal(s21_long_decimal value_1,
                               s21_long_decimal value_2,
                               s21_long_decimal *result);

void __sub_module_long_decimal(s21_long_decimal value_1,
                               s21_long_decimal value_2,
                               s21_long_decimal *result);

void __change_exp_up(s21_long_decimal *long_value, int diff_exp);
void __change_exp_down(s21_long_decimal *long_value);

int __long_decimal_to_decimal(s21_long_decimal *long_value, s21_decimal *value);
int __check_value_long_decimal_to_decimal(
    s21_long_decimal long_value);  // !!!!!!!!!!!!!!!!!!!      ToDo      for
                                   // min value  !!!!!!!!!!!!
void __change_value_long_decimal_to_decimal(s21_long_decimal *long_value);

#endif