#include <stdlib.h>

#include "./s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t size = s21_strlen(str);
    result = malloc((size + 1) * sizeof(char));
    for (s21_size_t i = 0; i <= size; i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        result[i] = str[i] - 32;
      } else {
        result[i] = str[i];
      }
    }
  }
  return result;
}
