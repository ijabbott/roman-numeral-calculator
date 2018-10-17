#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "numeral_calculator.h"

#define BUFFER_SIZE 100
#define MAX_STRING_SIZE 15

#define ADD '+'
#define SUBTRACT '-'

#define ADD_DELIMITERS " +\n\r"
#define SUBTRACT_DELIMITERS " -\n\r"

#define ESCAPE_CHAR 'e'

static void calculate_numerals(char *delimiters, char *buffer, int (*calculation)(char*, char*, char*));


/* This is a quick demo program to test the numeral_calculator library */
int main(void)
{
	char buffer[BUFFER_SIZE];

	printf("Enter e to exit.\n");

	while(1)
	{
		printf("Enter your numeral equation:\n");

		fgets(buffer, BUFFER_SIZE, stdin);

		if(buffer[0] == ESCAPE_CHAR)
		{
			return 0;
		}

		if(strchr(buffer, ADD) != NULL)
		{
			calculate_numerals(ADD_DELIMITERS, buffer, add_numerals);
		}
		else if(strchr(buffer, SUBTRACT) != NULL)
		{
			calculate_numerals(SUBTRACT_DELIMITERS, buffer, subtract_numerals);
		}
		else
		{
			printf("Invalid equation\n");
		}
	}

	return 0;
}

static void calculate_numerals(char *delimiters, char *buffer, int (*calculation)(char*, char*, char*))
{
	char operand1[15];
	char operand2[15];
	char result[15];

	char *token;

	memset(operand1, 0, sizeof(operand1));
	memset(operand2, 0, sizeof(operand2));
	memset(result, 0, sizeof(result));

	token = strtok(buffer, delimiters);		
	strcpy(operand1, token);
	token = strtok(NULL, delimiters);		
	strcpy(operand2, token);

	if(calculation(operand1, operand2, result) == 0)
	{
		printf("Result is: %s\n", result);
	}
	else
	{
		printf("Invalid equation\n");
	}
}
