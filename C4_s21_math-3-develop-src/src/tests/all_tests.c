#include <check.h>
// #include "/Users/hotblacb/.brew/Cellar/check/0.15.2/include/check.h"
// #include "/Users/hotblacb/.brew/Cellar/check/0.15.2/include/check_stdint.h"

#include <locale.h>
#include <math.h>

#include "../s21_math.h"

//----------------------------------------------------------------

START_TEST(ceil0) {
  double variable[] = {-2.0, -1.0, 0, -1.25, -2.33};
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(s21_ceil(variable[i]), ceil(variable[i]), 6);
  }
}
END_TEST

START_TEST(ceil1) {
  double variable[] = {2.0, 1.0, 0, 1.25, 2.33};
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(s21_ceil(variable[i]), ceil(variable[i]), 6);
  }
}
END_TEST

START_TEST(ceil2) {
  for (double i = 0; i < 1.5; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), 6);
  }
}
END_TEST

START_TEST(ceil3) {
  for (double i = 0; i < 1.5; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_ceil((-1) * i), ceil((-1) * i), 6);
  }
}
END_TEST

START_TEST(ceil4) {
  ck_assert_ldouble_eq(ceil(S21_INF), s21_ceil(S21_INF));
  ck_assert_ldouble_eq(ceil(-S21_INF), s21_ceil(-S21_INF));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

//----------------------------------------------------------------

START_TEST(acos0) {
  for (double i = 0; i < 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_acos((-1) * i), acos((-1) * i), 6);
  }
}
END_TEST

START_TEST(acos1) {
  for (double i = 0; i < 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), 6);
  }
}
END_TEST

START_TEST(acos2) {
  for (double i = 1; i < 0.0000001; i *= 0.1) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), 6);
  }
}
END_TEST

START_TEST(acos3) {
  for (double i = 1; i < 0.0000001; i *= 0.1) {
    ck_assert_ldouble_eq_tol(s21_acos((-1) * i), acos((-1) * i), 6);
  }
}
END_TEST

START_TEST(acos4) {
  for (double i = 1; i < 0; i -= 0.0001) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), 6);
  }
  ck_assert(isnan(s21_acos(1.1)) && isnan(acos(1.1)));
}
END_TEST

//----------------------------------------------------------------

START_TEST(asin_forrun) {
  for (double i = 0; i < 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_asin((-1) * i), asin((-1) * i), 6);
  }
}
END_TEST

START_TEST(asin1) {
  for (double i = 0; i < 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), 6);
  }
  ck_assert(isnan(s21_asin(1.1)) && isnan(asin(1.1)));
}
END_TEST

START_TEST(asin2) {
  for (double i = 1; i < 0.0000001; i *= 0.1) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), 6);
  }
}
END_TEST

START_TEST(asin3) {
  for (double i = 1; i < 0.0000001; i *= 0.1) {
    ck_assert_ldouble_eq_tol(s21_asin((-1) * i), asin((-1) * i), 6);
  }
}
END_TEST

START_TEST(asin4) {
  for (double i = 1; i < 0; i -= 0.0001) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), 6);
  }
}
END_TEST

//----------------------------------------------------------------
START_TEST(atan0) {
  for (double i = 0; i < 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_atan((-1) * i), atan((-1) * i), 6);
  }
}
END_TEST

START_TEST(atan1) {
  for (double i = 0; i < 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 6);
  }
}
END_TEST

START_TEST(atan_2) {
  for (double i = 1; i < 0.0000001; i *= 0.1) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 6);
  }
}
END_TEST

START_TEST(atan3) {
  for (double i = 1; i < 0.0000001; i *= 0.1) {
    ck_assert_ldouble_eq_tol(s21_atan((-1) * i), atan((-1) * i), 6);
  }
}
END_TEST

START_TEST(atan4) {
  for (double i = 1; i < 0; i -= 0.0001) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 6);
  }
}
END_TEST

//----------------------------------------------------------------

START_TEST(sin_cos_tan_test) {
  ck_assert_double_nan(s21_sin(NAN));
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(s21_sin(INFINITY));
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(s21_sin(-INFINITY));
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_nan(s21_tan(-INFINITY));
}
END_TEST

START_TEST(cos_forrun) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * S21_PI), s21_cos(k + R * S21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(sin_forrun) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
      ck_assert_double_eq_tol(sin(k + R * S21_PI), s21_sin(k + R * S21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(tan_forrun) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * S21_PI), s21_tan(k + R * S21_PI),
                              1e-6);
    }
  }
}
END_TEST

//----------------------------------------------------------------

START_TEST(powers_fabs) {
  double variable[] = {-2.0, -1.0, 0, 1.25, 11.33};
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(s21_fabs(variable[i]), fabs(variable[i]), 6);
  }
}
END_TEST

START_TEST(powers_floor) {
  double variable[] = {-2.0, -1.0, 0, 1.25, 11.33};
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(s21_floor(variable[i]), floor(variable[i]), 6);
  }
}
END_TEST

START_TEST(powers_exponent) {
  double variable[] = {4.0, 16.0, 2.0, -1,
                       0};  // проверить на корректность значения
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(s21_exp(variable[i]), exp(variable[i]), 6);
  }
}
END_TEST

START_TEST(powers_sqrt) {
  long double arr[] = {5898.467, 8427.928,  5698.0035, 1289.244, 7025.7,
                       12.1357,  4745.5,    2930.637,  8187.391, 1015.89,
                       3155.844, 3954.143,  2862.1,    2782.954, 5097.545,
                       2630.4,   1075.747,  1889.786,  1782,     0.0001,
                       21345678, 7432,      0.3245,    12345,    13456,
                       0.03213,  324.42342, 0,         50,       0.24};
  for (int i = 0; i < 30; i++) {
    ck_assert_ldouble_eq_tol(s21_sqrt(arr[i]), sqrt(arr[i]), 0.000001);
  }
}
END_TEST

START_TEST(powers_fmod) {
  double variable[] = {5.1, 1.3, -5.1, 1.3, -5.1, -1.3, 0, 1, 5.1, INFINITY};
  for (int i = 0; i < 10; i += 2) {
    ck_assert_ldouble_eq_tol((s21_fmod(variable[i], variable[i + 1])),
                             (fmod(variable[i], variable[i + 1])), 6);
  }
}
END_TEST

START_TEST(powers_log) {
  double variable[] = {5.6, 23.78, 1, 0.1, 3364};
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(s21_log(variable[i]), log(variable[i]), 6);
  }
  // printf("\n%.6Lf %.6f\n", s21_log(variable), log(variable));
}
END_TEST

START_TEST(powers_log1) {
  double variable = 5.6;  ///, 23.78, 0, -1, 3364
  ck_assert_ldouble_eq_tol(s21_log(variable), log(variable), 6);
}
END_TEST

START_TEST(powers_log2) {
  double variable = 23.78;  ///, 23.78, 0, -1, 3364
  ck_assert_ldouble_eq_tol(s21_log(variable), log(variable), 6);
}
END_TEST

START_TEST(powers_log3) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(powers_log4) { ck_assert_ldouble_nan(s21_log(-1)); }
END_TEST

START_TEST(powers_log5) {
  double variable = 3364;  ///, 23.78, 0, -1, 3364
  ck_assert_ldouble_eq_tol(s21_log(variable), log(variable), 6);
}
END_TEST

START_TEST(log_1) {
  double num = 456.789;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
  double num = NAN;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
  double num = 0.001;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
  double num = 0.4;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
  double num = -INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
  double num = INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_7) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));

  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_8) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_9) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
}
END_TEST

START_TEST(log_10) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_11) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6); }
END_TEST

START_TEST(log_12) { ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6); }
END_TEST

START_TEST(log_13) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_14) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_15) {
  ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
}
END_TEST

START_TEST(log_16) {
  ck_assert_ldouble_eq_tol(s21_log(S21_PI / 3), log(S21_PI / 3), 1e-6);
}
END_TEST

START_TEST(log_17) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                           1e-6);
}
END_TEST

START_TEST(log_18) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           1e-6);
}
END_TEST

START_TEST(log_19) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           1e-6);
}
END_TEST

START_TEST(log_20) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), 1e-6);
}
END_TEST

START_TEST(log_24) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-6);
}
END_TEST

START_TEST(log_25) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-6);
}
END_TEST

START_TEST(log_26) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-6);
}
END_TEST

START_TEST(log_27) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), 1e-6);
}
END_TEST

START_TEST(log_21) {
  ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), 1e-6);
}
END_TEST

START_TEST(log_22) {
  ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-6);
}
END_TEST

START_TEST(log_23) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(log_28) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), 1e-6);
}
END_TEST

START_TEST(log_29) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), 1e-6);
}
END_TEST

START_TEST(log_30) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), 1e-6);
}
END_TEST

START_TEST(log_31) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), 1e-6);
}
END_TEST

START_TEST(log_32) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), 1e-6);
}
END_TEST

START_TEST(log_33) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), 1e-6);
}
END_TEST

START_TEST(log_34) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), 1e-6);
}
END_TEST

START_TEST(powers_pow) {
  double variable[] = {-2.0, -1.0, 0, 1, 11.33};
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 5; i++) {
      ck_assert_ldouble_eq_tol(s21_pow(variable[i], variable[j]),
                               pow(variable[i], variable[j]), 6);
    }
  }
}
END_TEST
//----------------------------------------------------------------

START_TEST(abs0) {
  int variable[] = {3, -2378, 0, -1, 43234};
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(s21_abs(variable[i]), abs(variable[i]));
  }
}
END_TEST

START_TEST(exp_0) {
  double x = 0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_1) {
  double x = 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_2) {
  double x = 2;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_3) {
  double x = 3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_4) {
  double x = 1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_5) {
  double x = -1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_6) {
  double x = 0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_7) {
  double x = -0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_8) {
  double x = 715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_9) {
  double x = -715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_10) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_11) {
  double x = 'A';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_12) {
  double x = -'N';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_13) {
  double x = -'V';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_14) {
  double x = +'B';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_15) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_16) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_17) { ck_assert_float_eq(s21_exp(2), exp(2)); }
END_TEST

START_TEST(exp_18) { ck_assert_float_eq(s21_exp(-750), exp(-750)); }
END_TEST

START_TEST(exp_19) { ck_assert_float_eq(s21_exp(-2), exp(-2)); }
END_TEST

START_TEST(exp_20) {
  double num = NAN;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_21) {
  double num = INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_22) {
  double num = -INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_23) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_24) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), 1e-06);
}
END_TEST

START_TEST(exp_25) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(expl(INFINITY));
}
END_TEST

START_TEST(exp_26) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(expl(NAN));
}
END_TEST

START_TEST(exp_27) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_28) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_29) {
  double x = -100;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_30) {
  double x = -1000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_31) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_32) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_33) {
  double num = 1000000;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_1) {
  double num = 456.789;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  ck_assert_float_eq(our_res, orig_res);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_2) {
  double num = INFINITY;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_3) {
  double num = NAN;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_4) {
  double num = NAN;
  double ex = NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_5) {
  double num = 0.001;
  double ex = NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_6) {
  double num = INFINITY;
  double ex = INFINITY;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_7) {
  double num = INFINITY;
  double ex = INFINITY;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_8) {
  long double base = -16.161435;
  long double exp = 9.;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 6);
}
END_TEST

START_TEST(pow_9) {
  long double base = -10.1261;
  long double exp = -0.72;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
  long double base = -0;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_16) {
  long double base = -0;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_17) {
  long double base = -1;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_18) {
  long double base = -1;
  long double exp = S21_NAN;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
  long double base = S21_NAN;
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_20) {
  long double base = -123;
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
  long double base = 0.5591951;
  long double exp = -S21_INF;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_22) {
  long double base = 1.5591951;
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_23) {
  long double base = 0.5591951;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_24) {
  long double base = 1.5591951;
  long double exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
  long double base = -S21_INF;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_26) {
  long double base = -S21_INF;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_27) {
  long double base = -S21_INF;
  long double exp = 141;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
  long double base = -S21_INF;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
  long double base = S21_INF;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_30) {
  long double base = S21_INF;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

START_TEST(pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-6);
}
END_TEST

START_TEST(pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-6);
}
END_TEST

START_TEST(pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-6);
}
END_TEST

START_TEST(pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           1e-6);
}
END_TEST

START_TEST(pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_38) {
  long double orig_res = pow(2.1234567e-7, -2.45e4),
              our_res = s21_pow(2.1234567e-7, -2.45e4);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-6);
}
END_TEST

START_TEST(pow_40) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_41) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(-0, exp));
  ck_assert_ldouble_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_42) {
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_43) {
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(+0, exp));
  ck_assert_double_nan(pow(+0, exp));
}
END_TEST

START_TEST(pow_44) {
  long double exp = 2.456;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_45) {
  long double exp = -S21_INF;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_46) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_47) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_48) {
  long double exp = 56.345;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_49) {
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_50) {
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_51) {
  long double exp = S21_NAN;
  ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), 1e-6);
}
END_TEST

START_TEST(pow_52) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), 1e-6);
}
END_TEST

START_TEST(pow_53) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), 1e-6);
}
END_TEST

START_TEST(pow_54) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_55) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_56) {
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(S21_NAN, exp));
  ck_assert_double_nan(pow(S21_NAN, exp));
}
END_TEST

START_TEST(pow_57) {
  long double exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(S21_INF, exp));
  ck_assert_ldouble_infinite(pow(S21_INF, exp));
}
END_TEST

START_TEST(pow_58) {
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, exp), pow(-S21_INF, exp), 1e-6);
}
END_TEST

START_TEST(pow_59) {
  double exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, exp));
  ck_assert_ldouble_infinite(pow(-S21_INF, exp));
}
END_TEST

START_TEST(pow_60) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -1000; exp -= 0.1) {
    res1 = pow(S21_INF, exp);
    res2 = s21_pow(S21_INF, exp);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_61) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, S21_INF);
    res2 = s21_pow(base, S21_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, S21_INF);
    res2 = s21_pow(base, S21_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_63) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, -S21_INF);
    res2 = s21_pow(base, -S21_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_64) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, -S21_INF);
    res2 = s21_pow(base, -S21_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_65) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_66) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_67) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_68) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res2, res1, 1e-6);
}
END_TEST

START_TEST(pow_69) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_70) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_71) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_72) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_73) {
  long double base = -0;
  long double exp = S21_INF;
  long double res = pow(base, exp);
  long double res1 = s21_pow(base, exp);
  ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

START_TEST(pow_74) {
  long double exp;
  long double base = -0;
  long double res;
  long double res1;
  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res = pow(base, exp);
      res1 = s21_pow(base, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

//----------------------------------------------------------------

//----------------------------------------------------------------

//----------------------------------------------------------------

Suite *s21_math_h_suite(void) {
  Suite *s;
  TCase *tc_arc;
  TCase *tc_abs;
  TCase *tc_trigonometric;
  TCase *tc_powers;
  TCase *tc_ceil;

  // Создаём сьют
  s = suite_create("[s21_math] suite");

  // Создаём кейс
  tc_arc = tcase_create(" ARC Case ");
  tc_abs = tcase_create(" ABS Case ");
  tc_trigonometric = tcase_create(" Trigonometric Case ");
  tc_powers = tcase_create(" Powers Case ");
  tc_ceil = tcase_create(" Ceil Case ");

  // Добавялем тесты в кейс
  tcase_add_test(tc_ceil, ceil0);
  tcase_add_test(tc_ceil, ceil1);
  tcase_add_test(tc_ceil, ceil2);
  tcase_add_test(tc_ceil, ceil3);
  tcase_add_test(tc_ceil, ceil4);

  // -1 <= x <= 1
  tcase_add_test(tc_arc, acos0);
  tcase_add_test(tc_arc, acos1);
  tcase_add_test(tc_arc, acos2);
  tcase_add_test(tc_arc, acos3);
  tcase_add_test(tc_arc, acos4);

  // -1 <= x <= 1
  tcase_add_test(tc_arc, asin_forrun);
  tcase_add_test(tc_arc, asin1);
  tcase_add_test(tc_arc, asin2);
  tcase_add_test(tc_arc, asin3);
  tcase_add_test(tc_arc, asin4);

  // all real numbers

  tcase_add_test(tc_arc, atan0);
  tcase_add_test(tc_arc, atan1);
  tcase_add_test(tc_arc, atan_2);
  tcase_add_test(tc_arc, atan3);
  tcase_add_test(tc_arc, atan4);

  // X э R trigonometric

  tcase_add_test(tc_trigonometric, sin_cos_tan_test);
  tcase_add_test(tc_trigonometric, sin_forrun);
  tcase_add_test(tc_trigonometric, cos_forrun);
  tcase_add_test(tc_trigonometric, tan_forrun);

  // powers
  tcase_add_test(tc_powers, powers_exponent);
  tcase_add_test(tc_powers, powers_log);
  tcase_add_test(tc_powers, powers_log1);
  tcase_add_test(tc_powers, powers_log2);
  tcase_add_test(tc_powers, powers_log3);
  tcase_add_test(tc_powers, powers_log4);
  tcase_add_test(tc_powers, powers_log5);
  tcase_add_test(tc_powers, log_1);
  tcase_add_test(tc_powers, log_2);
  tcase_add_test(tc_powers, log_3);
  tcase_add_test(tc_powers, log_4);
  tcase_add_test(tc_powers, log_5);
  tcase_add_test(tc_powers, log_6);
  tcase_add_test(tc_powers, log_7);
  tcase_add_test(tc_powers, log_8);
  tcase_add_test(tc_powers, log_9);
  tcase_add_test(tc_powers, log_10);
  tcase_add_test(tc_powers, log_11);
  tcase_add_test(tc_powers, log_12);
  tcase_add_test(tc_powers, log_13);
  tcase_add_test(tc_powers, log_14);
  tcase_add_test(tc_powers, log_15);
  tcase_add_test(tc_powers, log_16);
  tcase_add_test(tc_powers, log_17);
  tcase_add_test(tc_powers, log_18);
  tcase_add_test(tc_powers, log_19);
  tcase_add_test(tc_powers, log_20);
  tcase_add_test(tc_powers, log_21);
  tcase_add_test(tc_powers, log_22);
  tcase_add_test(tc_powers, log_23);
  tcase_add_test(tc_powers, log_24);
  tcase_add_test(tc_powers, log_25);
  tcase_add_test(tc_powers, log_26);
  tcase_add_test(tc_powers, log_27);
  tcase_add_test(tc_powers, log_28);
  tcase_add_test(tc_powers, log_29);
  tcase_add_test(tc_powers, log_30);
  tcase_add_test(tc_powers, log_31);
  tcase_add_test(tc_powers, log_32);
  tcase_add_test(tc_powers, log_33);
  tcase_add_test(tc_powers, log_34);

  tcase_add_test(tc_powers, powers_fmod);
  tcase_add_test(tc_powers, powers_sqrt);
  tcase_add_test(tc_powers, powers_floor);
  tcase_add_test(tc_powers, powers_fabs);

  tcase_add_test(tc_powers, exp_0);
  tcase_add_test(tc_powers, exp_1);
  tcase_add_test(tc_powers, exp_2);
  tcase_add_test(tc_powers, exp_3);
  tcase_add_test(tc_powers, exp_4);
  tcase_add_test(tc_powers, exp_5);
  tcase_add_test(tc_powers, exp_6);
  tcase_add_test(tc_powers, exp_7);
  tcase_add_test(tc_powers, exp_8);
  tcase_add_test(tc_powers, exp_9);
  tcase_add_test(tc_powers, exp_10);
  tcase_add_test(tc_powers, exp_11);
  tcase_add_test(tc_powers, exp_12);
  tcase_add_test(tc_powers, exp_13);
  tcase_add_test(tc_powers, exp_14);
  tcase_add_test(tc_powers, exp_15);
  tcase_add_test(tc_powers, exp_16);
  tcase_add_test(tc_powers, exp_17);
  tcase_add_test(tc_powers, exp_18);
  tcase_add_test(tc_powers, exp_19);
  tcase_add_test(tc_powers, exp_20);
  tcase_add_test(tc_powers, exp_21);
  tcase_add_test(tc_powers, exp_22);
  tcase_add_test(tc_powers, exp_23);
  tcase_add_test(tc_powers, exp_24);
  tcase_add_test(tc_powers, exp_25);
  tcase_add_test(tc_powers, exp_26);
  tcase_add_test(tc_powers, exp_27);
  tcase_add_test(tc_powers, exp_28);
  tcase_add_test(tc_powers, exp_29);
  tcase_add_test(tc_powers, exp_30);
  tcase_add_test(tc_powers, exp_31);
  tcase_add_test(tc_powers, exp_32);
  tcase_add_test(tc_powers, exp_33);

  tcase_add_test(tc_powers, pow_1);
  tcase_add_test(tc_powers, pow_2);
  tcase_add_test(tc_powers, pow_3);
  tcase_add_test(tc_powers, pow_4);
  tcase_add_test(tc_powers, pow_5);
  tcase_add_test(tc_powers, pow_6);
  tcase_add_test(tc_powers, pow_7);
  tcase_add_test(tc_powers, pow_8);
  tcase_add_test(tc_powers, pow_9);
  tcase_add_test(tc_powers, pow_10);
  tcase_add_test(tc_powers, pow_12);
  tcase_add_test(tc_powers, pow_13);
  tcase_add_test(tc_powers, pow_14);
  tcase_add_test(tc_powers, pow_15);
  tcase_add_test(tc_powers, pow_16);
  tcase_add_test(tc_powers, pow_17);
  tcase_add_test(tc_powers, pow_18);
  tcase_add_test(tc_powers, pow_19);
  tcase_add_test(tc_powers, pow_20);
  tcase_add_test(tc_powers, pow_21);
  tcase_add_test(tc_powers, pow_22);
  tcase_add_test(tc_powers, pow_23);
  tcase_add_test(tc_powers, pow_24);
  tcase_add_test(tc_powers, pow_25);
  tcase_add_test(tc_powers, pow_26);
  tcase_add_test(tc_powers, pow_27);
  tcase_add_test(tc_powers, pow_28);
  tcase_add_test(tc_powers, pow_29);
  tcase_add_test(tc_powers, pow_30);
  tcase_add_test(tc_powers, pow_31);
  tcase_add_test(tc_powers, pow_32);
  tcase_add_test(tc_powers, pow_33);
  tcase_add_test(tc_powers, pow_34);
  tcase_add_test(tc_powers, pow_35);
  tcase_add_test(tc_powers, pow_36);
  tcase_add_test(tc_powers, pow_37);
  tcase_add_test(tc_powers, pow_38);
  tcase_add_test(tc_powers, pow_39);
  tcase_add_test(tc_powers, pow_40);
  tcase_add_test(tc_powers, pow_41);
  tcase_add_test(tc_powers, pow_42);
  tcase_add_test(tc_powers, pow_43);
  tcase_add_test(tc_powers, pow_44);
  tcase_add_test(tc_powers, pow_45);
  tcase_add_test(tc_powers, pow_46);
  tcase_add_test(tc_powers, pow_47);
  tcase_add_test(tc_powers, pow_48);
  tcase_add_test(tc_powers, pow_49);
  tcase_add_test(tc_powers, pow_50);
  tcase_add_test(tc_powers, pow_51);
  tcase_add_test(tc_powers, pow_52);
  tcase_add_test(tc_powers, pow_53);
  tcase_add_test(tc_powers, pow_54);
  tcase_add_test(tc_powers, pow_55);
  tcase_add_test(tc_powers, pow_56);
  tcase_add_test(tc_powers, pow_57);
  tcase_add_test(tc_powers, pow_58);
  tcase_add_test(tc_powers, pow_59);
  tcase_add_test(tc_powers, pow_60);
  tcase_add_test(tc_powers, pow_61);
  tcase_add_test(tc_powers, pow_62);
  tcase_add_test(tc_powers, pow_63);
  tcase_add_test(tc_powers, pow_64);
  tcase_add_test(tc_powers, pow_65);
  tcase_add_test(tc_powers, pow_66);
  tcase_add_test(tc_powers, pow_67);
  tcase_add_test(tc_powers, pow_68);
  tcase_add_test(tc_powers, pow_69);
  tcase_add_test(tc_powers, pow_70);
  tcase_add_test(tc_powers, pow_71);
  tcase_add_test(tc_powers, pow_72);
  tcase_add_test(tc_powers, pow_73);
  tcase_add_test(tc_powers, pow_74);

  // abs

  tcase_add_test(tc_abs, abs0);
  // Добавляем кейсы в сьют

  suite_add_tcase(s, tc_ceil);
  suite_add_tcase(s, tc_arc);
  suite_add_tcase(s, tc_abs);
  suite_add_tcase(s, tc_trigonometric);
  suite_add_tcase(s, tc_powers);

  return s;
}

int main() {
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, "C");
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_math_h_suite();
  sr = srunner_create(s);

  // srunner_run_all(sr, CK_NORMAL - показывать только фейлы);  //? CK_VERBOSE -
  // показывать успешные тесты
  for (int repeats = 0; repeats < 1; repeats++) srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}