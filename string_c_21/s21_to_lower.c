#include <stdlib.h>

#include "./s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = S21_NULL;
  if (str) {
    s21_size_t size = s21_strlen(str);
    if (size > 0) {
      result = malloc((size + 1) * sizeof(char));
      for (s21_size_t i = 0; i <= size; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
          result[i] = str[i] + 32;
        } else {
          result[i] = str[i];
        }
      }
    } else {
      result = "";
    }
  }
  return result;
}