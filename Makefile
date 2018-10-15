CC = gcc
TEST_FILES = $(wildcard tests/*.c)
TEST_OUTPUT = run_tests
FILES = $(wildcard src/*.c)
LIB_FILES = src/numeral_calculator.c
DEMO_PROGRAM = demo/demo_program.c
DEMO_OUTPUT = demo_program
LIB_NAME = libnumeralcalculator.a
CFLAGS = -Wall
TST_LIBS = -lcheck -lm -lpthread -lrt
DIR = ./src

all: testsuite library demoprogram

testsuite: $(FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(FILES) $(TEST_FILES) -o $(TEST_OUTPUT) -I $(DIR) $(TST_LIBS)

library: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -c
	ar rcs $(LIB_NAME) $(LIB_FILES)

demoprogram: $(DEMO_PROGRAM)
	$(CC) $(CFLAGS) $(DEMO_PROGRAM) -o $(DEMO_OUTPUT) -I $(DIR) ./$(LIB_NAME)
clean: 
	rm -rf *.o

