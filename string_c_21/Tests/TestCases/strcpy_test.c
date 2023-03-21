#include "../s21_string_test.h"

START_TEST(strcpy_standart_test) {
  char *str = "King James";
  char result[SSIZE] = {'\0'};
  char s21_result[SSIZE] = {'\0'};

  strcpy(result, str);
  s21_strcpy(s21_result, str);

  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(strcpy_empty_test) {
  char *str = "";
  char result[SSIZE] = {'\0'};
  char s21_result[SSIZE] = {'\0'};

  strcpy(result, str);
  s21_strcpy(s21_result, str);

  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(strcpy_ptr_test) {
  char *str = "";
  char result[SSIZE] = {'\0'};

  ck_assert_ptr_eq(strcpy(result, str), s21_strcpy(result, str));
}
END_TEST

Suite *strcpy_tests() {
  Suite *suite = suite_create("strcpy_tests");
  TCase *testCase = tcase_create("strcpy_test_case");

  tcase_add_test(testCase, strcpy_standart_test);
  tcase_add_test(testCase, strcpy_empty_test);
  tcase_add_test(testCase, strcpy_ptr_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
