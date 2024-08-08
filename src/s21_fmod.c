#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double answer = 0;
  long long n = 0;
  int sign = 0;

  if (y < 0) {
    y *= -1;
  }

  if (x < 0) {
    x *= -1;
    sign = 1;
  }

  if (x == 0) {
    answer = 0;
  } else if (IsInf(x) || y == 0) {
    answer = s21_NAN;
  } else if (x == y || y == 1 || y == -1) {
    answer = 0;
  } else {
    double x_copy = x;
    n = s21_floor(x_copy / y);
    answer = x - n * y;
  }

  if (sign == 1) {
    answer *= -1;
  }

  return answer;
}
