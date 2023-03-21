#include "../s21_string_test.h"

START_TEST(strncpy_standart_test) {
  char *str = "King James";
  char result[SSIZE] = {'\0'};
  char s21_result[SSIZE] = {'\0'};
  s21_size_t n = 10;

  strncpy(result, str, n);
  s21_strncpy(s21_result, str, n);

  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(strncpy_empty_test) {
  char *str = "";
  char result[SSIZE] = {'\0'};
  char s21_result[SSIZE] = {'\0'};
  s21_size_t n = 10;

  strncpy(result, str, n);
  s21_strncpy(s21_result, str, n);

  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(strncpy_ptr_test) {
  char *str = "";
  char result[SSIZE] = {'\0'};
  s21_size_t n = 1;

  ck_assert_ptr_eq(strncpy(result, str, n), s21_strncpy(result, str, n));
}
END_TEST

START_TEST(strncpy_bytes_gr_test) {
  char *str = "King James";
  char result[SSIZE] = {'\0'};
  char s21_result[SSIZE] = {'\0'};
  s21_size_t n = 15;

  strncpy(result, str, n);
  s21_strncpy(s21_result, str, n);

  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(strncpy_zero_bytes_test) {
  char *str = "King James";
  char result[SSIZE] = {'\0'};
  char s21_result[SSIZE] = {'\0'};
  s21_size_t n = 0;

  strncpy(result, str, n);
  s21_strncpy(s21_result, str, n);

  ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite *strncpy_tests() {
  Suite *suite = suite_create("strncpy_tests");
  TCase *testCase = tcase_create("strncpy_test_case");

  tcase_add_test(testCase, strncpy_standart_test);
  tcase_add_test(testCase, strncpy_empty_test);
  tcase_add_test(testCase, strncpy_ptr_test);
  tcase_add_test(testCase, strncpy_bytes_gr_test);
  tcase_add_test(testCase, strncpy_zero_bytes_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
