#include "s21_math.h"

long double s21_asin(double x) {
  double answer = s21_atan(x / s21_sqrt(1 - x * x));
  if (x == s21_NEG_ZERO) {  // Added check for negative zero
    answer = -0.0;
  }
  return answer;
}