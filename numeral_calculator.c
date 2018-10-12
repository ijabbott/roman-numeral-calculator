#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeral_converter.h"

#define MIN_VALUE 1
#define MAX_VALUE 3999

typedef enum Operation_E
{
	ADDITION,
	SUBTRACTION
} Operation_T;

static int calculate_numerals(char *operand1, char *operand2, char *numeral_result, Operation_T op);

int add_numerals(char *operand1, char *operand2, char *sum)
{
	return calculate_numerals(operand1, operand2, sum, ADDITION);
}

int subtract_numerals(char *operand1, char *operand2, char *difference)
{
	return calculate_numerals(operand1, operand2, difference, SUBTRACTION);
}

static int calculate_numerals(char *operand1, char *operand2, char *numeral_result, Operation_T op)
{
	int result = 1;
	int decimal_result = 0;
	int decimal1 = 0;
	int decimal2 = 0;

	if(numeral_to_decimal(operand1, &decimal1) == 0 && numeral_to_decimal(operand2, &decimal2) == 0)
	{
		if(decimal1 >= MIN_VALUE && decimal1 <= MAX_VALUE)
		{
			if(op == ADDITION)
			{
				decimal_result = decimal1 + decimal2;
			}
			else if(op == SUBTRACTION)
			{
				decimal_result = decimal1 - decimal2;
			}

			if(decimal_result >= MIN_VALUE && decimal_result <= MAX_VALUE)
			{
				decimal_to_numeral(decimal_result, numeral_result);
				result = 0;
			}
		}
	}

	return result;
}
