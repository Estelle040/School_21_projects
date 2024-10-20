OS := $(shell uname)
CFLAGS = -Wall -Werror -Wextra -std=c++17 
FLAGS = -lgtest -ftest-coverage -fprofile-arcs -lstdc++ 
V_COMMAND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt


ifeq ($(OS),Darwin)
	OPEN_CMD = open 
else
	OS := $(shell hostnamectl | grep System | awk '{print $$3}')
	ifeq ($(OS),Ubuntu)
		FLAGS += -lm -lrt -lsubunit
	endif
	OPEN_CMD = xdg-open 
endif

all: clean s21_matrix_oop.a test

s21_matrix_oop.a:
	gcc $(CFLAGS) -c s21_matrix_oop.cpp -ftest-coverage -fprofile-arcs
	ar -crs s21_matrix_oop.a s21_matrix_oop.o


test: clean s21_matrix_oop.a
	gcc $(CFLAGS) test.cpp s21_matrix_oop.cpp -o test $(FLAGS)
	./test

valgrind: test
	$(eval FLAGS += -g)
	$(V_COMMAND) ./test


clean:
	rm -rf *.o *.a test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info
	rm -rf RESULT_VALGRIND.txt
