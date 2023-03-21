#include "../s21_string_test.h"

#define WCHAR_STR_SIZE 5

//  Integer Tests
START_TEST(sprintf_i_d_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long int n = __LONG_MAX__;

  sprintf(str, " %ld ", n);
  s21_sprintf(s21_str, " %ld ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_i_d_length_short_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  short int n = __SHRT_MAX__;

  sprintf(str, " %hd ", n);
  s21_sprintf(s21_str, " %hd ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Unsigned Tests
START_TEST(sprintf_o_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long unsigned int n = __UINT32_MAX__;

  sprintf(str, " %.4lo ", n);
  s21_sprintf(s21_str, " %.4lo ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_o_length_short_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  short unsigned int n = __UINT16_MAX__;

  sprintf(str, " %ho ", n);
  s21_sprintf(s21_str, " %ho ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Unsigned Tests
START_TEST(sprintf_u_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long unsigned int n = __UINT64_MAX__;

  sprintf(str, " %lu ", n);
  s21_sprintf(s21_str, " %lu ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_u_length_short_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  short unsigned int n = __UINT16_MAX__;

  sprintf(str, " %hu ", n);
  s21_sprintf(s21_str, " %hu ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

// Hex Tests
START_TEST(sprintf_x_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long unsigned int n = __UINT64_MAX__;

  sprintf(str, " %lx ", n);
  s21_sprintf(s21_str, " %lx ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long unsigned int n = __UINT64_MAX__;

  sprintf(str, " %lX ", n);
  s21_sprintf(s21_str, " %lX ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_x_length_short_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  short unsigned int n = __UINT16_MAX__;

  sprintf(str, " %hx ", n);
  s21_sprintf(s21_str, " %hx ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_X_length_short_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  short unsigned int n = __UINT16_MAX__;

  sprintf(str, " %hX ", n);
  s21_sprintf(s21_str, " %hX ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Float Tests
START_TEST(sprintf_f_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long double n = 23.89898988899898899;

  sprintf(str, " %Lf ", n);
  s21_sprintf(s21_str, " %Lf ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Char Tests
START_TEST(sprintf_c_length_wchar_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  wchar_t ch = 'h';

  sprintf(str, " %lc ", ch);
  s21_sprintf(s21_str, " %lc ", ch);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  String Tests
START_TEST(sprintf_s_length_wchar_test) {
  char str[LSIZE] = "abc123";
  char s21_str[LSIZE] = "abc123";
  wchar_t string[WCHAR_STR_SIZE] = {'0', '0', '0', '\0'};

  sprintf(str, " %ls ", string);
  s21_sprintf(s21_str, " %ls ", string);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Exp Tests
START_TEST(sprintf_e_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long double n = 23.898989;

  sprintf(str, " %Le ", n);
  s21_sprintf(s21_str, " %Le ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_E_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long double n = 22323.899898899;

  sprintf(str, " %LE ", n);
  s21_sprintf(s21_str, " %LE ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

//  Smarp Print Tests
START_TEST(sprintf_g_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long double n = 23.989;

  sprintf(str, " %Lg ", n);
  s21_sprintf(s21_str, " %Lg ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(sprintf_G_length_long_test) {
  char str[SSIZE] = "abc123";
  char s21_str[SSIZE] = "abc123";
  long double n = 22323.8;

  sprintf(str, " %LG ", n);
  s21_sprintf(s21_str, " %LG ", n);

  ck_assert_str_eq(str, s21_str);
}
END_TEST

static void AddI_DCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_i_d_length_long_test);
  tcase_add_test(testCase, sprintf_i_d_length_short_test);
}

static void AddO_UCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_o_length_long_test);
  tcase_add_test(testCase, sprintf_o_length_short_test);

  tcase_add_test(testCase, sprintf_u_length_long_test);
  tcase_add_test(testCase, sprintf_u_length_short_test);
}

static void AddC_SCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_c_length_wchar_test);

  tcase_add_test(testCase, sprintf_s_length_wchar_test);
}

static void AddX_xCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_x_length_long_test);
  tcase_add_test(testCase, sprintf_x_length_short_test);

  tcase_add_test(testCase, sprintf_X_length_long_test);
  tcase_add_test(testCase, sprintf_X_length_short_test);
}

static void AddFCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_f_length_long_test);
}

static void AddE_eCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_e_length_long_test);
  tcase_add_test(testCase, sprintf_E_length_long_test);
}

static void AddG_gCase(TCase *testCase) {
  tcase_add_test(testCase, sprintf_g_length_long_test);
  tcase_add_test(testCase, sprintf_G_length_long_test);
}

Suite *sprintf_length_tests() {
  Suite *suite = suite_create("sprintf_length_tests");
  TCase *testCase = tcase_create("sprintf_length_test_case");

  AddI_DCase(testCase);
  AddO_UCase(testCase);
  AddC_SCase(testCase);
  AddX_xCase(testCase);
  AddFCase(testCase);
  AddE_eCase(testCase);
  AddG_gCase(testCase);

  suite_add_tcase(suite, testCase);
  return suite;
}
