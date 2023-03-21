#include "./s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t lentghStr1 = s21_strlen(str1);
  bool breakPoint = false;
  while (!breakPoint && result < lentghStr1) {
    if (s21_strchr(str2, str1[result]) == S21_NULL) {
      breakPoint = true;
    }
    if (!breakPoint) {
      result++;
    }
  }
  return result;
}
