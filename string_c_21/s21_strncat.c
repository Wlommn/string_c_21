#include "./s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_temp = dest;
  dest_temp += s21_strlen(dest);
  s21_memcpy(dest_temp, src, n);
  dest[s21_strlen(dest)] = '\0';
  return dest;
}
