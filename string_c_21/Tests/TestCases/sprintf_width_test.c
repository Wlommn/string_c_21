#include "../s21_string_test.h"

//  Integer Tests
START_TEST(sprintf_i_d_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 23;

  sprintf(str, " %2d ", n);
  s21_sprintf(s21_str, " %2d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2345;

  sprintf(str, " %8d ", n);
  s21_sprintf(s21_str, " %8d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %2d ", n);
  s21_sprintf(s21_str, " %2d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %*d ", 4, n);
  s21_sprintf(s21_str, " %*d ", 4, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 223;

  sprintf(str, " %*.*d ", 4, 2, n);
  s21_sprintf(s21_str, " %*.*d ", 4, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Octal Tests
START_TEST(sprintf_o_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 88;

  sprintf(str, " %2o ", n);
  s21_sprintf(s21_str, " %2o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %8o ", n);
  s21_sprintf(s21_str, " %8o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 26575;

  sprintf(str, " %2o ", n);
  s21_sprintf(s21_str, " %2o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 5675;

  sprintf(str, " %*o ", 5, n);
  s21_sprintf(s21_str, " %*o ", 5, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 29093;

  sprintf(str, " %*.*o ", 4, 2, n);
  s21_sprintf(s21_str, " %*.*o ", 4, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Unsigned Tests
START_TEST(sprintf_u_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 23;

  sprintf(str, " %2u ", n);
  s21_sprintf(s21_str, " %2u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %6u ", n);
  s21_sprintf(s21_str, " %6u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 223232;

  sprintf(str, " %2u ", n);
  s21_sprintf(s21_str, " %2u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 5675;

  sprintf(str, " %*u ", 5, n);
  s21_sprintf(s21_str, " %*u ", 5, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 29093;

  sprintf(str, " %*.*u ", 4, 2, n);
  s21_sprintf(s21_str, " %*.*u ", 4, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Hex Tests
START_TEST(sprintf_x_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 23;

  sprintf(str, " %2x ", n);
  s21_sprintf(s21_str, " %2x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 23;

  sprintf(str, " %2X ", n);
  s21_sprintf(s21_str, " %2X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %6x ", n);
  s21_sprintf(s21_str, " %6x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2345;

  sprintf(str, " %8X ", n);
  s21_sprintf(s21_str, " %8X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 23232;

  sprintf(str, " %2x ", n);
  s21_sprintf(s21_str, " %2x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2232;

  sprintf(str, " %2X ", n);
  s21_sprintf(s21_str, " %2X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 5675;

  sprintf(str, " %*x ", 5, n);
  s21_sprintf(s21_str, " %*x ", 5, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 886642;

  sprintf(str, " %*X ", 5, n);
  s21_sprintf(s21_str, " %*X ", 5, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 29093;

  sprintf(str, " %*.*x ", 4, 2, n);
  s21_sprintf(s21_str, " %*.*x ", 4, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 2093;

  sprintf(str, " %*.*X ", 4, 2, n);
  s21_sprintf(s21_str, " %*.*X ", 4, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Char Tests
START_TEST(sprintf_c_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char ch = 'h';

  sprintf(str, " %3c ", ch);
  s21_sprintf(s21_str, " %3c ", ch);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_c_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char ch = 'h';

  sprintf(str, " %*c ", 5, ch);
  s21_sprintf(s21_str, " %*c ", 5, ch);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  String Tests
START_TEST(sprintf_s_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %3s ", string);
  s21_sprintf(s21_str, " %3s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_s_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %5s ", string);
  s21_sprintf(s21_str, " %5s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_s_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %2s ", string);
  s21_sprintf(s21_str, " %2s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_s_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %*s ", 2, string);
  s21_sprintf(s21_str, " %*s ", 2, string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Float Tests
START_TEST(sprintf_f_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 22.3;

  sprintf(str, " %4f ", n);
  s21_sprintf(s21_str, " %4f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2345.23323;

  sprintf(str, " %2f ", n);
  s21_sprintf(s21_str, " %2f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %5f ", n);
  s21_sprintf(s21_str, " %5f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 222.0;

  sprintf(str, " %*f ", 6, n);
  s21_sprintf(s21_str, " %*f ", 6, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %*.*f ", 2, 2, n);
  s21_sprintf(s21_str, " %*.*f ", 2, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Exp Tests
START_TEST(sprintf_e_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 22.333;

  sprintf(str, " %4e ", n);
  s21_sprintf(s21_str, " %4e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 211;

  sprintf(str, " %4E ", n);
  s21_sprintf(s21_str, " %4E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2345.323;

  sprintf(str, " %2e ", n);
  s21_sprintf(s21_str, " %2e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2345.223;

  sprintf(str, " %2E ", n);
  s21_sprintf(s21_str, " %2E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %5e ", n);
  s21_sprintf(s21_str, " %5e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %5E ", n);
  s21_sprintf(s21_str, " %5E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 222.0;

  sprintf(str, " %*e ", 6, n);
  s21_sprintf(s21_str, " %*e ", 6, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 222.0;

  sprintf(str, " %*E ", 6, n);
  s21_sprintf(s21_str, " %*E ", 6, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %*.*e ", 2, 2, n);
  s21_sprintf(s21_str, " %*.*e ", 2, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %*.*E ", 2, 2, n);
  s21_sprintf(s21_str, " %*.*E ", 2, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Smart Print Tests
START_TEST(sprintf_g_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 22.333;

  sprintf(str, " %4g ", n);
  s21_sprintf(s21_str, " %4g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_width_num_standart_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 211;

  sprintf(str, " %4G ", n);
  s21_sprintf(s21_str, " %4G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2345.323;

  sprintf(str, " %2g ", n);
  s21_sprintf(s21_str, " %2g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_width_num_gr_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2345.223;

  sprintf(str, " %2G ", n);
  s21_sprintf(s21_str, " %2G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %5g ", n);
  s21_sprintf(s21_str, " %5g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_width_num_le_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %5G ", n);
  s21_sprintf(s21_str, " %5G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 222.0;

  sprintf(str, " %*g ", 6, n);
  s21_sprintf(s21_str, " %*g ", 6, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_width_star_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 222.0;

  sprintf(str, " %*G ", 6, n);
  s21_sprintf(s21_str, " %*G ", 6, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %*.*g ", 2, 2, n);
  s21_sprintf(s21_str, " %*.*g ", 2, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_width_star_prec_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.0;

  sprintf(str, " %*.*G ", 2, 2, n);
  s21_sprintf(s21_str, " %*.*G ", 2, 2, n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

static void AddI_DCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_i_d_width_num_standart_test);
  tcase_add_test(testCase, sprintf_i_d_width_num_gr_test);
  tcase_add_test(testCase, sprintf_i_d_width_num_le_test);
  tcase_add_test(testCase, sprintf_i_d_width_star_test);
  tcase_add_test(testCase, sprintf_i_d_width_star_prec_test);
}

static void AddO_UCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_o_width_num_standart_test);
  tcase_add_test(testCase, sprintf_o_width_num_gr_test);
  tcase_add_test(testCase, sprintf_o_width_num_le_test);
  tcase_add_test(testCase, sprintf_o_width_star_test);
  tcase_add_test(testCase, sprintf_o_width_star_prec_test);

  tcase_add_test(testCase, sprintf_u_width_num_standart_test);
  tcase_add_test(testCase, sprintf_u_width_num_gr_test);
  tcase_add_test(testCase, sprintf_u_width_num_le_test);
  tcase_add_test(testCase, sprintf_u_width_star_test);
  tcase_add_test(testCase, sprintf_u_width_star_prec_test);
}

static void AddX_xCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_x_width_num_standart_test);
  tcase_add_test(testCase, sprintf_x_width_num_gr_test);
  tcase_add_test(testCase, sprintf_x_width_num_le_test);
  tcase_add_test(testCase, sprintf_x_width_star_test);
  tcase_add_test(testCase, sprintf_x_width_star_prec_test);

  tcase_add_test(testCase, sprintf_X_width_num_standart_test);
  tcase_add_test(testCase, sprintf_X_width_num_gr_test);
  tcase_add_test(testCase, sprintf_X_width_num_le_test);
  tcase_add_test(testCase, sprintf_X_width_star_test);
  tcase_add_test(testCase, sprintf_X_width_star_prec_test);
}

static void AddC_SCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_c_width_num_standart_test);
  tcase_add_test(testCase, sprintf_c_width_star_test);

  tcase_add_test(testCase, sprintf_s_width_num_standart_test);
  tcase_add_test(testCase, sprintf_s_width_num_gr_test);
  tcase_add_test(testCase, sprintf_s_width_num_le_test);
  tcase_add_test(testCase, sprintf_s_width_star_test);
}

static void AddFCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_f_width_num_standart_test);
  tcase_add_test(testCase, sprintf_f_width_num_gr_test);
  tcase_add_test(testCase, sprintf_f_width_num_le_test);
  tcase_add_test(testCase, sprintf_f_width_star_test);
  tcase_add_test(testCase, sprintf_f_width_star_prec_test);
}

static void AddE_eCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_e_width_num_standart_test);
  tcase_add_test(testCase, sprintf_e_width_num_gr_test);
  tcase_add_test(testCase, sprintf_e_width_num_le_test);
  tcase_add_test(testCase, sprintf_e_width_star_test);
  tcase_add_test(testCase, sprintf_e_width_star_prec_test);

  tcase_add_test(testCase, sprintf_E_width_num_standart_test);
  tcase_add_test(testCase, sprintf_E_width_num_gr_test);
  tcase_add_test(testCase, sprintf_E_width_num_le_test);
  tcase_add_test(testCase, sprintf_E_width_star_test);
  tcase_add_test(testCase, sprintf_E_width_star_prec_test);
}

static void AddG_gCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_g_width_num_standart_test);
  tcase_add_test(testCase, sprintf_g_width_num_gr_test);
  tcase_add_test(testCase, sprintf_g_width_num_le_test);
  tcase_add_test(testCase, sprintf_g_width_star_test);
  tcase_add_test(testCase, sprintf_g_width_star_prec_test);

  tcase_add_test(testCase, sprintf_G_width_num_standart_test);
  tcase_add_test(testCase, sprintf_G_width_num_gr_test);
  tcase_add_test(testCase, sprintf_G_width_num_le_test);
  tcase_add_test(testCase, sprintf_G_width_star_test);
  tcase_add_test(testCase, sprintf_G_width_star_prec_test);
}

Suite *sprintf_width_tests() {
  Suite *suite = suite_create("sprintf_width_tests");
  TCase *testCase = tcase_create("sprintf_width_test_case");

  AddI_DCase(testCase);
  AddO_UCase(testCase);
  AddX_xCase(testCase);
  AddC_SCase(testCase);
  AddFCase(testCase);
  AddE_eCase(testCase);
  AddG_gCase(testCase);

  suite_add_tcase(suite, testCase);
  return suite;
}
