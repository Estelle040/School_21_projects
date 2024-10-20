#include "s21_math.h"

long double s21_atan(double x) {
  if (x == S21_NAN) {
    return S21_NAN;
  }

  int flag_sign = 0, flag_reverse = 0;
  double result;
  int count = 0;

  if (x < 0) {
    x = -x;
    flag_sign = 1;
  }

  /* atan(x) + atan(1/x) = pi/2, x > 0 */

  if (x > 1) {
    x = 1 / x;
    flag_reverse = 1;
  }

  /* atan(x) = pi/6 + atan((x * sqrt(3) - 1) / (x + sqrt(3))) */

  while (x > S21_PI12) {
    x = (x * S21_SQRT3 - 1) / (x + S21_SQRT3);
    count++;
  }

  /* atan(x) = x * (0.55913709 / (1.4087812 + x * x) +0.60310579 - 0.05160454 *
   * x * x) на [-pi/12; pi/12] */

  result =
      x * (0.55913709 / (1.4087812 + x * x) + 0.60310579 - 0.05160454 * x * x);
  result += count * S21_PI6;

  if (flag_reverse) {
    result = S21_PI2 - result;
  }
  if (flag_sign) {
    result = -result;
  }
  return result;
}