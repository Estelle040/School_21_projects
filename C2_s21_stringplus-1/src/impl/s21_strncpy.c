#include "../s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest.

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t srcLen = s21_strlen(src);

  for (s21_size_t i = 0; i < srcLen; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }

  for (s21_size_t i = srcLen; i < n; i++) {
    ((char *)dest)[i] = '\0';
  }

  return dest;
}