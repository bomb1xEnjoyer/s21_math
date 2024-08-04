#include "s21_math.h"

long double s21_cos(double x) {
  long double answer = 0;
  if (IsNaN(x) || IsInf(x)) {
    answer = s21_NAN;
  } else if (x == 0) {
    answer = 1.0;
  } else {
    x = RemovePeriod(x);
    long double previous_answer = 1, factorial = 1, sign = 1, k = 1, x_pow = 1;
    while (s21_fabs(s21_fabs(previous_answer) - s21_fabs(answer)) > s21_EPS) {
      previous_answer = answer;
      answer += sign * x_pow / factorial;
      sign *= -1;
      x_pow *= x * x;
      factorial *= (2 * k) * (2 * k - 1);
      k++;
    }
  }
  return answer;
}