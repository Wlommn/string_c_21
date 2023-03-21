#include "../s21_string_test.h"

START_TEST(to_upper_standart_test) {
  char *str = "king james";
  char *expected = "KING JAMES";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

START_TEST(to_upper_empty_test) {
  char *str = "";
  char *expected = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

START_TEST(to_upper_another_ch_test) {
  char *str = "123456789[]./zxa&^";
  char *expected = "123456789[]./ZXA&^";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

Suite *to_upper_tests() {
  Suite *suite = suite_create("to_upper_tests");
  TCase *testCase = tcase_create("to_upper_test_case");

  tcase_add_test(testCase, to_upper_standart_test);
  tcase_add_test(testCase, to_upper_empty_test);
  tcase_add_test(testCase, to_upper_another_ch_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
