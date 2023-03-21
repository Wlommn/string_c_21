CC = gcc
AR = ar rc
RAN = ranlib
OS = $(shell uname -s)
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOVFLAGS = --coverage

ifeq ($(OS), Linux)
SYSFLAGS = -lcheck -lm
else
SYSFLAGS = -lcheck
endif

TEST_MAIN = ./Tests/s21_string_tests.c
TEST_MAIN_OBJ = ./Tests/s21_string_tests.o

GCOV_MAIN_OBJ = ./Tests/s21_string_gcovTests.o

TEST_SRC:=$(shell find ./Tests/TestCases -name "*.c")
GCOV_SRC:=$(shell find ./Tests/TestCases -name "*.c")

TEST_OBJ:=$(addprefix ./Tests/TestCases/, $(notdir $(TEST_SRC:.c=.o)))
GCOV_TEST_OBJ:=$(addprefix ./Tests/TestCases/, $(notdir $(GCOV_SRC:.c=.o)))

OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))

TEST_DIR = ./Tests
TEST_CASE_DIR = ./Tests/TestCases

GCOV_CASE_DIR = ./Tests/TestCases


all: s21_string.a test gcov_report
	$(MAKE) clean

s21_string.a: $(OBJECTS)
	$(AR) s21_string.a $(OBJECTS)
	$(RAN) s21_string.a

$(TEST_MAIN_OBJ): $(TEST_MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_CASE_DIR)%.o: $(TEST_CASE_DIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_OBJ) $(TEST_MAIN_OBJ) s21_string.a
	$(CC) $(CFLAGS) $(TEST_OBJ) $(TEST_MAIN_OBJ) $(GCOVFLAGS) -o ./test $(SYSFLAGS) -L. ./s21_string.a

$(GCOV_MAIN_OBJ): $(TEST_MAIN)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

$(GCOV_CASE_DIR)%.o: $(GCOV_CASE_DIR)%.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

gcov_tests: $(GCOV_TEST_OBJ) $(GCOV_MAIN_OBJ) s21_string.a
	$(CC) $(GCOVFLAGS) $(CFLAGS) -fprofile-arcs -ftest-coverage $(GCOV_TEST_OBJ) $(GCOV_MAIN_OBJ) -o ./Tests/gcov_tests $(SYSFLAGS) -L. ./s21_string.a

gcov_report: gcov_info
	genhtml ./Tests/gcov.info -o gcov_report
	$(MAKE) clean

gcov_info: gcov_tests 
	./Tests/gcov_tests
	geninfo ./Tests -b . -o ./Tests/gcov.info

clean:
	rm -rf $(OBJECTS) $(TEST_OBJ) $(TEST_MAIN_OBJ) $(GCOV_MAIN_OBJ)
	rm -rf $(TEST_DIR)/gcov_tests $(TEST_DIR)/gcov.info
	rm -rf ./*.gcda $(TEST_DIR)/*.gcda $(TEST_CASE_DIR)/*.gcda
	rm -rf ./*.gcno $(TEST_DIR)/*.gcno $(TEST_CASE_DIR)/*.gcno
	clear

rebuild:
	$(MAKE) clean
	$(MAKE) all