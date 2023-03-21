#include "../s21_string_test.h"

START_TEST(strstr_standart_test) {
  char *str = "King has name James";
  char *find = "James";

  ck_assert_ptr_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(strstr_word_path_test) {
  char *str = "King has name James";
  char *find = "am";

  ck_assert_ptr_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(strstr_empty_str_test) {
  char *str = "";
  char *find = "mes";

  ck_assert_ptr_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(strstr_empty_find_test) {
  char *str = "King has name James";
  char *find = "";

  ck_assert_ptr_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(strstr_find_zero_test) {
  char *str = "King has name James";
  char *find = "\0";

  ck_assert_ptr_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

Suite *strstr_tests() {
  Suite *suite = suite_create("strstr_tests");
  TCase *testCase = tcase_create("strstr_test_case");

  tcase_add_test(testCase, strstr_standart_test);
  tcase_add_test(testCase, strstr_word_path_test);
  tcase_add_test(testCase, strstr_empty_str_test);
  tcase_add_test(testCase, strstr_empty_find_test);
  tcase_add_test(testCase, strstr_find_zero_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
