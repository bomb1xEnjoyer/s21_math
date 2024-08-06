#include "s21_math.h"

long double s21_log(double x) {
  int exp_pow = 0;
  long double temp = 0;
  long double res = 0;
  long double answer = res + exp_pow;
  if (IsNaN(x)) {
    answer = s21_NAN;
  } else if (x == s21_INF) {
    answer = s21_INF;
  } else if (x == s21_INF_NEG) {
    answer = s21_NAN;
  } else {
    if (x > 0) {
      while (x >= s21_E) {
        x /= s21_E;
        exp_pow++;
      }
      for (int i = 0; i < 150; i++) {
        temp = res;
        res = temp + 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
      }
      answer = res + exp_pow;
    } else if (x == 0) {
      answer = s21_INF_NEG;
    } else if (x < 0) {
      answer = s21_NAN;
    }
  }
  return answer;
}
