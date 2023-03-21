#include "../s21_string_test.h"

START_TEST(insert_standart_test) {
  char *src = "King";
  char *str = " James";
  s21_size_t index = s21_strlen(src);
  char *expected = "King James";
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

START_TEST(insert_empty_src_test) {
  char *src = "";
  char *str = "King James";
  s21_size_t index = s21_strlen(src);
  char *expected = "King James";
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

START_TEST(insert_empty_str_test) {
  char *src = "King James";
  char *str = "";
  s21_size_t index = s21_strlen(src);
  char *expected = "King James";
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

START_TEST(insert_empty_test) {
  char *src = "";
  char *str = "";
  s21_size_t index = s21_strlen(src);
  char *expected = "";
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

Suite *insert_tests() {
  Suite *suite = suite_create("insert_tests");
  TCase *testCase = tcase_create("insert_test_case");

  tcase_add_test(testCase, insert_standart_test);
  tcase_add_test(testCase, insert_empty_src_test);
  tcase_add_test(testCase, insert_empty_str_test);
  tcase_add_test(testCase, insert_empty_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
