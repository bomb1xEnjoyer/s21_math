#include "s21_math.h"

int IsInf(long double num) {
  int flag = 0;
  if (num == s21_INF || num == s21_INF_NEG) {
    flag = 1;
  }
  return flag;
}