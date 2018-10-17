#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "numeral_calculator.h"

#define BUFFER_SIZE 100
#define MAX_STRING_SIZE 15
/* This is a quick demo program to test the numeral_calculator library */

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *str1 = malloc(MAX_STRING_SIZE);
	char *str2 = malloc(MAX_STRING_SIZE);
	char *str3 = malloc(MAX_STRING_SIZE);
	char *token;

	printf("Enter e to exit.\n");

	while(1)
	{
		memset(str1, 0, MAX_STRING_SIZE);
		memset(str2, 0, MAX_STRING_SIZE);
		memset(str3, 0, MAX_STRING_SIZE);

		printf("Enter your numeral equation:\n");

		fgets(buffer, BUFFER_SIZE, stdin);

		if(buffer[0] == 'e')
		{
			return 0;
		}

		if(strchr(buffer, '+') != NULL)
		{
			token = strtok(buffer, " +\n\r");		
			strcpy(str1, token);
			token = strtok(NULL, " +\n\r");		
			strcpy(str2, token);

			if(add_numerals(str1, str2, str3) == 0)
			{
				printf("Result is: %s\n", str3);
			}
			else
			{
				printf("Invalid equation\n");
			}
		
		
		}
		else if(strchr(buffer, '-') != NULL)
		{
			token = strtok(buffer, " -\n\r");
		
			strcpy(str1, token);
			token = strtok(NULL, " -\n\r");
		
			strcpy(str2, token);
			if(subtract_numerals(str1, str2, str3) == 0)
			{
				printf("Result is: %s\n", str3);
			}
			else
			{
				printf("Invalid equation\n");
			}
		}
		else
		{
			printf("Invalid equation\n");
		}
	}

	return 0;
}
