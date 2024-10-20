#include "s21_math.h"

long double s21_acos(double x) {
  if (x > 1.0 || x < -1.0 || x == S21_NAN || x == S21_INF || x == -S21_INF) {
    return S21_NAN;
  }

  return S21_PI / 2 - s21_asin(x);
}