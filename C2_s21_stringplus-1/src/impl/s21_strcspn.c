#include "../s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int flag = 0;

  while (*str1 != '\0' && !flag) {
    if (!isInStr(*str1, str2)) {  // там если что '!'
      count++;
    } else {
      flag = 1;
    }
    str1++;
  }

  return count;
}