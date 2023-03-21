#include "../s21_string_test.h"

START_TEST(memcmp_zero_bytes_test) {
  char *str = "King";
  char *str2 = "King";
  s21_size_t n = 0;

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(memcmp_first_gr_test) {
  char *str = "Cesar";
  char *str2 = "King";
  s21_size_t n = 5;
  int result = memcmp(str, str2, n);
  int s21_result = s21_memcmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

START_TEST(memcmp_second_gr_test) {
  char *str = "King";
  char *str2 = "Cesar";
  s21_size_t n = 5;
  int result = memcmp(str, str2, n);
  int s21_result = s21_memcmp(str, str2, n);

  result = CastToStandart(result);
  s21_result = CastToStandart(s21_result);

  ck_assert_int_eq(result, s21_result);
}
END_TEST

Suite *memcmp_tests() {
  Suite *suite = suite_create("memcmp_tests");
  TCase *testCase = tcase_create("memcmp_test_case");

  tcase_add_test(testCase, memcmp_zero_bytes_test);
  tcase_add_test(testCase, memcmp_first_gr_test);
  tcase_add_test(testCase, memcmp_second_gr_test);

  suite_add_tcase(suite, testCase);
  return suite;
}
