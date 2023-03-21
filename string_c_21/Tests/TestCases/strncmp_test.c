#include "../s21_string_test.h"

START_TEST(strncmp_eq_test) {
  char *str = "King James";
  char *str2 = "King James";
  s21_size_t n = 10;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strncmp_first_gr_test) {
  char *str = "Cesar August";
  char *str2 = "King James";
  s21_size_t n = 12;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strncmp_second_gr_test) {
  char *str = "King James";
  char *str2 = "Cesar August";
  s21_size_t n = 12;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strncmp_empty_test) {
  char *str = "";
  char *str2 = "";
  s21_size_t n = 0;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strncmp_num_str_test) {
  char *str = "1234";
  char *str2 = "1234";
  s21_size_t n = 4;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strncmp_bytes_gr_test) {
  char *str = "1234";
  char *str2 = "1234";
  s21_size_t n = 6;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strncmp_zero_bytes_test) {
  char *str = "1234";
  char *str2 = "1234";
  s21_size_t n = 0;
  int result = strncmp(str, str2, n);
  int s21_result = s21_strncmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

Suite *strncmp_tests() {
  Suite *suite = suite_create("strncmp_tests");
  TCase *testCase = tcase_create("strncmp_test_case");

  tcase_add_test(testCase, strncmp_eq_test);
  tcase_add_test(testCase, strncmp_first_gr_test);
  tcase_add_test(testCase, strncmp_second_gr_test);
  tcase_add_test(testCase, strncmp_empty_test);
  tcase_add_test(testCase, strncmp_num_str_test);
  tcase_add_test(testCase, strncmp_bytes_gr_test);
  tcase_add_test(testCase, strncmp_zero_bytes_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
