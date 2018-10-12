#include <stdlib.h>
#include <check.h>
#include "numeral_converter.h"

START_TEST(test_convert_I_to_1)
{
	int decimal = 0;
	
	numeral_to_decimal("I", &decimal);
	ck_assert_int_eq(1, decimal);
}
END_TEST

START_TEST(test_convert_IV_to_4)
{
	int decimal = 0;
	
	numeral_to_decimal("IV", &decimal);
	ck_assert_int_eq(4, decimal);
}
END_TEST

START_TEST(test_convert_V_to_5)
{
	int decimal = 0;
	
	numeral_to_decimal("V", &decimal);
	ck_assert_int_eq(5, decimal);
}
END_TEST

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

Suite * conversion_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Conversion Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_convert_I_to_1);
	tcase_add_test(tc_core, test_convert_IV_to_4);
	tcase_add_test(tc_core, test_convert_V_to_5);
	tcase_add_test(tc_core, test_convert_1_to_I);
	tcase_add_test(tc_core, test_convert_5_to_V);
	suite_add_tcase(s, tc_core);

	return s;
}
