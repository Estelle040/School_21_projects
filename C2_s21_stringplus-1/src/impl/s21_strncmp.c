#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0;

  while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0' && i < n) {
    i++;
  }

  if (i != n) {
    result = str1[i] - str2[i];
  }

  return result;
}