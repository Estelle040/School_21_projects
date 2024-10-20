#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  for (int i = 0; str1[i] != '\0' && result == s21_NULL; i++) {
    if (isInStr(str1[i], str2)) {
      result = (char *)&str1[i];
    }
  }

  return result;
}