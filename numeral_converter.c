#include <stdlib.h>
#include <string.h>

void numeral_to_decimal(char *numeral, int *decimal)
{	
	int i;
	
	for(i = 0; i < strlen(numeral); i++)
	{
		if(numeral[i] == 'I')
		{
			*decimal += 1;
		}
		if(numeral[i] == 'V')
		{
			*decimal += 5;
		}
	}
}

void decimal_to_numeral(int decimal, char *numeral)
{
	if(decimal == 1)
	{
		strcat(numeral, "I");
	}
	else if(decimal == 2)
	{
		strcat(numeral, "II");
	}
	else if(decimal == 3)
	{
		strcat(numeral, "III");
	}
	else if(decimal == 4)
	{
		strcat(numeral, "IV");
	}
	else if(decimal == 5)
	{
		strcat(numeral, "V");
	}
}
