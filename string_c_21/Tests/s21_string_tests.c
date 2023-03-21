#include "./s21_string_test.h"

int main() {
  static int count = 1;
  Suite *cases[TESTS];
  AddMemTests(cases);
  AddStrTests(cases);
  AddSharpTests(cases);
  AddSPrintfTests(cases);
  printf("\n");
  for (Suite **currentTest = cases; *currentTest != NULL; currentTest++) {
    printf("Current Test: %d\n", count);
    count++;
    SRunner *runner = srunner_create(*currentTest);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
    printf("\n");
  }
  return 0;
}

void AddMemTests(Suite **cases) {
  cases[0] = memchr_tests();
  cases[1] = memcmp_tests();
  cases[2] = memcpy_tests();
  cases[3] = memmove_tests();
  cases[4] = memset_tests();
}

void AddStrTests(Suite **cases) {
  cases[5] = strcat_tests();
  cases[6] = strncat_tests();
  cases[7] = strchr_tests();
  cases[8] = strcmp_tests();
  cases[9] = strncmp_tests();
  cases[10] = strcpy_tests();
  cases[11] = strncpy_tests();
  cases[12] = strcspn_tests();
  cases[13] = strerror_tests();
  cases[14] = strlen_tests();
  cases[15] = strpbrk_tests();
  cases[16] = strrchr_tests();
  cases[17] = strspn_tests();
  cases[18] = strstr_tests();
  cases[19] = strtok_tests();
}

void AddSharpTests(Suite **cases) {
  cases[20] = to_upper_tests();
  cases[21] = to_lower_tests();
  cases[22] = insert_tests();
  cases[23] = trim_tests();
}

void AddSPrintfTests(Suite **cases) {
  cases[24] = sprintf_spec_tests();
  cases[25] = sprintf_flag_tests();
  cases[26] = sprintf_width_tests();
  cases[27] = sprintf_length_tests();
  cases[28] = sprintf_precision_tests();
  cases[29] = NULL;
}

int CastToStandart(int casted) {
  int result = 0;
  if (casted > 0) {
    result = 1;
  } else if (casted < 0) {
    result = -1;
  }
  return result;
}
