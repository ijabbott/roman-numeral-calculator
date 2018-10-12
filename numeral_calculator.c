#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeral_converter.h"

void add_numerals(char *operand1, char *operand2, char *sum)
{
	int decimal_sum = 0;

	int decimal1 = 0;
	int decimal2 = 0;

	numeral_to_decimal(operand1, &decimal1);
	numeral_to_decimal(operand2, &decimal2);

	decimal_sum = decimal1 + decimal2;

	decimal_to_numeral(decimal_sum, sum);
}

void subtract_numerals(char *operand1, char *operand2, char *difference)
{

}
