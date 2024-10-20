#include "s21_math.h"

long double s21_sqrt(double fg) {
  long double n = fg / 2.0;
  long double lstX = 0.0;
  while (n != lstX) {
    lstX = n;
    n = (n + fg / n) / 2.0;
  }
  return n;
}