#include "../s21_string_test.h"

START_TEST(strcmp_eq_test) {
  char *str = "King James";
  char *str2 = "King James";
  int result = strcmp(str, str2);
  int s21_result = s21_strcmp(str, str2);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strcmp_first_gr_test) {
  char *str = "Cesar August";
  char *str2 = "King James";
  int result = strcmp(str, str2);
  int s21_result = s21_strcmp(str, str2);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strcmp_second_gr_test) {
  char *str = "King James";
  char *str2 = "Cesar August";
  int result = strcmp(str, str2);
  int s21_result = s21_strcmp(str, str2);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strcmp_empty_test) {
  char *str = "";
  char *str2 = "";
  int result = strcmp(str, str2);
  int s21_result = s21_strcmp(str, str2);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strcmp_num_str_test) {
  char *str = "1234";
  char *str2 = "1234";
  int result = strcmp(str, str2);
  int s21_result = s21_strcmp(str, str2);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

Suite *strcmp_tests() {
  Suite *suite = suite_create("strcmp_tests");
  TCase *testCase = tcase_create("strcmp_test_case");

  tcase_add_test(testCase, strcmp_eq_test);
  tcase_add_test(testCase, strcmp_first_gr_test);
  tcase_add_test(testCase, strcmp_second_gr_test);
  tcase_add_test(testCase, strcmp_empty_test);
  tcase_add_test(testCase, strcmp_num_str_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
