#include "../s21_string_test.h"

START_TEST(strspn_standart_test) {
  char *str = "King has name James";
  char *find = "ame";
  s21_size_t result = strspn(str, find);
  s21_size_t s21_result = s21_strspn(str, find);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strspn_empty_str_test) {
  char *str = "";
  char *find = "ame";
  s21_size_t result = strspn(str, find);
  s21_size_t s21_result = s21_strspn(str, find);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strspn_empty_find_test) {
  char *str = "King has name James";
  char *find = "";
  s21_size_t result = strspn(str, find);
  s21_size_t s21_result = s21_strspn(str, find);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(strspn_mixed_find_test) {
  char *str = "King has name James";
  char *find = "eam";
  s21_size_t result = strspn(str, find);
  s21_size_t s21_result = s21_strspn(str, find);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

Suite *strspn_tests() {
  Suite *suite = suite_create("strspn_tests");
  TCase *testCase = tcase_create("strspn_test_case");

  tcase_add_test(testCase, strspn_standart_test);
  tcase_add_test(testCase, strspn_empty_str_test);
  tcase_add_test(testCase, strspn_empty_find_test);
  tcase_add_test(testCase, strspn_mixed_find_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
