#include "s21_math.h"

long double s21_pow(double base, double exp) {
  int minus_flag = 0;
  long double result;

  int base_plus_inf = base == S21_INF_POS ? 1 : 0;
  int base_minus_inf = base == S21_INF_NEG ? 1 : 0;
  int base_inf = is_inf(base);
  int base_nan = is_nan(base);
  int base_fin = base_inf + base_nan == 0 ? 1 : 0;

  // hotbl/ вместо всех exp тут были base / вместо "= exp ==" было "= base =="
  int exp_plus_inf = exp == S21_INF_POS ? 1 : 0;
  int exp_minus_inf = exp == S21_INF_NEG ? 1 : 0;
  int exp_inf = is_inf(exp);
  int exp_nan = is_nan(exp);
  int exp_fin = exp_inf + exp_nan == 0 ? 1 : 0;
  int exp_int = s21_fabs(exp - s21_floor(exp)) <= S21_EPS ? 1 : 0;

  if (exp == -0) {
    return 1;
  }  // hotbl/ добавил случаи, если ноль в степени

  // pow(-1, inf) = 1
  if (exp_inf && base == -1) {
    return 1;
  }
  // pow(1, nan) = 1
  if (exp_nan && base == 1) {
    return 1;
  }
  // pow(nan) = nan
  if (exp_nan || base_nan) {
    return S21_NAN;
  }

  // pow(+0, exp) (exp - int, exp < 0, exp % 2 = 0) = +inf
  if (base_fin && base > 0 && base <= S21_EPS && exp_int && ((int)exp) < 0 &&
      ((int)exp) % 2) {
    return S21_INF;
  }

  // pow(-0, exp) (exp - int, exp < 0, exp % 2 = 0) = -inf
  if (base_fin && base < 0 && base >= -S21_EPS && exp_int && ((int)exp) < 0 &&
      ((int)exp) % 2) {
    return -S21_INF;
  }

  // pow(+-0, -inf) = inf
  if (base_fin && s21_fabs(base) < S21_EPS && exp_minus_inf) {
    return S21_INF;
  }

  // pow(+0, exp) = +0
  if (base_fin && base > 0 && base <= S21_EPS && exp_int && ((int)exp) % 2) {
    return +0;
  }

  // pow(-0, exp), = -0
  if (base_fin && base < 0 && base >= -S21_EPS && exp_int && ((int)exp) % 2) {
    return -0;
  }

  // pow(+-1, +-inf) = 1
  if (base == -1 || base == 1 && exp_fin) {
    return 1;
  }

  // pow(base, +-0) = 1
  if (s21_fabs(exp) < S21_EPS) {
    return 1;
  }

  // pow(base, -inf)
  if (exp_minus_inf) {
    if (s21_fabs(base) - 1 < S21_EPS)
      return S21_INF;
    else if (s21_fabs(base) - 1 > S21_EPS) {
      return +0;
    }
  }

  // pow(base, +inf)
  if (exp_plus_inf) {
    if (s21_fabs(base) - 1 < S21_EPS)
      return +0;
    else if (s21_fabs(base) - 1 > S21_EPS) {
      return S21_INF;
    }
  }

  // pow(-inf, exp % 2 == 0) = -0
  if (base_minus_inf && exp_int && exp < 0 && ((int)exp) % 2) {
    return -0;
  }

  // pow(-inf, exp)
  if (base_minus_inf &&
      ((!exp_int && exp < 0) || (exp_int && exp < 0 && !(((int)exp) % 2)))) {
    return +0;
  }

  // pow(+inf, exp)
  if (base_plus_inf && exp < -S21_EPS) {
    return +0;
  }

  // pow(+inf, exp)
  if (base_plus_inf && exp > S21_EPS) {
    return +S21_INF;
  }
  // hotbl/добавил
  if (base_minus_inf && exp > S21_EPS) {
    return S21_INF;
  }

  if ((base < 0) && s21_fmod(exp, 1) != 0) return S21_NAN;

  if (base == 0 && exp > 0) return 0;
  if (base < 0) {
    base = -base;
    minus_flag = 1;
  }
  long double log_base = s21_log(base);  // Натуральный логарифм основания
  result = s21_exp(log_base * exp);  // Результат возведения в степень
  if (minus_flag && s21_fmod(exp, 2)) return -result;
  return result;
}