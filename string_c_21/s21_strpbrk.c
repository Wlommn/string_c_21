#include "./s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *result = S21_NULL;
  bool find = false;
  for (int i = 0; !find && str1[i]; i++) {
    for (int j = 0; !find && str2[j]; j++) {
      if (str1[i] == str2[j]) {
        result = str1 + i;
        find = true;
      }
    }
  }
  return (char *)result;
}
