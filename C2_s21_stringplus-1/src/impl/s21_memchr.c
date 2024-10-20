#include "../s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  const void *result;

  // идём по строке пока не наткнёмся на символ
  // или не дойдём до конца сектора памяти из N
  while (i < n && *(char *)str != c) {
    str++, i++;
  }

  // чекаем причину остановки цикла (успело ли набраться N)
  if (i < n) {
    result = str;
  } else {
    result = s21_NULL;
  }

  return (void *)result;
}