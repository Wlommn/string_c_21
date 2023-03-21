#include "./s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_size = s21_strlen(src);
  if (src_size < n) {
    s21_memset(dest + src_size, '\0', n - src_size);
  }
  s21_memcpy(dest, src, n);
  return dest;
}
