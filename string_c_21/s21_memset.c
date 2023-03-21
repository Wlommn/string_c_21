#include "./s21_string.h"

void *s21_memset(void *src, int c, s21_size_t n) {
  unsigned char *ptr = src;
  while (n-- > 0) {
    *ptr++ = c;
  }
  return src;
}
