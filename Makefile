CC = gcc
FILES = check_calculations.c check_roman_to_decimal.c check_decimal_to_roman.c numeral_calculator.c numeral_converter.c suite_runner.c
OUTPUT = run_tests
CFLAGS = -Wall
TST_LIBS = -lcheck -lm -lpthread -lrt

check_numerals: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT) $(TST_LIBS)
clean: 
	rm -rf *.o

