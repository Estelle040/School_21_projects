#include "s21_math.h"

long double s21_floor(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x)) return x;
  int int_part = (int)x;
  int_part -= (x < 0 && (x - int_part));
  return (long double)int_part;
}
