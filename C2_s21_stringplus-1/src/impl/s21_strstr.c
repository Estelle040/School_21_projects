#include "../s21_string.h"

// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t hayLen = s21_strlen(haystack);
  s21_size_t needLen = s21_strlen(needle);

  const char *result = s21_NULL;
  if (needle[0] == '\0') {
    result = haystack;
  } else {
    s21_size_t i = 0;
    while (i <= hayLen - needLen && result == s21_NULL) {
      s21_size_t j = 0;
      while (j < needLen && haystack[i + j] == needle[j]) {
        j++;
      }

      if (j == needLen) {
        result = &haystack[i];
      }

      i++;
    }
  }

  return (char *)result;
}