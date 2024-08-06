#include "s21_math.h"

long double IntPow(double base, int exp) {
  long double answer = 1;
  for (; exp > 0; exp--) {
    answer *= base;
  }
  return answer;
}
