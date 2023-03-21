#include "../s21_string_test.h"

//  Integer Tests
START_TEST(sprintf_i_d_flag_minus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %-d ", n);
  s21_sprintf(s21_str, " %-d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_flag_plus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %+d ", n);
  s21_sprintf(s21_str, " %+d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_flag_plus_neg_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = -2;

  sprintf(str, " %+d ", n);
  s21_sprintf(s21_str, " %+d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_flag_space_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " % d ", n);
  s21_sprintf(s21_str, " % d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 2;

  sprintf(str, " %04d ", n);
  s21_sprintf(s21_str, " %04d ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Octal Tests
START_TEST(sprintf_o_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  int n = 89;

  sprintf(str, " %-o ", n);
  s21_sprintf(s21_str, " %-o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 24555;

  sprintf(str, " %010o ", n);
  s21_sprintf(s21_str, " %010o ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Hex Tests
START_TEST(sprintf_x_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  int n = 122;

  sprintf(str, " %-x ", n);
  s21_sprintf(s21_str, " %-x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  int n = 122;

  sprintf(str, " %-X ", n);
  s21_sprintf(s21_str, " %-X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_flag_sharp_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 6425;

  sprintf(str, " %#x ", n);
  s21_sprintf(s21_str, " %#x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_flag_sharp_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 6425;

  sprintf(str, " %#X ", n);
  s21_sprintf(s21_str, " %#X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 55;

  sprintf(str, " %04x ", n);
  s21_sprintf(s21_str, " %04x ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  int n = 88;

  sprintf(str, " %04X ", n);
  s21_sprintf(s21_str, " %04X ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Float Tests
START_TEST(sprintf_f_flag_minus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.3;

  sprintf(str, " %-f ", n);
  s21_sprintf(s21_str, " %-f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_flag_plus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.3;

  sprintf(str, " %+f ", n);
  s21_sprintf(s21_str, " %+f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_flag_plus_neg_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = -2.3;

  sprintf(str, " %+f ", n);
  s21_sprintf(s21_str, " %+f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_flag_space_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2.3;

  sprintf(str, " % f ", n);
  s21_sprintf(s21_str, " % f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_flag_sharp_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 222.0;

  sprintf(str, " %#f ", n);
  s21_sprintf(s21_str, " %#f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_f_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  float n = 2222.33;

  sprintf(str, " %010f ", n);
  s21_sprintf(s21_str, " %010f ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Char Tests
START_TEST(sprintf_c_flag_minus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char ch = 'h';

  sprintf(str, " %-c ", ch);
  s21_sprintf(s21_str, " %-c ", ch);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  String Tests
START_TEST(sprintf_s_flag_minus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %-s ", string);
  s21_sprintf(s21_str, " %-s ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Pointer Tests
START_TEST(sprintf_p_flag_minus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  char *string = "000";

  sprintf(str, " %-p ", string);
  s21_sprintf(s21_str, " %-p ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Exp Tests
START_TEST(sprintf_e_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  double n = 178;

  sprintf(str, " %-e ", n);
  s21_sprintf(s21_str, " %-e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  double n = 182;

  sprintf(str, " %-E ", n);
  s21_sprintf(s21_str, " %-E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_flag_sharp_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  double n = 641;

  sprintf(str, " %#e ", n);
  s21_sprintf(s21_str, " %#e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_flag_sharp_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 6425;

  sprintf(str, " %#E ", n);
  s21_sprintf(s21_str, " %#E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_e_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55;

  sprintf(str, " %010e ", n);
  s21_sprintf(s21_str, " %010e ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 88;

  sprintf(str, " %010E ", n);
  s21_sprintf(s21_str, " %010E ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Smart Print Tests
START_TEST(sprintf_g_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  double n = 123456;

  sprintf(str, " %-g ", n);
  s21_sprintf(s21_str, " %-g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_flag_minus_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  double n = 12345678;

  sprintf(str, " %-G ", n);
  s21_sprintf(s21_str, " %-G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_flag_sharp_test) {
  char str[SSIZE] = {'\0'};
  char s21_str[SSIZE] = {'\0'};
  double n = 641;

  sprintf(str, " %#g ", n);
  s21_sprintf(s21_str, " %#g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_flag_sharp_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 690990.2;

  sprintf(str, " %#G ", n);
  s21_sprintf(s21_str, " %#G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_g_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 55;

  sprintf(str, " %010g ", n);
  s21_sprintf(s21_str, " %010g ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_flag_zero_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  double n = 8888888;

  sprintf(str, " %010G ", n);
  s21_sprintf(s21_str, " %010G ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Unsigned Tests
START_TEST(sprintf_u_flag_minus_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  unsigned int n = 3;

  sprintf(str, " %-5u ", n);
  s21_sprintf(s21_str, " %-5u ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

static void AddI_DCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_i_d_flag_minus_test);
  tcase_add_test(testCase, sprintf_i_d_flag_plus_test);
  tcase_add_test(testCase, sprintf_i_d_flag_plus_neg_test);
  tcase_add_test(testCase, sprintf_i_d_flag_space_test);
  tcase_add_test(testCase, sprintf_i_d_flag_zero_test);
}

static void AddO_UCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_o_flag_minus_test);
  tcase_add_test(testCase, sprintf_o_flag_zero_test);

  tcase_add_test(testCase, sprintf_u_flag_minus_test);
}

static void AddC_S_PCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_c_flag_minus_test);

  tcase_add_test(testCase, sprintf_s_flag_minus_test);

  tcase_add_test(testCase, sprintf_p_flag_minus_test);
}

static void AddX_xCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_x_flag_minus_test);
  tcase_add_test(testCase, sprintf_X_flag_minus_test);
  tcase_add_test(testCase, sprintf_x_flag_sharp_test);
  tcase_add_test(testCase, sprintf_X_flag_sharp_test);
  tcase_add_test(testCase, sprintf_x_flag_zero_test);
  tcase_add_test(testCase, sprintf_X_flag_zero_test);
}

static void AddFCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_f_flag_minus_test);
  tcase_add_test(testCase, sprintf_f_flag_plus_test);
  tcase_add_test(testCase, sprintf_f_flag_plus_neg_test);
  tcase_add_test(testCase, sprintf_f_flag_space_test);
  tcase_add_test(testCase, sprintf_f_flag_sharp_test);
  tcase_add_test(testCase, sprintf_f_flag_zero_test);
}

static void AddE_eCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_e_flag_minus_test);
  tcase_add_test(testCase, sprintf_E_flag_minus_test);
  tcase_add_test(testCase, sprintf_e_flag_sharp_test);
  tcase_add_test(testCase, sprintf_E_flag_sharp_test);
  tcase_add_test(testCase, sprintf_e_flag_zero_test);
  tcase_add_test(testCase, sprintf_E_flag_zero_test);
}

static void AddG_gCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_g_flag_minus_test);
  tcase_add_test(testCase, sprintf_G_flag_minus_test);
  tcase_add_test(testCase, sprintf_g_flag_sharp_test);
  tcase_add_test(testCase, sprintf_G_flag_sharp_test);
  tcase_add_test(testCase, sprintf_g_flag_zero_test);
  tcase_add_test(testCase, sprintf_G_flag_zero_test);
}

Suite *sprintf_flag_tests() {
  Suite *suite = suite_create("sprintf_flag_tests");
  TCase *testCase = tcase_create("sprintf_flag_test_case");

  AddI_DCase(testCase);
  AddO_UCase(testCase);
  AddC_S_PCase(testCase);
  AddX_xCase(testCase);
  AddFCase(testCase);
  AddE_eCase(testCase);
  AddG_gCase(testCase);

  suite_add_tcase(suite, testCase);
  return suite;
}
