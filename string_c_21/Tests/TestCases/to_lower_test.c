#include "../s21_string_test.h"

START_TEST(to_lower_standart_test) {
  char *str = "KING JAMES";
  char *expected = "king james";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(expected, result);
  free(result);
}
END_TEST

START_TEST(to_lower_empty_test) {
  char *str = "";
  char *expected = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(expected, result);
  if (*result) {
    free(result);
  }
}
END_TEST

START_TEST(to_lower_another_ch_test) {
  char *str = "123456789[]./ZXA&^";
  char *expected = "123456789[]./zxa&^";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(expected, result);
  if (*result) {
    free(result);
  }
}
END_TEST

Suite *to_lower_tests() {
  Suite *suite = suite_create("to_lower_tests");
  TCase *testCase = tcase_create("to_lower_test_case");

  tcase_add_test(testCase, to_lower_standart_test);
  tcase_add_test(testCase, to_lower_empty_test);
  tcase_add_test(testCase, to_lower_another_ch_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
