#include <stdlib.h>
#include <string.h>
#include "numeral_converter.h"


static int add_decimals(int operand1, int operand2);
static int subtract_decimals(int operand1, int operand2);
static int calculate_numerals(char *operand1, char *operand2, char *numeral_result, int (*operation)(int, int));


int add_numerals(char *operand1, char *operand2, char *sum)
{
	return calculate_numerals(operand1, operand2, sum, add_decimals);
}

int subtract_numerals(char *operand1, char *operand2, char *difference)
{
	return calculate_numerals(operand1, operand2, difference, subtract_decimals);
}


static int add_decimals(int operand1, int operand2)
{
	return operand1 + operand2;
}

static int subtract_decimals(int operand1, int operand2)
{
	return operand1 - operand2;
}

static int calculate_numerals(char *operand1, char *operand2, char *numeral_result, int (*operation)(int, int))
{
	int result = 1;
	int decimal_result = 0;
	int decimal1 = 0;
	int decimal2 = 0;

	if(numeral_to_decimal(operand1, &decimal1) == 0 && numeral_to_decimal(operand2, &decimal2) == 0)
	{
		decimal_result = operation(decimal1, decimal2);

		if(decimal_to_numeral(decimal_result, numeral_result) == 0)
		{
			result = 0;
		}
	}

	return result;
}

