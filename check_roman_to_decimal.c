#include <stdlib.h>
#include <check.h>
#include "check_roman_to_decimal.h"
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

START_TEST(test_convert_X_to_10)
{
	int decimal = 0;
	
	numeral_to_decimal("X", &decimal);
	ck_assert_int_eq(10, decimal);
}
END_TEST

Suite * roman_to_decimal_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Roman to Decimal Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_convert_I_to_1);
	tcase_add_test(tc_core, test_convert_IV_to_4);
	tcase_add_test(tc_core, test_convert_V_to_5);
	tcase_add_test(tc_core, test_convert_X_to_10);

	suite_add_tcase(s, tc_core);

	return s;
}
