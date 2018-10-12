#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeral_converter.h"

#define MIN_VALUE 1
#define MAX_VALUE 3999

int add_numerals(char *operand1, char *operand2, char *sum)
{
	int result = 1;
	int decimal_sum = 0;
	int decimal1 = 0;
	int decimal2 = 0;

	if(numeral_to_decimal(operand1, &decimal1) == 0 && numeral_to_decimal(operand2, &decimal2) == 0)
	{
		decimal_sum = decimal1 + decimal2;

		if(decimal_sum < MAX_VALUE)
		{
			decimal_to_numeral(decimal_sum, sum);
			result = 0;
		}
	}

	return result;
}

int subtract_numerals(char *operand1, char *operand2, char *difference)
{
	int result = 1;
	int decimal_difference = 0;
	int decimal1 = 0;
	int decimal2 = 0;

	if(numeral_to_decimal(operand1, &decimal1) == 0 && numeral_to_decimal(operand2, &decimal2) == 0)
	{
		decimal_difference = decimal1 - decimal2;

		if(decimal_difference >= MIN_VALUE)
		{
			decimal_to_numeral(decimal_difference, difference);
			result = 0;
		}
	}

	return result;	
}
