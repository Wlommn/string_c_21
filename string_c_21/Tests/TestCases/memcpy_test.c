#include "../s21_string_test.h"

START_TEST(memcpy_zero_bytes_test) {
  char *str = "King";
  char copy[SSIZE] = {'\0'};
  char s21_copy[SSIZE] = {'\0'};
  s21_size_t n = 0;

  memcpy(copy, str, n);
  s21_memcpy(s21_copy, str, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

START_TEST(memcpy_empty_test) {
  char *str = "";
  char copy[SSIZE] = {'\0'};
  char s21_copy[SSIZE] = {'\0'};
  s21_size_t n = 0;

  memcpy(copy, str, n);
  s21_memcpy(s21_copy, str, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

START_TEST(memcpy_standart_test) {
  char *str = "King";
  char copy[SSIZE] = {'\0'};
  char s21_copy[SSIZE] = {'\0'};
  s21_size_t n = 5;

  memcpy(copy, str, n);
  s21_memcpy(s21_copy, str, n);

  ck_assert_mem_eq(copy, s21_copy, n);
}
END_TEST

START_TEST(memcpy_ptr_test) {
  char *str = "King";
  char copy[SSIZE] = {'\0'};
  s21_size_t n = 5;

  ck_assert_ptr_eq(memcpy(copy, str, n), s21_memcpy(copy, str, n));
}
END_TEST

Suite *memcpy_tests() {
  Suite *suite = suite_create("memcpy_tests");
  TCase *testCase = tcase_create("memcpy_test_case");

  tcase_add_test(testCase, memcpy_zero_bytes_test);
  tcase_add_test(testCase, memcpy_empty_test);
  tcase_add_test(testCase, memcpy_standart_test);
  tcase_add_test(testCase, memcpy_ptr_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
