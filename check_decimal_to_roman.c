#include <stdlib.h>
#include <check.h>
#include "check_decimal_to_roman.h"
#include "numeral_converter.h"

#define MAX_LENGTH 12 // MMMCCCXXXIII

/* Cases Covered
	- Each individual numearl
	- Repeated numerals
	- Lesser numeral before larger numeral
	- Lesser numeral after larger numeral
	- Lesser numeral between two larger numerals
	- Maximum numeral 
*/

START_TEST(test_convert_1_to_I)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(1, numeral);
	ck_assert_str_eq("I", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_2_to_II)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(2, numeral);
	ck_assert_str_eq("II", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_4_to_IV)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(4, numeral);
	ck_assert_str_eq("IV", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_5_to_V)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(5, numeral);
	ck_assert_str_eq("V", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_6_to_VI)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(6, numeral);
	ck_assert_str_eq("VI", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_9_to_IX)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(9, numeral);
	ck_assert_str_eq("IX", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_10_to_X)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(10, numeral);
	ck_assert_str_eq("X", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_11_to_XI)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(11, numeral);
	ck_assert_str_eq("XI", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_14_to_XIV)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(14, numeral);
	ck_assert_str_eq("XIV", numeral);
	free(numeral);
}
END_TEST


START_TEST(test_convert_15_to_XV)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(15, numeral);
	ck_assert_str_eq("XV", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_16_to_XVI)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(16, numeral);
	ck_assert_str_eq("XVI", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_40_to_XL)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(40, numeral);
	ck_assert_str_eq("XL", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_50_to_L)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(50, numeral);
	ck_assert_str_eq("L", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_100_to_C)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(100, numeral);
	ck_assert_str_eq("C", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_500_to_D)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(500, numeral);
	ck_assert_str_eq("D", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_1000_to_M)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(1000, numeral);
	ck_assert_str_eq("M", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_3999_to_MMMCMXCIX)
{
	char *numeral = malloc(MAX_LENGTH);
	
	decimal_to_numeral(3999, numeral);
	ck_assert_str_eq("MMMCMXCIX", numeral);
	free(numeral);
}
END_TEST

Suite * decimal_to_roman_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Decimal to Roman Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_convert_1_to_I);
	tcase_add_test(tc_core, test_convert_2_to_II);
	tcase_add_test(tc_core, test_convert_4_to_IV);
	tcase_add_test(tc_core, test_convert_5_to_V);
	tcase_add_test(tc_core, test_convert_6_to_VI);
	tcase_add_test(tc_core, test_convert_9_to_IX);
	tcase_add_test(tc_core, test_convert_10_to_X);
	tcase_add_test(tc_core, test_convert_11_to_XI);
	tcase_add_test(tc_core, test_convert_14_to_XIV);
	tcase_add_test(tc_core, test_convert_15_to_XV);
	tcase_add_test(tc_core, test_convert_16_to_XVI);
	tcase_add_test(tc_core, test_convert_40_to_XL);
	tcase_add_test(tc_core, test_convert_50_to_L);
	tcase_add_test(tc_core, test_convert_100_to_C);
	tcase_add_test(tc_core, test_convert_500_to_D);
	tcase_add_test(tc_core, test_convert_1000_to_M);
	tcase_add_test(tc_core, test_convert_3999_to_MMMCMXCIX);

	suite_add_tcase(s, tc_core);

	return s;
}
