CC = gcc
FILES = check_numerals.c numeral_calculator.c
OUTPUT = run_tests
CFLAGS = -Wall
TST_LIBS = -lcheck -lm -lpthread -lrt

check_numerals: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT) $(TST_LIBS)
clean: 
	rm -rf *.o

