#include "../s21_string_test.h"

START_TEST(memset_standart_test) {
  char str[] = "abc123";
  char s21_str[] = "abc123";
  char ch = '0';
  s21_size_t n = 3;

  memset(str, ch, n);
  s21_memset(s21_str, ch, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(memset_zero_bytes_test) {
  char str[] = "abc123";
  char s21_str[] = "abc123";
  char ch = '0';
  s21_size_t n = 0;

  memset(str, ch, n);
  s21_memset(s21_str, ch, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(memset_empty_test) {
  char *str = "";
  char *s21_str = "";
  char ch = '\0';
  s21_size_t n = 0;

  memset(str, ch, n);
  s21_memset(s21_str, ch, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(memset_ptr_test) {
  char str[] = "abc123";
  char ch = '0';
  char ch2 = '2';
  s21_size_t n = 3;

  ck_assert_ptr_eq(memset(str, ch, n), s21_memset(str, ch2, n));
}
END_TEST

Suite *memset_tests() {
  Suite *suite = suite_create("memset_tests");
  TCase *testCase = tcase_create("memset_test_case");

  tcase_add_test(testCase, memset_standart_test);
  tcase_add_test(testCase, memset_zero_bytes_test);
  tcase_add_test(testCase, memset_empty_test);
  tcase_add_test(testCase, memset_ptr_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
