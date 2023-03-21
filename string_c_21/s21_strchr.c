#include "./s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  bool breakPoint = false;
  do {
    if (*str == c) {
      result = (char *)str;
      breakPoint = true;
    }
  } while (*str++ && !breakPoint);
  return result;
}
