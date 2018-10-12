#include <stdlib.h>
#include <check.h>
#include "check_numeral_to_decimal.h"
#include "numeral_converter.h"

/* Cases Covered
	- Each individual numeral
	- Repeated numerals
	- Lesser numeral before larger numeral
	- Lesser numeral after larger numeral
	- Lesser numeral between two larger numerals
	- Maximum numeral 
	- Invalid numerals
*/

START_TEST(test_convert_I_to_1)
{
	int decimal = 0;
	
	numeral_to_decimal("I", &decimal);
	ck_assert_int_eq(1, decimal);
}
END_TEST

START_TEST(test_convert_II_to_2)
{
	int decimal = 0;
	
	numeral_to_decimal("II", &decimal);
	ck_assert_int_eq(2, decimal);
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

START_TEST(test_convert_VI_to_6)
{
	int decimal = 0;
	
	numeral_to_decimal("VI", &decimal);
	ck_assert_int_eq(6, decimal);
}
END_TEST

START_TEST(test_convert_IX_to_9)
{
	int decimal = 0;
	
	numeral_to_decimal("IX", &decimal);
	ck_assert_int_eq(9, decimal);
}
END_TEST

START_TEST(test_convert_X_to_10)
{
	int decimal = 0;
	
	numeral_to_decimal("X", &decimal);
	ck_assert_int_eq(10, decimal);
}
END_TEST

START_TEST(test_convert_XI_to_11)
{
	int decimal = 0;
	
	numeral_to_decimal("XI", &decimal);
	ck_assert_int_eq(11, decimal);
}
END_TEST

START_TEST(test_convert_XIV_to_14)
{
	int decimal = 0;
	
	numeral_to_decimal("XIV", &decimal);
	ck_assert_int_eq(14, decimal);
}
END_TEST

START_TEST(test_convert_XV_to_15)
{
	int decimal = 0;
	
	numeral_to_decimal("XV", &decimal);
	ck_assert_int_eq(15, decimal);
}
END_TEST

START_TEST(test_convert_XVI_to_16)
{
	int decimal = 0;
	
	numeral_to_decimal("XVI", &decimal);
	ck_assert_int_eq(16, decimal);
}
END_TEST

START_TEST(test_convert_XL_to_40)
{
	int decimal = 0;
	
	numeral_to_decimal("XL", &decimal);
	ck_assert_int_eq(40, decimal);
}
END_TEST

START_TEST(test_convert_L_to_50)
{
	int decimal = 0;
	
	numeral_to_decimal("L", &decimal);
	ck_assert_int_eq(50, decimal);
}
END_TEST

START_TEST(test_convert_C_to_100)
{
	int decimal = 0;
	
	numeral_to_decimal("C", &decimal);
	ck_assert_int_eq(100, decimal);
}
END_TEST

START_TEST(test_convert_D_to_500)
{
	int decimal = 0;
	
	numeral_to_decimal("D", &decimal);
	ck_assert_int_eq(500, decimal);
}
END_TEST

START_TEST(test_convert_M_to_1000)
{
	int decimal = 0;
	
	numeral_to_decimal("M", &decimal);
	ck_assert_int_eq(1000, decimal);
}
END_TEST

START_TEST(test_convert_MMMCMXCIX_to_3999)
{
	int decimal = 0;
	
	numeral_to_decimal("MMMCMXCIX", &decimal);
	ck_assert_int_eq(3999, decimal);
}
END_TEST

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

Suite * numeral_to_decimal_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Numeral to Decimal Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_convert_I_to_1);
	tcase_add_test(tc_core, test_convert_II_to_2);
	tcase_add_test(tc_core, test_convert_IV_to_4);
	tcase_add_test(tc_core, test_convert_V_to_5);
	tcase_add_test(tc_core, test_convert_VI_to_6);
	tcase_add_test(tc_core, test_convert_IX_to_9);
	tcase_add_test(tc_core, test_convert_X_to_10);
	tcase_add_test(tc_core, test_convert_XI_to_11);
	tcase_add_test(tc_core, test_convert_XIV_to_14);
	tcase_add_test(tc_core, test_convert_XV_to_15);
	tcase_add_test(tc_core, test_convert_XVI_to_16);
	tcase_add_test(tc_core, test_convert_XL_to_40);
	tcase_add_test(tc_core, test_convert_L_to_50);
	tcase_add_test(tc_core, test_convert_C_to_100);
	tcase_add_test(tc_core, test_convert_D_to_500);
	tcase_add_test(tc_core, test_convert_M_to_1000);
	tcase_add_test(tc_core, test_convert_MMMCMXCIX_to_3999);
	tcase_add_test(tc_core, test_invalid_numeral_A);
	tcase_add_test(tc_core, test_invalid_numeral_IIII);
	tcase_add_test(tc_core, test_invalid_numeral_XXXX);
	tcase_add_test(tc_core, test_invalid_numeral_CCCC);
	tcase_add_test(tc_core, test_invalid_numeral_VV);
	tcase_add_test(tc_core, test_invalid_numeral_LL);
	tcase_add_test(tc_core, test_invalid_numeral_DD);

	suite_add_tcase(s, tc_core);

	return s;
}
