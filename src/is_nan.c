#include "s21_math.h"

int IsNaN(long double num) {
  int flag = 0;
  if (num != num) {
    flag = 1;
  }
  return flag;
}