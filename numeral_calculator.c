#include <stdlib.h>
#include <string.h>

void add_numerals(char *operand1, char *operand2, char *sum)
{
	strcpy(sum, operand1);
	strcat(sum, operand2);
}
