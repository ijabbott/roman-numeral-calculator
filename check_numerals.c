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

Suite * numeral_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Numeral");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_add_I_I);
	tcase_add_test(tc_core, test_add_I_II);
	tcase_add_test(tc_core, test_add_II_II);
	tcase_add_test(tc_core, test_add_II_III);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = numeral_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

