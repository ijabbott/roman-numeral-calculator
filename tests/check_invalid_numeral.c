#include <stdlib.h>
#include <check.h>
#include "check_invalid_numeral.h"
#include "numeral_converter.h"

/* Cases Covered
	- Invalid numerals
*/

START_TEST(test_invalid_numeral_A)
{
	int decimal = 0;
	
	numeral_to_decimal("A", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_IIII)
{
	int decimal = 0;
	
	numeral_to_decimal("IIII", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_XXXX)
{
	int decimal = 0;
	
	numeral_to_decimal("XXXX", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_CCCC)
{
	int decimal = 0;
	
	numeral_to_decimal("CCCC", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_VV)
{
	int decimal = 0;
	
	numeral_to_decimal("VV", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_LL)
{
	int decimal = 0;
	
	numeral_to_decimal("LL", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_DD)
{
	int decimal = 0;
	
	numeral_to_decimal("DD", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

START_TEST(test_invalid_numeral_format)
{
	int decimal = 0;
	
	numeral_to_decimal("IIV", &decimal);
	ck_assert_int_eq(0, decimal);
}
END_TEST

Suite * invalid_numeral_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Invalid Numeral Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_invalid_numeral_A);
	tcase_add_test(tc_core, test_invalid_numeral_IIII);
	tcase_add_test(tc_core, test_invalid_numeral_XXXX);
	tcase_add_test(tc_core, test_invalid_numeral_CCCC);
	tcase_add_test(tc_core, test_invalid_numeral_VV);
	tcase_add_test(tc_core, test_invalid_numeral_LL);
	tcase_add_test(tc_core, test_invalid_numeral_DD);
	tcase_add_test(tc_core, test_invalid_numeral_format);

	suite_add_tcase(s, tc_core);

	return s;
}
