#include "../s21_string_test.h"

START_TEST(trim_standart_test) {
  char *src = "+Make+trim+this+string+\0";
  char *trim_chars = "+";
  char *expected = "Make+trim+this+string";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(expected, result);
  if (result) {
    free(result);
  }
}
END_TEST

START_TEST(trim_empty_str_test) {
  char *src = "";
  char *trim_chars = "+";
  char *expected = NULL;
  char *result = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(expected, result);
  if (result) {
    free(result);
  }
}
END_TEST

START_TEST(trim_empty_trim_test) {
  char *src = "Make trim this string";
  char *trim_chars = "";
  char *expected = "Make trim this string";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(expected, result);
  if (result) {
    free(result);
  }
}
END_TEST

START_TEST(trim_space_test) {
  char *src = "        Make trim this string       ";
  char *trim_chars = "";
  char *expected = "Make trim this string";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(expected, result);
  if (result) {
    free(result);
  }
}
END_TEST

Suite *trim_tests() {
  Suite *suite = suite_create("trim_tests");
  TCase *testCase = tcase_create("trim_test_case");

  tcase_add_test(testCase, trim_standart_test);
  tcase_add_test(testCase, trim_empty_str_test);
  tcase_add_test(testCase, trim_empty_trim_test);
  tcase_add_test(testCase, trim_space_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
