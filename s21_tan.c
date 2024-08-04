#include "s21_math.h"

long double s21_tan(double x) {
  long double answer = 0;
  if (IsNaN(x) || IsInf(x)) {
    answer = s21_NAN;
  } else if (x == (double)s21_PI / 2) {
    answer = 16331239353195370.0;
  } else if (x == (double)-s21_PI / 2) {
    answer = -16331239353195370.0;
  } else {
    answer = s21_sin(x) / s21_cos(x);
  }
  return answer;
}
