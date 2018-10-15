/**
 * Function: numeral_to_decimal
 * 	Converts a roman numeral into decimal format
 *
 *	numeral[in]: roman numeral to convert
 *	decimal[out]: decimal format of the roman numeral 
 *
 *	returns: 
 * 		0 - Conversion Success
 *		1 - Invalid Numeral
 */
int numeral_to_decimal(char *numeral, int *decimal);


/**
 * Function: decimal_to_numeral
 * 	Converts a decimal number to roman numeral format
 *
 *	decimal[in]: decimal number to convert
 *	numeral[out]: roman numeral format of the decimal number
 *
 *	returns: 
 * 		0 - Success
 *		1 - Failure
 */
int decimal_to_numeral(int decimal, char* numeral);

