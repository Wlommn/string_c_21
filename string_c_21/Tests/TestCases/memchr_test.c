#include "../s21_string_test.h"

START_TEST(memchr_empty_test) {
  char *str = "";
  int find = '\0';
  s21_size_t n = 0;

  ck_assert_ptr_eq(memchr(str, find, n), s21_memchr(str, find, n));
}
END_TEST

START_TEST(memchr_standart_test) {
  char *str = "Beethoven";
  int find = 'v';
  s21_size_t n = 9;

  ck_assert_ptr_eq(memchr(str, find, n), s21_memchr(str, find, n));
}
END_TEST

START_TEST(memchr_more_bytes_test) {
  char str[SSIZE] = "Beethoven";
  int find = 'v';
  s21_size_t n = 20;

  ck_assert_ptr_eq(memchr(str, find, n), s21_memchr(str, find, n));
}
END_TEST

START_TEST(memchr_zero_test) {
  char *str = "Zero";
  int find = '\0';
  s21_size_t n = 5;

  ck_assert_ptr_eq(memchr(str, find, n), s21_memchr(str, find, n));
}
END_TEST

START_TEST(memchr_int_test) {
  int arr[] = {1, 2, 3, 4, 4, 5, 6};
  int find = 4;
  s21_size_t n = sizeof(int) * 7;

  ck_assert_ptr_eq(memchr(arr, find, n), s21_memchr(arr, find, n));
}
END_TEST

START_TEST(memchr_float_test) {
  float arr[] = {2.0, 1.2, 4.2, 8.0, 1.2, 4.8, 10.1};
  int find = 8.0;
  s21_size_t n = sizeof(float) * 7;

  ck_assert_ptr_eq(memchr(arr, find, n), s21_memchr(arr, find, n));
}
END_TEST

Suite *memchr_tests() {
  Suite *suite = suite_create("memchr_tests");
  TCase *testCase = tcase_create("memchr_test_case");

  tcase_add_test(testCase, memchr_empty_test);
  tcase_add_test(testCase, memchr_standart_test);
  tcase_add_test(testCase, memchr_more_bytes_test);
  tcase_add_test(testCase, memchr_zero_test);
  tcase_add_test(testCase, memchr_int_test);
  tcase_add_test(testCase, memchr_float_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
