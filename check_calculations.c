#include <stdlib.h>
#include <check.h>
#include "numeral_calculator.h"

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

Suite * calculation_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Calculation Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_add_I_I);
	tcase_add_test(tc_core, test_add_I_II);
	tcase_add_test(tc_core, test_add_II_II);
	tcase_add_test(tc_core, test_add_II_III);
	tcase_add_test(tc_core, test_add_I_IV);
	suite_add_tcase(s, tc_core);

	return s;
}

