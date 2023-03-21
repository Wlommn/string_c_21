#include "./s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_temp = dest;
  const unsigned char *src_temp = src;
  while (n--) {
    *dest_temp++ = *src_temp++;
  }
  return dest;
}
