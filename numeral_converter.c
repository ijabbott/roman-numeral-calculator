#include <stdlib.h>
#include <string.h>

void numeral_to_decimal(char *numeral, int *decimal)
{	
	int decimal_list[] = {900, 400, 90, 40, 9, 4, 1000, 500, 100, 50, 10, 5, 1};
	char *numeral_list[] = {"CM", "CD", "XC", "XL", "IX", "IV", "M", "D", "C", "L", "X", "V", "I"};

	int j ;
	int i = 0;
	
	while(i < strlen(numeral))
	{
		for(j = 0; j < sizeof(numeral_list)/sizeof(numeral_list[0]); j++)
		{
			if(strncmp(&numeral[i], numeral_list[j], strlen(numeral_list[j])) == 0)
			{
				*decimal += decimal_list[j];
				i += strlen(numeral_list[j]);
			}
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
