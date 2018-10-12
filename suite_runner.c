#include <stdlib.h>
#include <check.h>
#include "check_calculations.h"
#include "check_conversions.h"

int main(void)
{
	int number_failed;
	Suite *calculation_tests;
	Suite *conversion_tests;
	SRunner *sr;

	calculation_tests = calculation_suite();
	conversion_tests = conversion_suite();
	sr = srunner_create(calculation_tests);
	srunner_add_suite(sr, conversion_tests);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
