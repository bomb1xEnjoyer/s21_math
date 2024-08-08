CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})
SECONDFUNCS=is_inf.c is_nan.c remove_period.c int_pow.c
TARGET=s21_math.a
OS := $(shell uname -s)
ifeq ($(OS), Linux)
TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
endif
ifeq ($(OS), Darwin)
TEST_LIBS=-lcheck -lm
endif


all: $(TARGET) test gcov_report clean_test

$(TARGET): ${SRC}
	$(CC) -c $(CFLAGS) $(SRC) $(SECONDFUNCS)
	ar rc $@ $(OBJ) is_inf.o is_nan.o remove_period.o int_pow.o
	ranlib $@
	cp $@ lib$@
	make clean_obj


test: test_s21math.c s21_math.a
	$(CC) $(CFLAGS) -c test_s21math.c -o test.o
	$(CC) test.o s21_math.a $(TEST_LIBS) -o test

gcov_report: $(TARGET)
	$(CC) $(CFLAGS) --coverage test_s21math.c ${SRC} $(SECONDFUNCS) $(TARGET) -o gcov_test $(TEST_LIBS)
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info

style_test:
	cp ../materials/linters/.clang-format .
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n *.c *.h
	rm .clang-format

re:
	make clean
	make all

clean: clean_obj clean_lib clean_test
	rm -rf test
	rm -rf report
	

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test: clean_lib
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf gcov_test
	rm -rf test.o