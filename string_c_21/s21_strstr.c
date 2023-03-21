#include "./s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  if (s21_strlen(needle) > 0) {
    if (*haystack) {
      const char *haystack_pos = haystack;
      const char *haystack_temp = haystack;
      const char *needle_temp = needle;
      bool breakPoint = false;
      while (!breakPoint && *needle_temp) {
        haystack_pos = haystack_temp;
        while (!breakPoint && (*(haystack_temp++) == *(needle_temp++))) {
          if (!(*needle_temp)) {
            result = (char *)haystack_pos;
            breakPoint = true;
          }
          if (!breakPoint && !(*haystack_temp)) {
            breakPoint = true;
          }
        }
        needle_temp = needle;
      }
    }
  } else {
    result = (char *)haystack;
  }
  return result;
}
