#include "./s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  if (str) {
    for (; str[result]; result++)
      ;
  }
  return result;
}
