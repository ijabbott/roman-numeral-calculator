#include <stdlib.h>
#include <check.h>
#include "check_additions.h"
#include "check_subtractions.h"
#include "check_decimal_to_roman.h"
#include "check_roman_to_decimal.h"

int main(void)
{
	int number_failed;
	Suite *addition_tests;
	Suite *subtraction_tests;
	Suite *decimal_to_roman_tests;
	Suite *roman_to_decimal_tests;
	SRunner *sr;

	addition_tests = additions_suite();
	subtraction_tests = subtractions_suite();
	decimal_to_roman_tests = decimal_to_roman_suite();
	roman_to_decimal_tests = roman_to_decimal_suite();

	sr = srunner_create(addition_tests);
	srunner_add_suite(sr, decimal_to_roman_tests);
	srunner_add_suite(sr, roman_to_decimal_tests);
	srunner_add_suite(sr, subtraction_tests);
	

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
