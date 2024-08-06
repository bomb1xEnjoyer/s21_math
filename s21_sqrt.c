#include "s21_math.h"

long double s21_sqrt(double x) {
  double xsqrt, previous_value, a, b, estimated_value = x;
  int n = 0;
  if (x == s21_INF) {
    xsqrt = s21_INF;
  } else if (x == s21_INF_NEG) {
    xsqrt = s21_NAN;
  } else if (IsNaN(x) || x < 0) {
    xsqrt = s21_NAN;
  } else {
    while (estimated_value > 100) {
      estimated_value = estimated_value / 10;
      n++;
    }
    if ((n / 2 - (int)n / 2) > 0) {
      n--;
      estimated_value = estimated_value * 10;
    }
    if (estimated_value < 10)
      xsqrt = (0.28 * estimated_value + 0.89) * IntPow(10, n / 2);
    if (estimated_value >= 10)
      xsqrt = (0.089 * estimated_value + 2.8) * IntPow(10, n / 2);
    do {
      previous_value = xsqrt;
      a = (x - IntPow(xsqrt, 2)) / (2 * xsqrt);
      b = xsqrt + a;
      xsqrt = b - IntPow(a, 2) / (2 * b);
    } while (s21_fabs(previous_value - xsqrt) > s21_EPS);
  }

  return xsqrt;
}
