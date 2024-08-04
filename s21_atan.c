#include "s21_math.h"

long double s21_atan(double x) {
  long double answer = 0;
  if (IsNaN(x)) {
    answer = s21_NAN;
  } else if (x == s21_INF) {
    answer = s21_PI / 2;
  } else if (x == s21_INF_NEG) {
    answer = -s21_PI / 2;
  } else {
    if (x > -1.0 && x < 1.0) {
      answer = CalculateAtan(x);
    } else if (x > 1.0) {
      answer = s21_PI / 2 - CalculateAtan(1 / x);
    } else if (x < -1.0) {
      answer = -s21_PI / 2 - CalculateAtan(1 / x);
    } else if (x == 1.0) {
      answer = s21_PI / 4;
    } else if (x == -1.0) {
      answer = -s21_PI / 4;
    }
  }
  return answer;
}

long double CalculateAtan(double num) {
  long double answer = 0, add_value = 1, sign = 1, denominator = 1,
              num_pow = num;
  while (s21_fabs(add_value) > s21_EPS) {
    add_value = sign * num_pow / denominator;
    answer += add_value;
    sign *= -1;
    num_pow *= num * num;
    denominator += 2;
  }
  return answer;
}