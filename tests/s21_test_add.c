#include "s21_tests.h"

START_TEST(test_add_1) {
  char str_value_1[len_str_max] = "-5.89765958854";
  char str_value_2[len_str_max] = "-7.01";
  char str_res_value[len_str_max] = {0};
  char str_test_value[len_str_max] = "-12.90765958854";
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal res_value = {0};
  s21_decimal test_value = {0};
  s21_str_to_decimal(&value_1, str_value_1);
  s21_str_to_decimal(&value_2, str_value_2);
  s21_str_to_decimal(&test_value, str_test_value);
  s21_decimal_to_str(&test_value, str_test_value);
  int err = s21_add(value_1, value_2, &res_value);
  s21_decimal_to_str(&res_value, str_res_value);
  ck_assert_str_eq(str_test_value, str_res_value);
}
END_TEST

START_TEST(test_add_2) {
  char str_value_1[len_str_max] = "7922816";
  char str_value_2[len_str_max] = "0.1";
  char str_res_value[len_str_max] = {0};
  char str_test_value[len_str_max] = "7922816.1";
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal res_value = {0};
  s21_decimal test_value = {0};
  s21_str_to_decimal(&value_1, str_value_1);
  s21_str_to_decimal(&value_2, str_value_2);
  s21_str_to_decimal(&test_value, str_test_value);
  s21_decimal_to_str(&test_value, str_test_value);
  int err = s21_add(value_1, value_2, &res_value);
  s21_decimal_to_str(&res_value, str_res_value);
  ck_assert_str_eq(str_test_value, str_res_value);
}
END_TEST

START_TEST(test_add_3) {
  char str_value_1[len_str_max] = "79228162514264337593543950335";
  char str_value_2[len_str_max] = "0.1";
  char str_res_value[len_str_max] = {0};
  char str_test_value[len_str_max] = "79228162514264337593543950335";
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal res_value = {0};
  s21_decimal test_value = {0};
  s21_str_to_decimal(&value_1, str_value_1);
  s21_str_to_decimal(&value_2, str_value_2);
  s21_str_to_decimal(&test_value, str_test_value);
  s21_decimal_to_str(&test_value, str_test_value);
  int err = s21_add(value_1, value_2, &res_value);
  s21_decimal_to_str(&res_value, str_res_value);
  ck_assert_str_eq(str_test_value, str_res_value);
}
END_TEST

START_TEST(test_add_4) {
  char str_value_1[len_str_max] = "79228162514264337593543950335";
  char str_value_2[len_str_max] = "1.1";
  char str_res_value[len_str_max] = {0};
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal res_value = {0};
  s21_decimal test_value = {0};
  s21_str_to_decimal(&value_1, str_value_1);
  s21_str_to_decimal(&value_2, str_value_2);
  int err = s21_add(value_1, value_2, &res_value);
  ck_assert_int_eq(err, 1);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  TCase *tc = tcase_create("add_tc");

  // небольшие числа с одинаковыми знаками
  tcase_add_test(tc, test_add_1);  // +
  tcase_add_test(tc, test_add_2);  // +
  // максимальное децимал с дробным числом, где значимая часть равна 0
  tcase_add_test(tc, test_add_3);  // +
  // максимальное децимал с дробным числом, где значимая часть не равна 0
  tcase_add_test(tc, test_add_4);  // +

  suite_add_tcase(s, tc);
  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = test_insert();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}