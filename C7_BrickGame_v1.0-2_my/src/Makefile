TARGET = tetris
CC = gcc
CFLAGS = -std=c99 
TEST_FLAGS = -std=c11 -g

SRC = ../src/brick_game/tetris/*.c 
GUI = ../src/gui/cli/*.c
OBJ = *.o
TEST = ./tests/tests.c
TEST_PATH = ./tests/
MAIN= ../src/brick_game/main.c

OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck
	OPEN_CMD = xdg-open
else
	CHECK_FLAGS = -lcheck -pthread -lm `pkg-config --cflags --libs check`
	OPEN_CMD = open
endif

all: clean install
	./$(TARGET) 


create_tests:
	checkmk clean_mode=1 $(TEST_PATH)*.check >$(TEST_PATH)tests.c 

dvi:
	open ./README.md

dist:
	tar -czf tetris.install.tar.gz ./* 


gcov_report: clean test
	$(CC) $(CFLAGS) $(TEST_FLAGS) -fprofile-arcs -ftest-coverage $(OBJ) $(TEST) -o test -lncurses $(CHECK_FLAGS) $(GCOVFLAGS)
	lcov -t test -o rep.info -c -d .
	genhtml rep.info --output-directory report
	genhtml -o report rep.info 
	$(OPEN_CMD) ./report/index.html
	rm -f *.gcno *.info *.gcda 



test: clean  backend.o create_tests
	$(CC) $(CFLAGS) $(TEST_FLAGS) -fprofile-arcs -ftest-coverage $(SRC) $(TEST) -o test -lncurses $(CHECK_FLAGS) $(GCOVFLAGS)
	./test
	



install: backend.o frontend.o
	$(CC) $(CFLAGS) -o $(TARGET) *.o $(MAIN) -lncurses
	rm -rf *.o



backend.a: backend.o
	ar rcs $(TARGET).a *.o
	ranlib $(TARGET).a


backend.o: 
	$(CC) $(CFLAGS) -c $(SRC)


frontend.o: 
	$(CC) $(CFLAGS) -c $(GUI)


uninstall: clean


check: install
	leaks -atExit -- ./$(TARGET) 

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(SRC) $(GUI)
	clang-format -i $(GUI) $(SRC)
	rm -rf .clang-format

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f test
	-rm -f tests
	-rm -f greport
	-rm -rf report
	-rm -f tetris.install.tar.gz 
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
	

.PHONY: backend.o frontend.o