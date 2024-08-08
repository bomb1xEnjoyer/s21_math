#include "s21_math.h"

long double RemovePeriod(double num) {
  long long period = num / 2 / s21_PI;
  num -= period * 2 * s21_PI - 2 * s21_PI;
  return num;
}
