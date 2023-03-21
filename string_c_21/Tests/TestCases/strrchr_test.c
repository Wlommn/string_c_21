#include "../s21_string_test.h"

START_TEST(strrchr_standart_test) {
  char *str = "King has name James";
  char find = 'a';

  ck_assert_ptr_eq(strrchr(str, find), s21_strrchr(str, find));
}
END_TEST

START_TEST(strrchr_empty_str_test) {
  char *str = "";
  char find = 'a';

  ck_assert_ptr_eq(strrchr(str, find), s21_strrchr(str, find));
}
END_TEST

START_TEST(strrchr_not_find_test) {
  char *str = "King has name James";
  char find = ']';

  ck_assert_ptr_eq(strrchr(str, find), s21_strrchr(str, find));
}
END_TEST

START_TEST(strrchr_zero_find_test) {
  char *str = "King has name James";
  char find = '\0';

  ck_assert_ptr_eq(strrchr(str, find), s21_strrchr(str, find));
}
END_TEST

Suite *strrchr_tests() {
  Suite *suite = suite_create("strrchr_tests");
  TCase *testCase = tcase_create("strrchr_test_case");

  tcase_add_test(testCase, strrchr_standart_test);
  tcase_add_test(testCase, strrchr_empty_str_test);
  tcase_add_test(testCase, strrchr_not_find_test);
  tcase_add_test(testCase, strrchr_zero_find_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
