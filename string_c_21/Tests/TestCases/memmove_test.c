#include "../s21_string_test.h"

START_TEST(memmove_standart_test) {
  char *str = "abc123";
  char copy[SSIZE] = {'\0'};
  char s21_copy[SSIZE] = {'\0'};
  s21_size_t n = 6;

  memmove(copy, str, n);
  s21_memmove(s21_copy, str, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

START_TEST(memmove_empty_test) {
  char *str = "";
  char copy[SSIZE] = {'\0'};
  char s21_copy[SSIZE] = {'\0'};
  s21_size_t n = 0;

  memmove(copy, str, n);
  s21_memmove(s21_copy, str, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

START_TEST(memmove_int_test) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int copy[SSIZE] = {0};
  int s21_copy[SSIZE] = {0};
  s21_size_t n = 4;

  memmove(copy, arr, n);
  s21_memmove(s21_copy, arr, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

START_TEST(memmove_float_test) {
  float arr[] = {2.0, 1.2, 4.2, 8.0, 1.2, 4.8, 10.1};
  float copy[SSIZE] = {0};
  float s21_copy[SSIZE] = {0};
  s21_size_t n = 4;

  memmove(copy, arr, n);
  s21_memmove(s21_copy, arr, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

Suite *memmove_tests() {
  Suite *suite = suite_create("memmove_tests");
  TCase *testCase = tcase_create("memmove_test_case");

  tcase_add_test(testCase, memmove_standart_test);
  tcase_add_test(testCase, memmove_empty_test);
  tcase_add_test(testCase, memmove_int_test);
  tcase_add_test(testCase, memmove_float_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
