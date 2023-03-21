#ifndef SRC_TESTS_S21_STRING_TESTS_H_
#define SRC_TESTS_S21_STRING_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

#define SSIZE 64
#define LSIZE 128
#define TESTS 30

Suite *memchr_tests();
Suite *memcmp_tests();
Suite *memcpy_tests();
Suite *memmove_tests();
Suite *memset_tests();

Suite *strcat_tests();
Suite *strncat_tests();
Suite *strchr_tests();
Suite *strcmp_tests();
Suite *strncmp_tests();
Suite *strcpy_tests();
Suite *strncpy_tests();
Suite *strcspn_tests();
Suite *strerror_tests();
Suite *strlen_tests();
Suite *strpbrk_tests();
Suite *strrchr_tests();
Suite *strspn_tests();
Suite *strstr_tests();
Suite *strtok_tests();

Suite *sprintf_spec_tests();
Suite *sprintf_flag_tests();
Suite *sprintf_width_tests();
Suite *sprintf_length_tests();
Suite *sprintf_precision_tests();

Suite *to_upper_tests();
Suite *to_lower_tests();
Suite *insert_tests();
Suite *trim_tests();

void AddMemTests(Suite **cases);
void AddStrTests(Suite **cases);
void AddSharpTests(Suite **cases);
void AddSPrintfTests(Suite **cases);

int CastToStandart(int casted);

#endif  //  SRC_TESTS_S21_STRING_TESTS_H_
