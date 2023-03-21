#include "./s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *str_temp = (const unsigned char *)str;
  void *result = S21_NULL;
  bool breakPoint = false;
  if (str_temp) {
    while (n-- > 0 && !breakPoint) {
      if (*str_temp == c) {
        result = (void *)str_temp;
        breakPoint = true;
      } else {
        str_temp++;
      }
    }
  }
  return result;
}
