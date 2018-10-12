#include <stdlib.h>
#include <check.h>
#include "check_decimal_to_roman.h"
#include "numeral_converter.h"

START_TEST(test_convert_1_to_I)
{
	char *numeral = malloc(2);
	
	decimal_to_numeral(1, numeral);
	ck_assert_str_eq("I", numeral);
	free(numeral);
}
END_TEST

START_TEST(test_convert_5_to_V)
{
	char *numeral = malloc(2);
	
	decimal_to_numeral(5, numeral);
	ck_assert_str_eq("V", numeral);
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
	tcase_add_test(tc_core, test_convert_5_to_V);

	suite_add_tcase(s, tc_core);

	return s;
}
