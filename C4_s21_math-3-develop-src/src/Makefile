CFLAGS = -Wall -Werror -Wextra -std=c11
OBJ = s21_math
TEST= tests.sh
TEST_FLAGS = -std=c11 -g
GCOVFLAGS = -L. -ls21_math --coverage
OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck 
endif

UTIL = -fsanitize=address

TEST_COMPILE = $(CC) $(TEST_FLAGS) tests/all_tests.c libs21_math.a $(CHECK_FLAGS) -L. -ls21_math


all: style test clean

peer: gcov_report

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM debug *.txt ./tests/make* ./report/*

style:
	clang-format -i ./*.c ./*.h ./tests/*.c
	clang-format -n ./*.c ./*.h ./tests/*.c

leaks:
	cppcheck --enable=all --suppress=missingIncludeSystem .

good: clean all test
	sleep 3
	clear

me:
	gcc ./tests/test_maker.c -o ./tests/makesometest
	./tests/makesometest

rebuild: clean all

qt: clean test_local

test_local: s21_math.a
	gcc $(CFLAGS) libs21_math.a s21*.c test_main.c -o test_main.out

test: s21_math.a
	$(TEST_COMPILE)
	./a.out
	rm -rf *.gcda *.gcno ./a.out *.a *.o

val:  s21_math.a
	$(TEST_COMPILE)
	valgrind --tool=memcheck --leak-check=yes  --leak-check=full --show-leak-kinds=all ./a.out
	rm -rf *.gcda *.gcno ./a.out *.a *.o
	$ echo Библиотека check.h имеет утечки! Вертер их не учитывает.

s21_math.a: s21_math.o
	ar rcs libs21_math.a *.o
	rm -rf *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a

s21_math.o:
	$(CC) $(CC_FLAGS) -c s21*.c

gcov_report: clean s21_math.a
	rm -f *.g*
	gcc $(TEST_FLAGS) tests/all_tests.c ./s21*.c libs21_math.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o all_test.info -c -d .
	genhtml -o report all_test.info
	rm -rf *.gcda *.gcno ./a.out all_tests.info
	open ./report/index.html
	