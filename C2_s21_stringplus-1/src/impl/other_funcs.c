// эта функция проверяет встречается ли символ в строке.
// если встречается, то функция возвращает 1, если нет - 0

int isInStr(const char c, const char *str) {
  int flag = 0;
  while (*str != '\0' && !flag) {
    if (c == *str) {
      flag = 1;
    }
    str++;
  }
  return flag;
}