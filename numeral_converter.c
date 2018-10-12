#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

const int decimal_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char *numeral_list[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const char valid_numerals[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I', '\0'};

void numeral_to_decimal(char *numeral, int *decimal)
{	
	int list_index;
	int numeral_index = 0;
	int i;
	int previous_value = 1000;

	if(strstr(numeral, "IIII") != NULL ||
	   strstr(numeral, "XXXX") != NULL ||
	   strstr(numeral, "CCCC") != NULL ||
	   strstr(numeral, "VV")   != NULL ||
	   strstr(numeral, "LL")   != NULL ||
	   strstr(numeral, "DD")   != NULL)
	{
		return;
	}
	
	for(i = 0; i < strlen(numeral); i++)
	{
		if(strchr(valid_numerals, numeral[i]) == NULL)
		{
			return;
		}
	}
	
	// Compare numeral character/s with the numeral list until there is a match, then shift the numeral index
	while(numeral_index < strlen(numeral))
	{
		for(list_index = 0; list_index < NELEMS(numeral_list); list_index++)
		{
			if(strncmp(&numeral[numeral_index], numeral_list[list_index], strlen(numeral_list[list_index])) == 0)
			{
				if(decimal_list[list_index] <= previous_value)
				{
					*decimal += decimal_list[list_index];
					previous_value = decimal_list[list_index];
					numeral_index += strlen(numeral_list[list_index]);
					break;
				}
				else
				{
					*decimal = 0;
					return;
				}
			}
		}
	}
}

void decimal_to_numeral(int decimal, char *numeral)
{
	int list_index;

	// Subtract the largest possible numeral value, adding that value to the string with each iteration
	for(list_index = 0; list_index < NELEMS(decimal_list); list_index++)
	{
		while(decimal_list[list_index] <= decimal)
		{
			strcat(numeral, numeral_list[list_index]);
			decimal -= decimal_list[list_index];
		}
	}
}
