#include <stdlib.h>
#include <check.h>
#include "check_additions.h"
#include "numeral_calculator.h"

/* Cases Covered
	- Adding identical numerals
	- Adding numerals contain all of the same character
	- Adding same character numerals that will include a different numeral in the result
	- Adding numerals that will simplify to a single larger numeral
	- Adding numerals that will simply only part of the larger numeral
	- Adding numerals where the result is greater than MMMCMXCIX
	- Adding an invalid numeral
	- Adding any numeral greater than MMMCMXCIX
*/

START_TEST(test_add_I_I)
{
	char *sum = malloc(strlen("I") + strlen("I") + 1);
	add_numerals("I", "I", sum);
	ck_assert_str_eq("II", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_I_II)
{
	char *sum = malloc(strlen("I") + strlen("II") + 1);
	add_numerals("I", "II", sum);
	ck_assert_str_eq("III", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_II_II)
{
	char *sum = malloc(strlen("II") + strlen("II") + 1);
	add_numerals("II", "II", sum);
	ck_assert_str_eq("IV", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_II_III)
{
	char *sum = malloc(strlen("II") + strlen("III") + 1);
	add_numerals("II", "III", sum);
	ck_assert_str_eq("V", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_I_IV)
{
	char *sum = malloc(strlen("I") + strlen("IV") + 1);
	add_numerals("I", "IV", sum);
	ck_assert_str_eq("V", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_I_V)
{
	char *sum = malloc(strlen("I") + strlen("V") + 1);
	add_numerals("I", "V", sum);
	ck_assert_str_eq("VI", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_I_VI)
{
	char *sum = malloc(strlen("I") + strlen("VI") + 1);
	add_numerals("I", "VI", sum);
	ck_assert_str_eq("VII", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_V_VI)
{
	char *sum = malloc(strlen("V") + strlen("VI") + 1);
	add_numerals("V", "VI", sum);
	ck_assert_str_eq("XI", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_X_MMMCCCXXXIII)
{
	char *sum = malloc(strlen("X") + strlen("MMMCCCXXXIII") + 1);
	add_numerals("X", "MMMCCCXXXIII", sum);
	ck_assert_str_eq("MMMCCCXLIII", sum);
	free(sum);
}
END_TEST

START_TEST(test_add_I_MMMCMXCIX)
{
	char *sum = malloc(strlen("I") + strlen("MMMCMXCIX") + 1);
	int result;
	result = add_numerals("I", "MMMCMXCIX", sum);
	ck_assert_str_eq("", sum);
	ck_assert_int_eq(1, result);
	free(sum);
}
END_TEST

START_TEST(test_add_I_A)
{
	char *sum = malloc(strlen("I") + strlen("A") + 1);
	int result;
	result = add_numerals("I", "A", sum);
	ck_assert_str_eq("", sum);
	ck_assert_int_eq(1, result);
	free(sum);
}
END_TEST

START_TEST(test_add_I_MMMM)
{
	char *sum = malloc(strlen("I") + strlen("MMMM") + 1);
	int result;
	result = add_numerals("I", "MMMM", sum);
	ck_assert_str_eq("", sum);
	ck_assert_int_eq(1, result);
	free(sum);
}
END_TEST

START_TEST(test_add_I_empty)
{
	char *sum = malloc(strlen("I") + strlen("") + 1);
	int result;
	result = add_numerals("I", "", sum);
	ck_assert_str_eq("", sum);
	ck_assert_int_eq(1, result);
	free(sum);
}
END_TEST

START_TEST(test_add_I_NULL)
{
	char *sum = malloc(strlen("I") + 1);
	int result;
	result = add_numerals("I", NULL, sum);
	ck_assert_str_eq("", sum);
	ck_assert_int_eq(1, result);
	free(sum);
}
END_TEST

Suite * additions_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Addition Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_add_I_I);
	tcase_add_test(tc_core, test_add_I_II);
	tcase_add_test(tc_core, test_add_II_II);
	tcase_add_test(tc_core, test_add_II_III);
	tcase_add_test(tc_core, test_add_I_IV);
	tcase_add_test(tc_core, test_add_I_V);
	tcase_add_test(tc_core, test_add_I_VI);
	tcase_add_test(tc_core, test_add_V_VI);
	tcase_add_test(tc_core, test_add_X_MMMCCCXXXIII);
	tcase_add_test(tc_core, test_add_I_MMMCMXCIX);
	tcase_add_test(tc_core, test_add_I_A);
	tcase_add_test(tc_core, test_add_I_MMMM);
	tcase_add_test(tc_core, test_add_I_empty);
	tcase_add_test(tc_core, test_add_I_NULL);
	suite_add_tcase(s, tc_core);

	return s;
}

