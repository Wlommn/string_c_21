#include "../s21_string_test.h"

START_TEST(strchr_standart_test) {
  char *str = "King James";
  char find = 'J';

  ck_assert_ptr_eq(strchr(str, find), s21_strchr(str, find));
}
END_TEST

START_TEST(strchr_empty_str_test) {
  char *str = "";
  char find = 'J';

  ck_assert_ptr_eq(strchr(str, find), s21_strchr(str, find));
}
END_TEST

START_TEST(strchr_empty_char_test) {
  char *str = "King James";
  char find = '\0';

  ck_assert_ptr_eq(strchr(str, find), s21_strchr(str, find));
}
END_TEST

Suite *strchr_tests() {
  Suite *suite = suite_create("strchr_tests");
  TCase *testCase = tcase_create("strchr_test_case");

  tcase_add_test(testCase, strchr_standart_test);
  tcase_add_test(testCase, strchr_empty_str_test);
  tcase_add_test(testCase, strchr_empty_char_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
