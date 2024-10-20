#ifndef SRC_S21_MATH_H
#define SRC_S21_MATH_H

#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)
#define S21_INF __builtin_inf()
#define S21_NAN __builtin_nan("")
#define is_inf __builtin_isinf
#define is_nan __builtin_isnan
#define S21_EPS 1e-200
#define S21_EXP 2.7182818284590452
#define S21_MAX 1e100
#define POS_INF 1.0 / 0.0L
#define NEG_INF -1.0 / 0.0L
#define isNAN(x) (x != x)
#define isPOS_INF(x) (x == POS_INF)
#define isNEG_INF(x) (x == NEG_INF)
#define isNormal(x) (!isNAN(x) && !isNEG_INF(x) && !isPOS_INF(x))
#define S21_PI ((double)3.141592653589793)
#define S21_PI12 (S21_PI / 12.F)
#define S21_PI6 (S21_PI / 6.F)
#define S21_PI2 (S21_PI / 2.F)
#define S21_SQRT3 ((float)1.732050807569)

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const long double EXP_EPS = 1e-100;

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double fg);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H