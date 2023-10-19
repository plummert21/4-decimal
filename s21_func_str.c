#include "s21_func_str.h"

void s21_str_to_decimal(s21_decimal *num, char *str) {
  char *tmp = str;
  char c = '.';
  if (str[strlen(str) - 1] == c) str[strlen(str) - 1] = '\0';
  size_t tmp_len = strlen(str);
  int dot = 0;
  char *exp = strrchr(tmp, c);
  if (exp) {
    dot = strlen(exp) - 1;
    dot = dot << 16;
    num->bits[rank_exp_decimal] |= dot;
  }
  if (*tmp == '+') tmp++;
  if (*tmp == '-') {
    __set_bit_decimal(num, sign_bit_decimal);
    tmp++;
    tmp_len--;
  }
  int i = tmp_len - 1, j = 0;
  while (*tmp) {
    i = tmp_len - 1;
    if (tmp[i] % 2) {
      __set_bit_decimal(num, j);
      tmp[i]--;
    }
    __div_str(tmp, tmp_len);
    tmp_len = strlen(tmp);
    j++;
  }
}

void s21_str_to_long_decimal(s21_long_decimal *num, char *str) {
  char *tmp = str;
  char c = '.';
  if (str[strlen(str) - 1] == c) str[strlen(str) - 1] = '\0';
  size_t tmp_len = strlen(str);
  int dot = 0;
  char *exp = strrchr(tmp, c);
  if (exp) {
    dot = strlen(exp) - 1;
    dot = dot << 16;
    num->bits[rank_exp_long_decimal] |= dot;
  }
  if (*tmp == '+') tmp++;
  if (*tmp == '-') {
    __set_bit_long_decimal(num, sign_bit_long_decimal);
    tmp++;
    tmp_len--;
  }
  int i = tmp_len - 1, j = 0;
  while (*tmp) {
    i = tmp_len - 1;
    if (tmp[i] % 2) {
      __set_bit_long_decimal(num, j);
      tmp[i]--;
    }
    __div_str(tmp, tmp_len);
    tmp_len = strlen(tmp);
    j++;
  }
}

void __div_str(char *str, size_t tmp_len) {
  char res[len_str_max] = {0};
  int tmp = 0, tmp_val = '0';
  int i = 0, j = 0;
  tmp = str[i] - '0';
  for (; i < tmp_len;) {
    tmp_val = tmp / 2 + '0';
    tmp %= 2;
    if ((tmp_val < 59) && (tmp_val >= 48)) {
      res[j++] = tmp_val;
    }
    if (str[++i] == '.') i++;
    tmp = tmp * 10 + (str[i] - '0');
  }
  res[j] = '\0';
  if (*res == '0') __del_zero(res);
  strcpy(str, res);
}

void __del_zero(char *str) {
  while (*str == '0') {
    int lenStr = strlen(str);
    for (int i = 0; i <= lenStr; i++) {
      str[i] = str[i + 1];
    }
  }
}

void s21_decimal_to_str(s21_decimal *num, char *str) {
  char str_pow_2[len_str_max];
  __init_str(str);
  for (int i = 0; i < count_bits_module_decimal; i++) {
    __init_str(str_pow_2);
    str_pow_2[len_str_max - 1] = '1';
    if (__get_bit_decimal(num, i)) {
      __pow_2_to_str(str_pow_2, i);
      __sum_strings_10(str_pow_2, str, str);
    }
  }
  if (__get_bit_decimal(num, sign_bit_decimal)) str[0] = '-';
  __dot_incert_to_str(__get_exp(num->bits[rank_exp_decimal]), str);
}

void s21_long_decimal_to_str(s21_long_decimal *num, char *str) {
  char str_pow_2[len_str_max];
  __init_str(str);
  for (int i = 0; i < count_bits_module_long_decimal; i++) {
    __init_str(str_pow_2);
    str_pow_2[len_str_max - 1] = '1';
    if (__get_bit_long_decimal(num, i)) {
      __pow_2_to_str(str_pow_2, i);
      __sum_strings_10(str_pow_2, str, str);
    }
  }
  if (__get_bit_long_decimal(num, sign_bit_long_decimal)) str[0] = '-';
  __dot_incert_to_str(__get_exp(num->bits[rank_exp_long_decimal]), str);
}

void s21_print_str(char *str) {
  printf("%c ", str[0]);
  for (int i = 1; i < len_str_max; i++) {
    printf("%c", str[i]);
    if (i % 3 == 0) printf(" ");
  }
  printf("\n");
}

void __init_str(char *str) {
  str[len_str_max] = '\0';
  // str[0] = 's';
  for (int i = len_str_max - 1; i >= 0; i--) str[i] = '0';
}

void __pow_2_to_str(char *str, int pow) {
  int over = 0;
  if (pow > 0) {
    for (int i = 1; i <= pow; i++) {
      int tmp_value = 0;
      for (int str_i = len_str_max - 1; str_i > 0; str_i--) {
        tmp_value = (str[str_i] - '0') * 2 + over;
        if (tmp_value < 10) over = 0;
        if (tmp_value > 9) {
          tmp_value %= 10;
          over = 1;
        }
        tmp_value = tmp_value + '0';
        if ((tmp_value < 59) && (tmp_value >= 48)) {
          str[str_i] = tmp_value;
        }
      }
    }
  }
}

void __sum_strings_10(char *str1, char *str2, char *sum_str) {
  int over = 0;
  int tmp_value = 0;
  for (int str_i = len_str_max - 1; str_i > 0; str_i--) {
    tmp_value = (str1[str_i] - '0') + (str2[str_i] - '0') + over;
    if (tmp_value < 10) over = 0;
    if (tmp_value > 9) {
      tmp_value %= 10;
      over = 1;
    }
    tmp_value = tmp_value + '0';
    if ((tmp_value < 59) && (tmp_value >= 48)) {
      sum_str[str_i] = tmp_value;
    }
  }
}

void __dot_incert_to_str(int dot, char *str) {
  int i = 1;
  for (; i < len_str_max - dot - 1; i++) {
    str[i] = str[i + 1];
  }
  str[i] = '.';
}