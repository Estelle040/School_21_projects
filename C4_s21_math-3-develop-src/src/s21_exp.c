#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1;
  int flag = 0;
  if (is_nan(x)) {
    res = x < 0 ? -S21_NAN : S21_NAN;
  } else if (is_inf(x)) {
    res = x < 0 ? 0 : S21_INF;
  } else {
    if (x < 0) {
      x *= -1;
      flag = 1;
    }
    long double num = x;
    long double fact = 1;
    long double step = 1;
    while (s21_fabs(step) > EXP_EPS) {
      step *= num / fact;
      res += step;
      fact++;
      if (res > __DBL_MAX__) {
        res = S21_INF;
        break;
      }
    }
    if (flag == 1) {
      if (res > __DBL_MAX__) {
        res = 0;
      } else {
        res = 1. / res;
      }
    }
    if (res > __DBL_MAX__) {
      return S21_INF;
    }
  }
  return res;
}