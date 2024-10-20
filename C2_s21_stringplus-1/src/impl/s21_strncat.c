#include "../s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int destLen = s21_strlen(dest);

  s21_size_t i = 0;
  while (src[i] != '\0' && i < n) {
    dest[destLen + i] = src[i];
    i++;
  }

  return dest;
}