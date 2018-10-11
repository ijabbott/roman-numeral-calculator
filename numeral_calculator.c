#include <stdlib.h>
#include <string.h>

void add_numerals(char *operand1, char *operand2, char *sum)
{
	strcpy(sum, operand1);
	strcat(sum, operand2);
	if(strcmp(sum, "IIII") == 0)
	{
		memset(sum, 0, strlen(sum) + 1);
		strcpy(sum, "IV");
	}
	if(strcmp(sum, "IIIII") == 0)
	{
		memset(sum, 0, strlen(sum) + 1);
		strcpy(sum, "V");
	}

}
