#include "s21_math.h"

long double s21_tan(double x) {
  if (x == S21_NAN || x == S21_INF_POS || x == S21_INF_NEG) {
    return S21_NAN;
  }
  long double cos_res = s21_cos(x);
  if (cos_res == S21_NAN) return S21_NAN;
  return (s21_sin(x) / cos_res);
}