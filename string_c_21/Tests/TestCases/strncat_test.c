#include "../s21_string_test.h"

START_TEST(strncat_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  s21_size_t n = 3;

  strncat(str, "456", n);
  s21_strncat(s21_str, "456", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strncat_empty_dest_test) {
  char str[SSIZE] = "";
  char s21_str[SSIZE] = "";
  s21_size_t n = 4;

  strncat(str, "dest", n);
  s21_strncat(s21_str, "dest", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strncat_empty_src_test) {
  char str[SSIZE] = "src";
  char s21_str[SSIZE] = "src";
  s21_size_t n = 0;

  strncat(str, "", n);
  s21_strncat(s21_str, "", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strncat_zero_bytes_test) {
  char str[SSIZE] = "dest";
  char s21_str[SSIZE] = "dest";
  s21_size_t n = 0;

  strncat(str, "dsds", n);
  s21_strncat(s21_str, "dsds", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strncat_more_bytes_test) {
  char str[SSIZE] = "dest";
  char s21_str[SSIZE] = "dest";
  s21_size_t n = 10;

  strncat(str, "dsds", n);
  s21_strncat(s21_str, "dsds", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strncat_ptr_test) {
  char str[SSIZE] = "src";
  s21_size_t n = 2;

  ck_assert_ptr_eq(strncat(str, "23", n), s21_strncat(str, "23", n));
}
END_TEST

Suite *strncat_tests() {
  Suite *suite = suite_create("strncat_tests");
  TCase *testCase = tcase_create("strncat_test_case");

  tcase_add_test(testCase, strncat_standart_test);
  tcase_add_test(testCase, strncat_empty_dest_test);
  tcase_add_test(testCase, strncat_empty_src_test);
  tcase_add_test(testCase, strncat_ptr_test);
  tcase_add_test(testCase, strncat_zero_bytes_test);
  tcase_add_test(testCase, strncat_more_bytes_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
