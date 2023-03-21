#include "../s21_string_test.h"

#ifdef __linux__
#define ERR_LIST_SIZE 134
#endif

#ifdef __APPLE__
#define ERR_LIST_SIZE 107
#endif

START_TEST(strerror_standart_end_test) {
  int n = ERR_LIST_SIZE - 1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(strerror_standart_start_test) {
  int n = 0;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(strerror_standart_mid_test) {
  int n = ERR_LIST_SIZE / 2;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(strerror_unknown_test) {
#ifdef __linux__
  char *expected = "Unknown error 2500";
#elif __APPLE__
  char *expected = "Unknown error: 2500";
#endif
  ck_assert_str_eq(expected, s21_strerror(2500));
}
END_TEST

START_TEST(strerror_negative_unknown_test) {
#ifdef __linux__
  char *expected = "Unknown error -25";
#elif __APPLE__
  char *expected = "Unknown error: -25";
#endif
  ck_assert_str_eq(expected, s21_strerror(-25));
}
END_TEST

Suite *strerror_tests() {
  Suite *suite = suite_create("strerror_tests");
  TCase *testCase = tcase_create("strerror_test_case");

  tcase_add_test(testCase, strerror_standart_end_test);
  tcase_add_test(testCase, strerror_standart_start_test);
  tcase_add_test(testCase, strerror_standart_mid_test);
  tcase_add_test(testCase, strerror_unknown_test);
  tcase_add_test(testCase, strerror_negative_unknown_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
