CC = gcc
TEST_FILES = $(wildcard tests/*.c)
TEST_OUTPUT = run_tests
FILES = $(wildcard src/*.c)
FILE_OBJECTS = $(wildcard src/*.o)
LIB_NAME = libnumeralcalculator.a
CFLAGS = -Wall
TST_LIBS = -lcheck -lm -lpthread -lrt
DIR = ./src

all: testsuite library clean

testsuite: $(FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(FILES) $(TEST_FILES) -o $(TEST_OUTPUT) -I $(DIR) $(TST_LIBS)

library: $(FILES) $(FILE_OBJECTS)
	$(CC) $(CFLAGS) $(FILES) -c
	ar rcs $(LIB_NAME) $(FILES) $(FILE_OBJECTS)

clean: 
	rm -rf *.o

