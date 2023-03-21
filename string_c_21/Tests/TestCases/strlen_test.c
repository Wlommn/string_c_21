#include "../s21_string_test.h"

START_TEST(strlen_standart_test) {
  char *str = "King James";
  size_t result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strlen_empty_test) {
  char *str = "";
  size_t result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strlen_edge_test) {
  char *str = "King J\0ames";
  size_t result = strlen(str);
  s21_size_t s21_result = s21_strlen(str);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

Suite *strlen_tests() {
  Suite *suite = suite_create("strlen_tests");
  TCase *testCase = tcase_create("strlen_test_case");

  tcase_add_test(testCase, strlen_standart_test);
  tcase_add_test(testCase, strlen_empty_test);
  tcase_add_test(testCase, strlen_edge_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
