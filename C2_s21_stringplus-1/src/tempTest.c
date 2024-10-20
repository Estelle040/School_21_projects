#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

/*---------------------------------------------------------*/
//ЭТО ВРЕМЕННЫЙ ТЕСТ. МНЕ ПРОСТО ЩАС ЛЕНЬ ПИСАТЬ НОРМАЛЬНЫЙ
/*---------------------------------------------------------*/

int main() {
  // MEMCHR
  /*
  char str[] = "Hello World!";
  char c = 'l';
  int len = strlen(str);

  printf("%p\n", memchr(str, c, len));
  printf("%p\n", s21_memchr(str, c, len));
  */

  /*-------------------------*/
  // В MEMCMP ВОЗМОЖНО ОШИБКА
  /*-------------------------*/

  /*
  upd: короче мб это с моим компилятором что-то не так, просто в другом
  компиляторе результаты сходятся, но мой gcc на ubuntu выдаёт вообще какие-то
  рандомные числа. чекните кто-нибудь с мака или ещё чего-нибудь
  */

  // MEMCMP
  /*
  char str1[] = "Hello World!";
  char str2[] = "HeFlo World!";
  int len = strlen(str1);

  printf("orig: %d\n", memcmp(str1, str2, len));
  printf("s21: %d\n", s21_memcmp(str1, str2, len));
  */

  // MEMCPY
  /*
  char str1[] = "World Hello!";
  char str2[] = "Hello World!";
  int len = strlen(str1);

  printf("before memcpy:\n");
  printf("%s\n", str1);
  printf("%s\n", str2);

  //memcpy(str1, str2, len);
  s21_memcpy(str1, str2, len);

  printf("\n\nafter memcpy:\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  */

  // MEMSET
  /*
  char str[] = "Hello World!";
  char c = 'H';
  //int len = strlen(str);

  printf("before memset:\n");
  printf("%s\n", str);

  memset(str, c, 8);
  //s21_memset(str, c, 8);

  printf("\nafter memset:\n");
  printf("%s\n", str);
  */

  // STRCHR
  /*
  char str[] = "Hello World!";
  char c = 'W';

  printf("%p\n", strchr(str, c));
  printf("%p\n", s21_strchr(str, c));
  */

  // STRCSPN
  /*
  const char *str1 = "Hello, World!";
  const char *str2 = " ,!";

  printf("%ld\n", strcspn(str1, str2));
  printf("%ld\n", s21_strcspn(str1, str2));
  */

  // STRLEN
  /*
  char str[] = "12345";

  printf("%ld\n", strlen(str));
  printf("%ld\n", s21_strlen(str));
  */

  // STRNCAT
  // gcc -Wall -Wextra -Werror -std=c11 tempTest.c impl/s21_strncat.c
  // impl/s21_strlen.c -o a.out
  /*
  char str1[20] = "Hello";
  char str2[] = ", World!";
  size_t n = sizeof(str1) - strlen(str1) - 1;

  // Original strncat
  char result[20];
  strcpy(result, str1);
  strncat(result, str2, n);

  char s21_result[20];
  strcpy(s21_result, str1);
  s21_strncat(s21_result, str2, n);

  printf("orig: %s\n", result);
  printf("s21: %s\n", s21_result);
  */

  // STRNCMP
  /*
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World0!";
  int len = strlen(str1);

  int result1 = strncmp(str1, str2, len);
  int result2 = s21_strncmp(str1, str2, len);

  printf("orig: %d\n", result1);
  printf("s21: %d\n", result2);
  */

  // STRNCPY
  /*
  char str1[] = "World Hello!";
  char str2[] = "Hello World!";
  int len = strlen(str1);

  printf("before memcpy:\n");
  printf("%s\n", str1);
  printf("%s\n", str2);

  //strncpy(str1, str2, len);
  s21_strncpy(str1, str2, len);

  printf("\n\nafter memcpy:\n");
  printf("%s\n", str1);
  printf("%s\n", str2);
  */

  // STRPBRK
  /*
  const char *str1 = "Hello, World!";
  const char *str2 = ",!l";

  printf("%p\n", strpbrk(str1, str2));
  printf("%p\n", s21_strpbrk(str1, str2));
  */

  // STRCHR
  /*
  char str[] = "Hello World!";
  char c = 'l';

  printf("%p\n", strrchr(str, c));
  printf("%p\n", s21_strrchr(str, c));
  */

  // STRSTR
  /*
  char str1[] = "Hello World!";
  char str2[] = " ";

  printf("%p\n", strstr(str1, str2));
  printf("%p\n", s21_strstr(str1, str2));

  printf("%c\n", *strstr(str1, str2));
  printf("%c\n", *s21_strstr(str1, str2));
  */

  // STRTOK
  /*
  char str[] = "This is a test string";
  char delim[] = " ";

  // Testing strtok
  printf("Using strtok:\n");
  char *token_strtok = strtok(str, delim);
  while (token_strtok != NULL) {
    printf("%s\n", token_strtok);
    token_strtok = strtok(NULL, delim);
  }

  printf("\n");

  // Testing s21_strtok
  printf("Using s21_strtok:\n");
  char str2[] = "This is a test string";
  // Copy of the original string because s21_strtok modifies the original string

  char *token_s21_strtok = s21_strtok(str2, delim);
  while (token_s21_strtok != s21_NULL) {
    printf("%s\n", token_s21_strtok);
    token_s21_strtok = s21_strtok(s21_NULL, delim);
  }
  */

  // TO_UPPER
  /*
  char str[] = "Hello World! Привет Славяне! ёЁёЁё òóôõøæýÂÇË";
  char *newStr = s21_to_upper(str);

  printf("%s", newStr);
  free(newStr);
  return 0;
  */

  // TO_LOWER
  /*
  char str[] = "HELLO World! Привет Славяне! ёЁёЁё òóôõøæýÂÇË";
  char *newStr = s21_to_lower(str);

  printf("%s", newStr);
  free(newStr);
  return 0;
  */

  // INSERT
  // void *insert(const char *src, const char *str, s21_size_t start_index)
  /*
  char str[] = "Hello, !";
  char *newStr = s21_insert(str, "World", 7);

  printf("%s", newStr);
  free(newStr);
  */

  // TRIM
  // void *s21_trim(const char *src, const char *trim_chars)
  /*
  char str[] = "***Hello, World!*****";
  char *newStr = s21_trim(str, "*");

  printf("%s", newStr);
  free(newStr);

  return 0;
  */
}