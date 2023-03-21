#include "../s21_string_test.h"

START_TEST(strcspn_standart_test) {
  char *str = "King James";
  char *rej = " ";

  ck_assert_int_eq(strcspn(str, rej), s21_strcspn(str, rej));
}
END_TEST

START_TEST(strcspn_empty_test) {
  char *str = "";
  char *rej = "";

  ck_assert_int_eq(strcspn(str, rej), s21_strcspn(str, rej));
}
END_TEST

START_TEST(strcspn_empty_str_test) {
  char *str = "";
  char *rej = "N";

  ck_assert_int_eq(strcspn(str, rej), s21_strcspn(str, rej));
}
END_TEST

START_TEST(strcspn_empty_rej_test) {
  char *str = "King James";
  char *rej = "";

  ck_assert_int_eq(strcspn(str, rej), s21_strcspn(str, rej));
}
END_TEST

START_TEST(strcspn_rej_str_test) {
  char *str = "James was King";
  char *rej = "as";

  ck_assert_int_eq(strcspn(str, rej), s21_strcspn(str, rej));
}
END_TEST

Suite *strcspn_tests() {
  Suite *suite = suite_create("strcspn_tests");
  TCase *testCase = tcase_create("strcspn_test_case");

  tcase_add_test(testCase, strcspn_standart_test);
  tcase_add_test(testCase, strcspn_empty_test);
  tcase_add_test(testCase, strcspn_empty_str_test);
  tcase_add_test(testCase, strcspn_empty_rej_test);
  tcase_add_test(testCase, strcspn_rej_str_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
