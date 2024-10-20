#include "../s21_string.h"

//Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
//которую указывает аргумент str.

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;

  while (*str != '\0') {
    if (*str == c) result = (char *)str;

    str++;
  }

  return result;
}