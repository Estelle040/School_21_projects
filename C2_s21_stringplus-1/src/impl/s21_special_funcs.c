#include <stdlib.h>

#include "../s21_string.h"

/*
!!ВАЖНО!!
все функции ниже динамически создают новую строку,
так что не забудьте прописать free после использования
*/

/*
Возвращает копию строки (str), преобразованной в верхний регистр.
В случае какой-либо ошибки следует вернуть значение NULL
*/

// короче я пытался сделать чтобы работало с русским алфавитом, но там фигня
// какая-то, так что пофиг

void *s21_to_upper(const char *str) {
  s21_size_t length = s21_strlen(str);
  char *newStr = (char *)malloc((length + 1) * sizeof(char));
  char *result = s21_NULL;

  if (newStr != NULL) {
    result = newStr;

    while (*str != '\0') {
      if ((*str >= 'a' && *str <= 'z')) {
        *newStr = *str - 32;
      } else {
        *newStr = *str;
      }

      newStr++, str++;
    }

    newStr[length] = '\0';
  }

  return result;
}

/*
Возвращает копию строки (str), преобразованной в нижний регистр.
В случае какой-либо ошибки следует вернуть значение NULL
*/

void *s21_to_lower(const char *str) {
  s21_size_t length = s21_strlen(str);
  char *newStr = (char *)malloc((length + 1) * sizeof(char));
  char *result = s21_NULL;

  if (newStr != NULL) {
    result = newStr;

    while (*str != '\0') {
      if ((*str >= 'A' && *str <= 'Z')) {
        *newStr = *str + 32;
      } else {
        *newStr = *str;
      }

      newStr++, str++;
    }

    newStr[length] = '\0';
  }

  return result;
}

/*
Возвращает новую строку, в которой указанная строка (str) вставлена в указанную
позицию (start_index) в данной строке (src). В случае какой-либо ошибки следует
вернуть значение NULL
*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t strLength = s21_strlen(str);  // sTR
  s21_size_t srcLength = s21_strlen(src);  // sRC
  char *newStr = (char *)malloc((strLength + srcLength + 1) * sizeof(char));
  char *result = s21_NULL;

  if (newStr != NULL && start_index <= srcLength) {
    result = newStr;

    for (s21_size_t i = 0; i < strLength + srcLength; i++) {
      if (i >= start_index && i < start_index + strLength && *str != '\0') {
        newStr[i] = *str;
        str++;
      } else if (*src != '\0') {
        newStr[i] = *src;
        src++;
      }
    }

    newStr[strLength + srcLength] = '\0';
  }

  return result;
}

/*
Возвращает новую строку, в которой удаляются все начальные
и конечные вхождения набора заданных символов (trim_chars) из данной строки
(src). В случае какой-либо ошибки следует вернуть значение NULL
*/

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t length = s21_strlen(src);
  s21_size_t start_index = 0, end_index = length;

  for (s21_size_t i = 0; i < length && isInStr(src[i], trim_chars); i++) {
    start_index++;
  }

  for (s21_size_t i = length - 1; i > 0 && isInStr(src[i], trim_chars); i--) {
    end_index--;
  }

  char *newStr = (char *)malloc((end_index - start_index + 1) * sizeof(char));
  char *result = s21_NULL;
  if (newStr != NULL) {
    result = newStr;

    for (s21_size_t i = start_index; i < end_index; i++) {
      *newStr = src[i];
      newStr++;
    }
  }

  return result;
}