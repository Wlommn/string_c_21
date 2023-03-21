#include "../s21_string_test.h"

#define WCHAR_STR_SIZE 5

//  Integer Tests
START_TEST(sprintf_i_d_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2345;

  sprintf(str, " %.2d ", n);
  s21_sprintf(s21_str, " %.2d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 0;

  sprintf(str, " %.0d ", n);
  s21_sprintf(s21_str, " %.0d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 223;

  sprintf(str, " %.5d ", n);
  s21_sprintf(s21_str, " %.5d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 223;

  sprintf(str, " %2.5d ", n);
  s21_sprintf(s21_str, " %2.5d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_precision_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 223;

  sprintf(str, " %.1d ", n);
  s21_sprintf(s21_str, " %.1d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 223;

  sprintf(str, " %.*d ", 2, n);
  s21_sprintf(s21_str, " %.*d ", 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Octal Tests
START_TEST(sprintf_o_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %.4o ", n);
  s21_sprintf(s21_str, " %.4o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 0;

  sprintf(str, " %.0o ", n);
  s21_sprintf(s21_str, " %.0o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.5o ", n);
  s21_sprintf(s21_str, " %.5o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %2.5o ", n);
  s21_sprintf(s21_str, " %2.5o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_precision_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.1o ", n);
  s21_sprintf(s21_str, " %.1o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.*o ", 1, n);
  s21_sprintf(s21_str, " %.*o ", 1, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Unsigned Tests
START_TEST(sprintf_u_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %.4u ", n);
  s21_sprintf(s21_str, " %.4u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 0;

  sprintf(str, " %.0u ", n);
  s21_sprintf(s21_str, " %.0u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.5u ", n);
  s21_sprintf(s21_str, " %.5u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %2.5u ", n);
  s21_sprintf(s21_str, " %2.5u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_precision_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.1u ", n);
  s21_sprintf(s21_str, " %.1u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.*u ", 1, n);
  s21_sprintf(s21_str, " %.*u ", 1, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Hex Tests
START_TEST(sprintf_x_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %.4x ", n);
  s21_sprintf(s21_str, " %.4x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 4233;

  sprintf(str, " %.4X ", n);
  s21_sprintf(s21_str, " %.4X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 0;

  sprintf(str, " %.0x ", n);
  s21_sprintf(s21_str, " %.0x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 0;

  sprintf(str, " %.0X ", n);
  s21_sprintf(s21_str, " %.0X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.5x ", n);
  s21_sprintf(s21_str, " %.5x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2237878;

  sprintf(str, " %.13X ", n);
  s21_sprintf(s21_str, " %.13X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 9077;

  sprintf(str, " %6.5x ", n);
  s21_sprintf(s21_str, " %6.5x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 78;

  sprintf(str, " %3.5X ", n);
  s21_sprintf(s21_str, " %3.5X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_precision_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.1x ", n);
  s21_sprintf(s21_str, " %.1x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_precision_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.1X ", n);
  s21_sprintf(s21_str, " %.1X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 22903;

  sprintf(str, " %.*x ", 2, n);
  s21_sprintf(s21_str, " %.*x ", 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223;

  sprintf(str, " %.*X ", 1, n);
  s21_sprintf(s21_str, " %.*X ", 1, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  String Tests
START_TEST(sprintf_s_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "1234";

  sprintf(str, " %.4s ", string);
  s21_sprintf(s21_str, " %.4s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_s_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "1234";

  sprintf(str, " %.0s ", string);
  s21_sprintf(s21_str, " %.0s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_s_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "1234";

  sprintf(str, " %.6s ", string);
  s21_sprintf(s21_str, " %.6s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_s_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "1234";

  sprintf(str, " %.*s ", 6, string);
  s21_sprintf(s21_str, " %.*s ", 6, string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Float Tests
START_TEST(sprintf_f_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 20.03;

  sprintf(str, " %.2f ", n);
  s21_sprintf(s21_str, " %.2f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 30.02;

  sprintf(str, " %.0f ", n);
  s21_sprintf(s21_str, " %.0f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 0.1;

  sprintf(str, " %.7f ", n);
  s21_sprintf(s21_str, " %.7f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %3.7f ", n);
  s21_sprintf(s21_str, " %3.7f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %.*f ", 7, n);
  s21_sprintf(s21_str, " %.*f ", 7, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Exp Tests
START_TEST(sprintf_e_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 20.03;

  sprintf(str, " %.2e ", n);
  s21_sprintf(s21_str, " %.2e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 2890.023;

  sprintf(str, " %.2E ", n);
  s21_sprintf(s21_str, " %.2E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 642.09;

  sprintf(str, " %.0e ", n);
  s21_sprintf(s21_str, " %.0e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 642.09;

  sprintf(str, " %.0E ", n);
  s21_sprintf(s21_str, " %.0E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 0.1;

  sprintf(str, " %.13e ", n);
  s21_sprintf(s21_str, " %.13e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 0.1;

  sprintf(str, " %.13E ", n);
  s21_sprintf(s21_str, " %.13E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %3.7e ", n);
  s21_sprintf(s21_str, " %3.7e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %3.7E ", n);
  s21_sprintf(s21_str, " %3.7E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %.*e ", 7, n);
  s21_sprintf(s21_str, " %.*e ", 7, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %.*E ", 7, n);
  s21_sprintf(s21_str, " %.*E ", 7, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Smart Print Tests
START_TEST(sprintf_g_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 20.03;

  sprintf(str, " %.2g ", n);
  s21_sprintf(s21_str, " %.2g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_precision_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 2890.023;

  sprintf(str, " %.2G ", n);
  s21_sprintf(s21_str, " %.2G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 642.09;

  sprintf(str, " %.0g ", n);
  s21_sprintf(s21_str, " %.0g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_precision_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 6422121.09;

  sprintf(str, " %.0G ", n);
  s21_sprintf(s21_str, " %.0G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 0.1;

  sprintf(str, " %.13g ", n);
  s21_sprintf(s21_str, " %.13g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_precision_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 0.1;

  sprintf(str, " %.13G ", n);
  s21_sprintf(s21_str, " %.13G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %3.7g ", n);
  s21_sprintf(s21_str, " %3.7g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_precision_width_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 5.55;

  sprintf(str, " %3.7G ", n);
  s21_sprintf(s21_str, " %3.7G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55.55;

  sprintf(str, " %.*g ", 7, n);
  s21_sprintf(s21_str, " %.*g ", 7, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_precision_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 1234567.55;

  sprintf(str, " %.*G ", 7, n);
  s21_sprintf(s21_str, " %.*G ", 7, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

static void AddI_DCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_i_d_precision_test);
  tcase_add_test(testCase, sprintf_i_d_precision_zero_test);
  tcase_add_test(testCase, sprintf_i_d_precision_gr_test);
  tcase_add_test(testCase, sprintf_i_d_precision_width_test);
  tcase_add_test(testCase, sprintf_i_d_precision_le_test);
  tcase_add_test(testCase, sprintf_i_d_precision_star_test);
}

static void AddO_UCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_o_precision_test);
  tcase_add_test(testCase, sprintf_o_precision_zero_test);
  tcase_add_test(testCase, sprintf_o_precision_gr_test);
  tcase_add_test(testCase, sprintf_o_precision_width_test);
  tcase_add_test(testCase, sprintf_o_precision_le_test);
  tcase_add_test(testCase, sprintf_o_precision_star_test);

  tcase_add_test(testCase, sprintf_u_precision_test);
  tcase_add_test(testCase, sprintf_u_precision_zero_test);
  tcase_add_test(testCase, sprintf_u_precision_gr_test);
  tcase_add_test(testCase, sprintf_u_precision_width_test);
  tcase_add_test(testCase, sprintf_u_precision_le_test);
  tcase_add_test(testCase, sprintf_u_precision_star_test);
}

static void AddSCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_s_precision_test);
  tcase_add_test(testCase, sprintf_s_precision_zero_test);
  tcase_add_test(testCase, sprintf_s_precision_gr_test);
  tcase_add_test(testCase, sprintf_s_precision_star_test);
}

static void AddX_xCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_x_precision_test);
  tcase_add_test(testCase, sprintf_x_precision_zero_test);
  tcase_add_test(testCase, sprintf_x_precision_gr_test);
  tcase_add_test(testCase, sprintf_x_precision_width_test);
  tcase_add_test(testCase, sprintf_x_precision_le_test);
  tcase_add_test(testCase, sprintf_x_precision_star_test);

  tcase_add_test(testCase, sprintf_X_precision_test);
  tcase_add_test(testCase, sprintf_X_precision_zero_test);
  tcase_add_test(testCase, sprintf_X_precision_gr_test);
  tcase_add_test(testCase, sprintf_X_precision_width_test);
  tcase_add_test(testCase, sprintf_X_precision_le_test);
  tcase_add_test(testCase, sprintf_X_precision_star_test);
}

static void AddFCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_f_precision_test);
  tcase_add_test(testCase, sprintf_f_precision_zero_test);
  tcase_add_test(testCase, sprintf_f_precision_gr_test);
  tcase_add_test(testCase, sprintf_f_precision_width_test);
  tcase_add_test(testCase, sprintf_f_precision_star_test);
}

static void AddE_eCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_e_precision_test);
  tcase_add_test(testCase, sprintf_e_precision_zero_test);
  tcase_add_test(testCase, sprintf_e_precision_gr_test);
  tcase_add_test(testCase, sprintf_e_precision_width_test);
  tcase_add_test(testCase, sprintf_e_precision_star_test);

  tcase_add_test(testCase, sprintf_E_precision_test);
  tcase_add_test(testCase, sprintf_E_precision_zero_test);
  tcase_add_test(testCase, sprintf_E_precision_gr_test);
  tcase_add_test(testCase, sprintf_E_precision_width_test);
  tcase_add_test(testCase, sprintf_E_precision_star_test);
}

static void AddG_gCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_g_precision_test);
  tcase_add_test(testCase, sprintf_g_precision_zero_test);
  tcase_add_test(testCase, sprintf_g_precision_gr_test);
  tcase_add_test(testCase, sprintf_g_precision_width_test);
  tcase_add_test(testCase, sprintf_g_precision_star_test);

  tcase_add_test(testCase, sprintf_G_precision_test);
  tcase_add_test(testCase, sprintf_G_precision_zero_test);
  tcase_add_test(testCase, sprintf_G_precision_gr_test);
  tcase_add_test(testCase, sprintf_G_precision_width_test);
  tcase_add_test(testCase, sprintf_G_precision_star_test);
}

Suite *sprintf_precision_tests() {
  Suite *suite = suite_create("sprintf_precision_tests");
  TCase *testCase = tcase_create("sprintf_precision_test_case");

  AddI_DCase(testCase);
  AddO_UCase(testCase);
  AddX_xCase(testCase);
  AddSCase(testCase);
  AddFCase(testCase);
  AddE_eCase(testCase);
  AddG_gCase(testCase);

  suite_add_tcase(suite, testCase);
  return suite;
}
