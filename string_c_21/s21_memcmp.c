#include "./s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *str1_temp = (const unsigned char *)str1;
  const unsigned char *str2_temp = (const unsigned char *)str2;
  int result = 0;

  while (n-- > 0 && result == 0) {
    result = *str1_temp - *str2_temp;
  }
  return result;
}
