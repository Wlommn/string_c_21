#include "../s21_string_test.h"

START_TEST(strcat_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";

  strcat(str, "456");
  s21_strcat(s21_str, "456");

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strcat_empty_dest_test) {
  char str[SSIZE] = "";
  char s21_str[SSIZE] = "";

  strcat(str, "dest");
  s21_strcat(s21_str, "dest");

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strcat_empty_src_test) {
  char str[SSIZE] = "src";
  char s21_str[SSIZE] = "src";

  strcat(str, "");
  s21_strcat(s21_str, "");

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(strcat_ptr_test) {
  char str[SSIZE] = "src";

  ck_assert_ptr_eq(strcat(str, "23"), s21_strcat(str, "23"));
}
END_TEST

Suite *strcat_tests() {
  Suite *suite = suite_create("strcat_tests");
  TCase *testCase = tcase_create("strcat_test_case");

  tcase_add_test(testCase, strcat_standart_test);
  tcase_add_test(testCase, strcat_empty_dest_test);
  tcase_add_test(testCase, strcat_empty_src_test);
  tcase_add_test(testCase, strcat_ptr_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
