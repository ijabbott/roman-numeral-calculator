#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "numeral_calculator.h"

int main(void)
{
	char buffer[100];
	char *str1 = malloc(15);
	char *str2 = malloc(15);
	char *str3 = malloc(15);
	char *token;

	printf("Enter your numeral equation:\n");

	fgets(buffer, 100, stdin);

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
	
	return 0;
}
