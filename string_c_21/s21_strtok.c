#include "./s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *olds = S21_NULL;
  char *result = S21_NULL;
  bool breakPoint = false;
  if (str == S21_NULL) {
    if (olds == S21_NULL) {
      breakPoint = true;
    }
    str = olds;
  }
  if (!breakPoint) {
    str += s21_strspn(str, delim);
    if (*str == '\0') {
      olds = str;
      result = S21_NULL;
      breakPoint = true;
    }
  }
  if (!breakPoint) {
    result = str;
    str = s21_strpbrk(result, delim);
    if (str == S21_NULL) {
      olds = S21_NULL;
    } else {
      *str = '\0';
      olds = str + 1;
    }
  }
  return result;
}
