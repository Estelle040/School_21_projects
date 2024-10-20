#include "../s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.

char *s21_strtok(char *str, const char *delim) {
  static char *nextToken = s21_NULL;
  char *result;

  // если передана новая строка, начинаем разбор с начала
  if (str != s21_NULL) {
    nextToken = str;
  }

  // пропускаем начальные разделители
  while (*nextToken != '\0' && s21_strchr(delim, *nextToken) != s21_NULL) {
    nextToken++;
  }

  // если достигнут конец строки, возвращаем NULL
  if (*nextToken == '\0') {
    result = s21_NULL;
  } else {
    // находим начало токена
    result = nextToken;

    // перемещаем указатель до конца токена
    while (*nextToken != '\0' && s21_strchr(delim, *nextToken) == s21_NULL) {
      nextToken++;
    }

    // заменяем разделитель концом строки и смещаем указатель на следующий
    // символ
    if (*nextToken != '\0') {
      *nextToken = '\0';
      nextToken++;
    }
  }

  return result;
}