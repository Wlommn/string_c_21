#include "./s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *result = s21_memcpy(dest, src, s21_strlen(src) + 1);
  return result;
}
