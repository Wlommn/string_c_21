#include <stdlib.h>

#include "./s21_string.h"

static void PutStr(char *dest, const char *str, s21_size_t *index);

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  if (src != S21_NULL && str != S21_NULL && s21_strlen(src) >= start_index) {
    s21_size_t result_size = s21_strlen(src) + s21_strlen(str) + 1;
    result = malloc(result_size * sizeof(char));
    result = s21_memset(result, '\0', result_size);
    for (s21_size_t i = 0, j = 0; i < result_size; i++) {
      if (i == start_index) {
        PutStr(result, str, &i);
      }
      result[i] = src[j];
      j++;
    }
  }
  return result;
}

static void PutStr(char *dest, const char *str, s21_size_t *index) {
  s21_size_t str_size = s21_strlen(str);
  for (s21_size_t j = 0; j < str_size; j++) {
    dest[*index] = str[j];
    *index += 1;
  }
}
