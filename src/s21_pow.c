#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double answer = 0;
  int tmp = 0;
  if (base == 1 || exp == 0 || (base == -1 && (IsInf(exp)))) {
    answer = 1;
  } else if ((s21_fabs(base) < 1 && exp == s21_INF_NEG) ||
             (s21_fabs(base) > 1 && exp == s21_INF) ||
             (base == s21_INF_NEG &&
              ((exp > 0 && (int)exp % 2 == 0) || exp == s21_INF)) ||
             (base == s21_INF && exp > 0)) {
    answer = s21_INF;
  } else if ((base < 0 && (int)exp - exp != 0) ||
             (base != base && exp != exp)) {
    answer = s21_NAN;
  } else if ((base == s21_NEG_ZERO && (exp > 0 && (int)exp % 2 == 0)) ||
             (s21_fabs(base) > 1 && exp == s21_INF_NEG) ||
             (s21_fabs(base) < 1 && exp == s21_INF) || (base == 0 && exp > 0) ||
             (base == s21_INF_NEG && (exp < 0 && (int)exp % 2 == 0)) ||
             (base == s21_INF && exp < 0)) {
    answer = 0;
  } else if ((base == s21_NEG_ZERO && (exp > 0 && (int)exp % 2 != 0)) ||
             (base == s21_INF_NEG && (exp < 0 && (int)exp % 2 != 0))) {
    answer = s21_NEG_ZERO;
  } else if (base == s21_INF_NEG && (exp > 0 && (int)exp % 2 != 0)) {
    answer = s21_INF_NEG;
  } else {
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        tmp = 1;
      }
      base = s21_fabs(base);
    }
    answer = tmp ? -s21_exp(exp * s21_log(base)) : s21_exp(exp * s21_log(base));
  }
  return answer;
}