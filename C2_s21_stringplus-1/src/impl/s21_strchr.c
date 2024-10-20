#include "../s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;

  while (*str != '\0' && *str != c) {
    str++;
  }

  if (*str != '\0') {
    result = (char *)str;
  }

  return result;
}