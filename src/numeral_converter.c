#include <stdlib.h>
#include <string.h>


#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#define MIN_VALUE 1
#define MAX_VALUE 3999


static int is_numeral_invalid(char *numeral);
static int invalid_numeral_empty_or_null(char *numeral);
static int invalid_numeral_characters(char *numeral);
static int invalid_consecutive_characters(char *numeral);
static int invalid_numeral_order(char *numeral);
static int decimal_outside_range(int decimal);


const int decimal_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char *numeral_list[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const char valid_characters[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I', '\0'};


int numeral_to_decimal(char *numeral, int *decimal)
{	
	if(is_numeral_invalid(numeral))
	{
		return 1;
	}

	// Compare numeral character/s with the numeral list until there is a match, then shift the numeral index
	for(int numeral_index = 0; numeral_index < strlen(numeral); numeral_index++)
	{
		for(int list_index = 0; list_index < NELEMS(numeral_list); list_index++)
		{
			if(strncmp(&numeral[numeral_index], numeral_list[list_index], strlen(numeral_list[list_index])) == 0)
			{
				*decimal += decimal_list[list_index];
				numeral_index += strlen(numeral_list[list_index]) - 1;
				break;
			}
		}
	}

	return decimal_outside_range(*decimal);
}

int decimal_to_numeral(int decimal, char *numeral)
{
	if(decimal_outside_range(decimal))
	{
		return 1;
	}

	// Subtract the largest possible numeral value, adding that value to the string with each iteration
	for(int list_index = 0; list_index < NELEMS(decimal_list); list_index++)
	{
		while(decimal_list[list_index] <= decimal)
		{
			strcat(numeral, numeral_list[list_index]);
			decimal -= decimal_list[list_index];
		}
	}

	return 0;
}


static int is_numeral_invalid(char *numeral)
{
	int result = 0;

	if(invalid_numeral_empty_or_null(numeral)  ||
	   invalid_numeral_characters(numeral)     ||
	   invalid_consecutive_characters(numeral) ||
	   invalid_numeral_order(numeral))
	{
		result = 1;
	}
	
	return result;
}

static int invalid_numeral_empty_or_null(char *numeral)
{
	return numeral == NULL || strlen(numeral) == 0;
}

static int invalid_numeral_characters(char *numeral)
{
	int result = 0;

	for(int numeral_index = 0; numeral_index < strlen(numeral); numeral_index++)
	{
		if(strchr(valid_characters, numeral[numeral_index]) == NULL)
		{
			result = 1;;
		}
	}

	return result;
}

static int invalid_consecutive_characters(char *numeral)
{
	int result = 0;

	if(strstr(numeral, "IIII") != NULL ||
	   strstr(numeral, "XXXX") != NULL ||
	   strstr(numeral, "CCCC") != NULL ||
	   strstr(numeral, "VV")   != NULL ||
	   strstr(numeral, "LL")   != NULL ||
	   strstr(numeral, "DD")   != NULL)
	{
		result = 1;
	}

	return result;
}

static int invalid_numeral_order(char *numeral)
{
	int previous_value = decimal_list[0];
	int previous_subtraction_base = 0;

	// Search the numeral and verify that each numeral or numeral pair is less than the numeral before it
	// In the event of a numeral pair (IV, IX, etc.), the next numeral character must not make the pair exceed or equal the next greatest numeral value
	for(int numeral_index = 0; numeral_index < strlen(numeral); numeral_index++)
	{
		for(int list_index = 0; list_index < NELEMS(numeral_list); list_index++)
		{
			if(strncmp(&numeral[numeral_index], numeral_list[list_index], strlen(numeral_list[list_index])) == 0)
			{
				if((decimal_list[list_index] > previous_value) || 
				  (previous_subtraction_base != 0 && decimal_list[list_index] + previous_value >= previous_subtraction_base)) 
				{
					return 1;
				}

				if(strlen(numeral_list[list_index]) == 2)
				{
					previous_subtraction_base = decimal_list[list_index - 1];
				}

				previous_value = decimal_list[list_index];
				numeral_index += strlen(numeral_list[list_index]) - 1;
				break;
			}
		}
	}

	return 0;
}

static int decimal_outside_range(int decimal)
{
	return decimal < MIN_VALUE || decimal > MAX_VALUE;
}
