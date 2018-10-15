/**
 * Function: add_numerals
 * 	Adds two unique roman numeral operands
 *
 *	operand1[in]: First roman numeral operand
 *	operand2[in]: Second roman numeral operand
 *	sum[out]: Roman numeral result 
 *
 *	The maximum roman numeral is MMMCMXCIX (3999)
 *	The minimum roman numeral is I (1)
 *
 *	returns: 
 * 		0 - Addition Success
 *		1 - Invalid Numeral
 */
int add_numerals(char *operand1, char *operand2, char *sum);

/**
 * Function: subtract_numerals
 * 	Subtracts the second unique roman numeral operand from the first
 *
 *	operand1[in]: First roman numeral operand
 *	operand2[in]: Second roman numeral operand
 *	difference[out]: Roman numeral result 
 *
 *	The maximum roman numeral is MMMCMXCIX (3999)
 *	The minimum roman numeral is I (1)
 *
 *	returns: 
 * 		0 - Subtraction Success
 *		1 - Invalid Numeral
 */
int subtract_numerals(char *operand1, char *operand2, char *difference);
