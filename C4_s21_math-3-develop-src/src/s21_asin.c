#include "s21_math.h"

long double s21_asin(double x) {
  if (x > 1.0 || x < -1.0 || x == S21_NAN || x == S21_INF || x == -S21_INF) {
    return S21_NAN;
  }

  return s21_atan(x / s21_sqrt(1 - x * x));
}