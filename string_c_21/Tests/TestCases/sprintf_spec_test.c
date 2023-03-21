#include "../s21_string_test.h"

START_TEST(sprintf_spec_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";

  sprintf(str, "000");
  s21_sprintf(s21_str, "000");

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_i_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %i ", n);
  s21_sprintf(s21_str, " %d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_d_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %d ", n);
  s21_sprintf(s21_str, " %d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_o_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 16;

  sprintf(str, " %o ", n);
  s21_sprintf(s21_str, " %o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_u_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2;

  sprintf(str, " %u ", n);
  s21_sprintf(s21_str, " %u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_x_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 16;

  sprintf(str, " %x ", n);
  s21_sprintf(s21_str, " %x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_X_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 5;

  sprintf(str, " %X ", n);
  s21_sprintf(s21_str, " %X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_c_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char ch = 'h';

  sprintf(str, " %c ", ch);
  s21_sprintf(s21_str, " %c ", ch);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_s_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %s ", string);
  s21_sprintf(s21_str, " %s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_p_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char string[SSIZE] = {'\0'};

  sprintf(str, " %p ", string);
  s21_sprintf(s21_str, " %p ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_f_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.3;

  sprintf(str, " %f ", n);
  s21_sprintf(s21_str, " %f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_e_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 123488.4;

  sprintf(str, " %e ", n);
  s21_sprintf(s21_str, " %e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_E_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 123456.0;

  sprintf(str, " %E ", n);
  s21_sprintf(s21_str, " %E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_g_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 123488.4;

  sprintf(str, " %g ", n);
  s21_sprintf(s21_str, " %g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_G_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 123456.0;

  sprintf(str, " %G ", n);
  s21_sprintf(s21_str, " %G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_spec_percent_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";

  sprintf(str, " %% ");
  s21_sprintf(s21_str, " %% ");

  ck_assert_str_eq(str, s21_str);
}
END_TEST

Suite *sprintf_spec_tests() {
  Suite *suite = suite_create("sprintf_spec_tests");
  TCase *testCase = tcase_create("sprintf_spec_test_case");

  tcase_add_test(testCase, sprintf_spec_standart_test);
  tcase_add_test(testCase, sprintf_spec_i_test);
  tcase_add_test(testCase, sprintf_spec_d_test);
  tcase_add_test(testCase, sprintf_spec_o_test);
  tcase_add_test(testCase, sprintf_spec_u_test);
  tcase_add_test(testCase, sprintf_spec_x_test);
  tcase_add_test(testCase, sprintf_spec_X_test);
  tcase_add_test(testCase, sprintf_spec_c_test);
  tcase_add_test(testCase, sprintf_spec_s_test);
  tcase_add_test(testCase, sprintf_spec_p_test);
  tcase_add_test(testCase, sprintf_spec_f_test);
  tcase_add_test(testCase, sprintf_spec_e_test);
  tcase_add_test(testCase, sprintf_spec_E_test);
  tcase_add_test(testCase, sprintf_spec_g_test);
  tcase_add_test(testCase, sprintf_spec_G_test);
  tcase_add_test(testCase, sprintf_spec_percent_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
