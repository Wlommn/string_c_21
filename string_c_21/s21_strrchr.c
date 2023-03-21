#include "./s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    do {
      if ((*str) == c) {
        result = (char *)str;
      }
    } while (*str++);
  }
  return result;
}
