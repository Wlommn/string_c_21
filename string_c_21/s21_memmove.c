#include "./s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_temp = dest;
  const unsigned char *src_temp = src;
  if (dest_temp < src_temp) {
    while (n--) {
      *dest_temp++ = *src_temp++;
    }
  } else {
    const unsigned char *buf_src = src_temp + (n - 1);
    unsigned char *buf_dest = dest_temp + (n - 1);
    while (n--) {
      *buf_dest-- = *buf_src--;
    }
  }
  return dest;
}
