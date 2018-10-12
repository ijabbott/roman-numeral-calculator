#include <stdlib.h>
#include <string.h>

void numeral_to_decimal(char *numeral, int *decimal)
{	
	int i;
	
	for(i = 0; i < strlen(numeral); i++)
	{
		if(numeral[i] == 'I')
		{
			if(numeral[i + 1] == 'V' || numeral[i + 1] == 'X')
			{
				*decimal -= 1;
			}
			else
			{
				*decimal += 1;
			}
		}
		else if(numeral[i] == 'V')
		{
			*decimal += 5;
		}
		else if(numeral[i] == 'X')
		{
			if(numeral[i + 1] == 'L')
			{
				*decimal -= 10;
			}
			else
			{
				*decimal += 10;
			}
		}
		else if(numeral[i] == 'L')
		{
			*decimal += 50;
		}
	}
}

void decimal_to_numeral(int decimal, char *numeral)
{
	int decimal_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char *numeral_list[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	int i;

	for(i = 0; i < sizeof(decimal_list) / sizeof(decimal_list[0]); i++)
	{
		while(decimal_list[i] <= decimal)
		{
			strcat(numeral, numeral_list[i]);
			decimal -= decimal_list[i];
		}
	}
}
