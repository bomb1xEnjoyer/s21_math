#include "s21_math.h"

long double s21_fabs(double x) {
  long double answer = x;
  if (IsNaN(x)) {
    answer = s21_NAN;
  } else if (IsInf(x)) {
    answer = s21_INF;
  } else if (x == s21_NEG_ZERO) {  //+
    answer = 0;                    //+
  }
  if (x < 0) {
    answer = -x;
  }
  return answer;
}