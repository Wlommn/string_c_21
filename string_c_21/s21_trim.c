#include <stdlib.h>

#include "./s21_string.h"

#define DEFAULT_CHARS " \t\n\v\r\f\0"

static s21_size_t TrimStart(const char **src, const char *trim_chars);
static s21_size_t TrimEnd(const char **src, const char *trim_chars);

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;
  s21_size_t srcLength = 0;
  if (src && *src) {
    if (trim_chars && *trim_chars) {
      srcLength = TrimStart(&src, trim_chars);
      srcLength = TrimEnd(&src, trim_chars);
      result = malloc((srcLength + 1) * sizeof(char));
      if (result) {
        s21_memset(result, '\0', srcLength + 1);
        s21_memcpy(result, src, srcLength);
      }
    } else {
      result = s21_trim(src, DEFAULT_CHARS);
    }
  }
  return result;
}

static s21_size_t TrimStart(const char **src, const char *trim_chars) {
  s21_size_t srcLen = s21_strlen(*src);
  s21_size_t trimCharsLen = s21_strlen(trim_chars);
  s21_size_t i = 0;
  while (src && i != trimCharsLen) {
    if ((**src) == trim_chars[i]) {
      (*src)++;
      srcLen--;
      i = 0;
    } else {
      i++;
    }
  }
  return srcLen;
}

static s21_size_t TrimEnd(const char **src, const char *trim_chars) {
  s21_size_t srcLen = s21_strlen(*src);
  s21_size_t trimCharsLen = s21_strlen(trim_chars);
  if (srcLen) {
    s21_size_t i = 0;
    s21_size_t j = srcLen - 1;
    while (src && i != trimCharsLen) {
      if ((*src)[j] == trim_chars[i]) {
        j--;
        srcLen--;
        i = 0;
      } else {
        i++;
      }
    }
  }
  return srcLen;
}
