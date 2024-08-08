#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"
#define EPS 0.000001L

START_TEST(s21_abs_test_f) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(5), abs(5));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
  ck_assert_int_eq(s21_abs(-0xA13), abs(-0xA13));
  ck_assert_int_eq(s21_abs(13), abs(13));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(-05), abs(-05));
  ck_assert_int_eq(s21_abs(-00002345670), abs(-00002345670));
  ck_assert_int_eq(s21_abs(123456789), abs(123456789));
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(s21_acos_test_f) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_acos(value1), acos(value1));
  double value2 = -1;
  ck_assert_int_eq(s21_acos(value2), acos(value2));
  double value3 = -0.999;
  ck_assert_int_eq(s21_acos(value3), acos(value3));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  for (double i = -10.; i < 10.; i += 1.) {
    ck_assert_int_eq(s21_acos(i), acos(i));
  }
  for (double i = -1; i < 1; i += 0.01) {
    ck_assert_int_eq(s21_acos(i), acos(i));
  }
}
END_TEST

START_TEST(s21_asin_test_f) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_asin(value1), asin(value1));
  double value2 = 0.12;
  ck_assert_int_eq(s21_asin(value2), asin(value2));
  for (double i = 0.; i < 2; i += 1) {
    ck_assert_int_eq(s21_asin(i), asin(i));
  }
  for (double i = -1; i < 5; i += 0.01) {
    ck_assert_int_eq(s21_asin(i), asin(i));
  }
}
END_TEST

START_TEST(s21_atan_test_f) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_atan(value1), atan(value1));
  double value2 = 0.12;
  ck_assert_int_eq(s21_atan(value2), atan(value2));
  double value3 = 1;
  ck_assert_int_eq(s21_atan(value3), atan(value3));
  double value4 = -1;
  ck_assert_int_eq(s21_atan(value4), atan(value4));
  double value5 = 0;
  ck_assert_int_eq(s21_atan(value5), atan(value5));
  double value6 = 12345;
  ck_assert_int_eq(s21_atan(value6), atan(value6));
  double value7 = 0.001;
  ck_assert_int_eq(s21_atan(value7), atan(value7));
  double value8 = -12345;
  ck_assert_int_eq(s21_atan(value8), atan(value8));
  double x = s21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  ck_assert_ldouble_eq_tol(atan(s21_INF_NEG), s21_atan(s21_INF_NEG), 1e-6);
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_int_eq(s21_atan(i), atan(i));
  }
}
END_TEST

START_TEST(s21_ceil_test_f) {
  double value1 = 1.5;
  ck_assert_uint_eq(s21_ceil(value1), ceil(value1));
  double value2 = 0.45;
  ck_assert_uint_eq(s21_ceil(value2), ceil(value2));
  double value3 = -3.01;
  ck_assert_uint_eq(s21_ceil(value3), ceil(value3));
  double value4 = -0;
  ck_assert_uint_eq(s21_ceil(value4), ceil(value4));
  double value5 = 1234567;
  ck_assert_uint_eq(s21_ceil(value5), ceil(value5));
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_nan(ceil(s21_NAN));
  double x = s21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_cos_test_f) {
  double value1 = 0;
  ck_assert_int_eq(s21_cos(value1), cos(value1));
  double value2 = 112343;
  ck_assert_int_eq(s21_cos(value2), cos(value2));
  double value3 = -312345;
  ck_assert_int_eq(s21_cos(value3), cos(value3));
  ck_assert_ldouble_eq_tol(cos(-1), s21_cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(cos(1), s21_cos(1), 1e-6);
  for (double i = -s21_PI; i < s21_PI; i += 0.01) {
    ck_assert_int_eq(s21_cos(i), cos(i));
  }
}
END_TEST

START_TEST(s21_exp_test_f) {
  ck_assert_uint_eq(s21_exp(5), exp(5));
  ck_assert_uint_eq(s21_exp(-2), exp(-2));
  ck_assert_uint_eq(s21_exp(1234567), exp(1234567));
  ck_assert_uint_eq(s21_exp(-1234567), exp(-1234567));
  for (double i = -10; i < 10; i++) {
    ck_assert_uint_eq(s21_exp(i), exp(i));
  }
  double x = DBL_MIN;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
  ck_assert_ldouble_nan(s21_exp(s21_NAN));
  ck_assert_ldouble_eq(exp(s21_INF), s21_exp(s21_INF));
  ck_assert_ldouble_eq(exp(s21_INF_NEG), s21_exp(s21_INF_NEG));
  ck_assert_ldouble_eq_tol(exp(1.0), s21_exp(1.0), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test_f) {
  ck_assert_uint_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_uint_eq(s21_fabs(-45.345), fabs(-45.345));
  ck_assert_uint_eq(s21_fabs(1.0), fabs(1.0));
  ck_assert_ldouble_nan(s21_fabs(s21_NAN));
}
END_TEST

START_TEST(s21_floor_test_f) {
  double value1 = 1.5;
  ck_assert_uint_eq(s21_floor(value1), floor(value1));
  double value2 = 0.45;
  ck_assert_uint_eq(s21_floor(value2), floor(value2));
  double value3 = -3.01;
  ck_assert_uint_eq(s21_floor(value3), floor(value3));
  double value4 = -0.;
  ck_assert_uint_eq(s21_floor(value4), floor(value4));
  double value5 = -0;
  ck_assert_uint_eq(s21_floor(value5), floor(value5));
  ck_assert_ldouble_nan(s21_floor(s21_NAN));
  ck_assert_ldouble_eq(s21_floor(s21_INF), floor(s21_INF));
}
END_TEST

START_TEST(s21_fmod_test_f) {
  ck_assert_int_eq(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7));
  ck_assert_int_eq(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1));
  ck_assert_int_eq(s21_fmod(23.456, 4.355), fmod(23.456, 4.355));
  ck_assert_int_eq(s21_fmod(23.456, -4.355), fmod(23.456, -4.355));
  ck_assert_int_eq(s21_fmod(-23.456, 4.355), fmod(-23.456, 4.355));
  ck_assert_int_eq(s21_fmod(0.0, 4.355), fmod(0.0, 4.355));
  ck_assert_ldouble_nan(s21_fmod(s21_INF, 5.5));
  ck_assert_int_eq(s21_fmod(4.355, 4.355), fmod(4.355, 4.355));
}
END_TEST

START_TEST(s21_log_test_f) {
  double a = s21_INF;
  ck_assert_ldouble_infinite(log(a));
  ck_assert_ldouble_infinite(s21_log(a));
}

START_TEST(s21_log_test2_f) {
  double a = s21_NAN;
  ck_assert_ldouble_nan(log(a));
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(s21_log_test3_f) {
  double a = -0.000003;
  ck_assert_ldouble_nan(log(a));
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(s21_log_test4_f) {
  double a = 131223;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), EPS);
}
END_TEST

START_TEST(s21_log_test5_f) {
  double a = 0.000123;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), EPS);
}
END_TEST

START_TEST(s21_log_test6_f) {
  double a = 123.123123;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), EPS);
}
END_TEST

START_TEST(s21_pow_test_f) {
  ck_assert_int_eq(s21_pow(2.6, 3.45), pow(2.6, 3.45));
  ck_assert_int_eq(s21_pow(3.0, 14.0), pow(3.0, 14.0));
  ck_assert_int_eq(s21_pow(31.456, 4.3), pow(31.456, 4.3));
  ck_assert_int_eq(s21_pow(31.456, 0.3), pow(31.456, 0.3));
  ck_assert_int_eq(s21_pow(4.3, 4.3), pow(4.3, 4.3));
  ck_assert_int_eq(s21_pow(-1234, 4.3), pow(-1234, 4.3));
  ck_assert_int_eq(s21_pow(-1234, -4.3), pow(-1234, -4.3));
  ck_assert_int_eq(s21_pow(1234, -4.3), pow(1234, -4.3));
  ck_assert_ldouble_eq_tol(pow(-1.0, s21_INF), s21_pow(-1.0, s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(pow(0.123, s21_INF), s21_pow(0.123, s21_INF), 1e-6);
  ck_assert_ldouble_eq(pow(s21_NEG_ZERO, 12.0), s21_pow(s21_NEG_ZERO, 12.0));
  ck_assert_ldouble_eq_tol(pow(0.0, 12.0), s21_pow(0.0, 12.0), 1e-6);
  ck_assert_ldouble_eq_tol(pow(-1.0, s21_INF), s21_pow(-1.0, s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(pow(-10.1, 2.0), s21_pow(-10.1, 2.0), 1e-6);
  ck_assert_ldouble_infinite(s21_pow(13, s21_INF));
  ck_assert_ldouble_infinite(pow(13, s21_INF));
  ck_assert_ldouble_eq_tol(pow(s21_INF_NEG, -13), s21_pow(s21_INF_NEG, -13),
                           1e-6);
  ck_assert_ldouble_eq_tol(pow(DBL_MIN, 10.0), s21_pow(DBL_MIN, 10.0), 1e-6);
  ck_assert_ldouble_eq_tol(pow(13.0, s21_INF_NEG), s21_pow(13.0, s21_INF_NEG),
                           1e-6);
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_ldouble_eq_tol(pow(-3.0, 1.0), s21_pow(-3.0, 1.0), 1e-6);
  ck_assert_ldouble_eq(pow(s21_INF_NEG, 1.0), s21_pow(s21_INF_NEG, 1.0));
  ck_assert_ldouble_eq(pow(s21_NEG_ZERO, 1.0), s21_pow(s21_NEG_ZERO, 1.0));
}
END_TEST

START_TEST(s21_sin_test_f) {
  double value1 = 0;
  ck_assert_int_eq(s21_sin(value1), sin(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_sin(value2), sin(value2));
  double value3 = -3234567;
  ck_assert_int_eq(s21_sin(value3), sin(value3));
  ck_assert_ldouble_nan(s21_sin(s21_NAN));
  ck_assert_ldouble_nan(s21_sin(s21_INF));
  for (double i = -s21_PI; i < s21_PI; i += 0.01) {
    ck_assert_int_eq(s21_sin(i), sin(i));
  }
}
END_TEST

START_TEST(s21_sqrt_test_f) {
  ck_assert_int_eq(s21_sqrt(16.0), sqrt(16.0));
  ck_assert_int_eq(s21_sqrt(45.35), sqrt(45.35));
  ck_assert_int_eq(s21_sqrt(5.0), sqrt(5.0));
  ck_assert_ldouble_eq(sqrt(s21_INF), s21_sqrt(s21_INF));
  ck_assert_ldouble_nan(s21_sqrt(s21_INF_NEG));
  for (double i = -1.; i < 100000; i += 10) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
  for (double i = 0; i < 1; i += 0.001) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
}
END_TEST

START_TEST(s21_tan_test_f) {
  double value1 = 0.23;
  ck_assert_int_eq(s21_tan(value1), tan(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_tan(value2), tan(value2));
  double value3 = -1234567;
  ck_assert_int_eq(s21_tan(value3), tan(value3));
  ck_assert_ldouble_nan(s21_tan(s21_INF));
  ck_assert_ldouble_nan(s21_tan(s21_NAN));
  ck_assert_int_eq(s21_tan(2), tan(2));
  ck_assert_int_eq(s21_tan(-2), tan(-2));
  ck_assert_int_eq(s21_tan(s21_PI / 2), tan(s21_PI / 2));
  ck_assert_int_eq(s21_tan(-s21_PI / 2), tan(-s21_PI / 2));

  for (double i = -100; i < 100; i += 2) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Func Check");

  TCase *tc_ceil;
  TCase *tc_floor;
  TCase *tc_tan;
  TCase *tc_cos;
  TCase *tc_sin;
  TCase *tc_abs;
  TCase *tc_atan;
  TCase *tc_acos;
  TCase *tc_asin;
  TCase *tc_fmod;
  TCase *tc_exp;
  TCase *tc_log;
  TCase *tc_sqrt;
  TCase *tc_pow;
  TCase *tc_fabs;

  tc_abs = tcase_create("Abs func testing");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, s21_abs_test_f);

  tc_acos = tcase_create("Acos func testing");
  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, s21_acos_test_f);

  tc_asin = tcase_create("Asin func testing");
  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, s21_asin_test_f);

  tc_atan = tcase_create("Atan func testing");
  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, s21_atan_test_f);

  tc_ceil = tcase_create("Ceil func testing");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_test_f);

  tc_cos = tcase_create("Cos func testing");
  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, s21_cos_test_f);

  tc_exp = tcase_create("Exp func testing");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, s21_exp_test_f);

  tc_fabs = tcase_create("Fabs func testing");
  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_test_f);

  tc_floor = tcase_create("Floor func testing");
  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, s21_floor_test_f);

  tc_fmod = tcase_create("Fmod func testing");
  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_test_f);

  tc_log = tcase_create("Log func testing");
  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, s21_log_test_f);
  tcase_add_test(tc_log, s21_log_test2_f);
  tcase_add_test(tc_log, s21_log_test3_f);
  tcase_add_test(tc_log, s21_log_test4_f);
  tcase_add_test(tc_log, s21_log_test5_f);
  tcase_add_test(tc_log, s21_log_test6_f);

  tc_pow = tcase_create("Pow func testing");
  suite_add_tcase(s, tc_pow);
  tcase_add_test(tc_pow, s21_pow_test_f);

  tc_sin = tcase_create("Sin func testing");
  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, s21_sin_test_f);

  tc_sqrt = tcase_create("Sqrt func testing");
  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_test_f);

  tc_tan = tcase_create("Tan func testing");
  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, s21_tan_test_f);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
  return 0;
}
