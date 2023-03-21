#include "./s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  const unsigned char *str1_temp = (const unsigned char *)str1;
  const unsigned char *str2_temp = (const unsigned char *)str2;
  bool breakPoint = false;
  int result = 0;
  while ((*str1_temp != '\0' || *str2_temp != '\0') && !breakPoint) {
    if (*str1_temp != *str2_temp) {
      result = *str1_temp - *str2_temp;
      breakPoint = true;
    }
    str1_temp++;
    str2_temp++;
  }
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  }
  return result;
}
