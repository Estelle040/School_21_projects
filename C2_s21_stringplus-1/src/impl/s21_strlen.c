#include "../s21_string.h"

// Вычисляет длину строки str, не включая завершающий нулевой символ.

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  while (str[count] != '\0') {
    count++;
  }

  return count;
}