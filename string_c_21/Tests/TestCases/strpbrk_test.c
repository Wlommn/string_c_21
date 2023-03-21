#include "../s21_string_test.h"

START_TEST(strpbrk_standart_test) {
  char *str = "King James";
  char *find = "abc";

  ck_assert_ptr_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_empty_str_test) {
  char *str = "";
  char *find = "abc";

  ck_assert_ptr_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_empty_find_test) {
  char *str = "King James";
  char *find = "";

  ck_assert_ptr_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_not_find_test) {
  char *str = "King James";
  char *find = "ubo";

  ck_assert_ptr_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(strpbrk_zero_find_test) {
  char *str = "King James";
  char *find = "\0";

  ck_assert_ptr_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

Suite *strpbrk_tests() {
  Suite *suite = suite_create("strpbrk_tests");
  TCase *testCase = tcase_create("strpbrk_test_case");

  tcase_add_test(testCase, strpbrk_standart_test);
  tcase_add_test(testCase, strpbrk_empty_str_test);
  tcase_add_test(testCase, strpbrk_empty_find_test);
  tcase_add_test(testCase, strpbrk_not_find_test);
  tcase_add_test(testCase, strpbrk_zero_find_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
