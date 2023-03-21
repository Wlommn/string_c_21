#include "../s21_string_test.h"

START_TEST(strtok_standart_test) {
  char str[SSIZE] = "King has name James";
  char str2[SSIZE] = "King has name James";
  char *delim = " ";
  char *result = strtok(str, delim);
  char *s21_result = s21_strtok(str2, delim);
  while (result != NULL || s21_result != S21_NULL) {
    ck_assert_str_eq(result, s21_result);
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_all_sep_test) {
  char str[SSIZE] = "_____";
  char str2[SSIZE] = "_____";
  char *delim = "_";
  char *result = strtok(str, delim);
  char *s21_result = s21_strtok(str2, delim);
  while (result != NULL || s21_result != S21_NULL) {
    ck_assert_str_eq(result, s21_result);
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_empty_test) {
  char str[SSIZE] = "";
  char str2[SSIZE] = "";
  char *delim = "_";
  char *result = strtok(str, delim);
  char *s21_result = s21_strtok(str2, delim);
  while (result != NULL || s21_result != S21_NULL) {
    ck_assert_str_eq(result, s21_result);
    result = strtok(NULL, delim);
    s21_result = s21_strtok(NULL, delim);
  }
}
END_TEST

Suite *strtok_tests() {
  Suite *suite = suite_create("strtok_tests");
  TCase *testCase = tcase_create("strtok_test_case");

  tcase_add_test(testCase, strtok_standart_test);
  tcase_add_test(testCase, strtok_all_sep_test);
  tcase_add_test(testCase, strtok_empty_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
