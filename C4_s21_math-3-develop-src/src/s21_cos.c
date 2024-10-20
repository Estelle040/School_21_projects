#include "s21_math.h"

long double s21_cos(double x) {
  if (x == S21_NAN || x == S21_INF_POS || x == S21_INF_NEG) {
    return S21_NAN;
  }
  return s21_sin(S21_PI / 2 - x);
}