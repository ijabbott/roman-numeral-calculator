#include <stdlib.h>
#include <check.h>
#include "check_subtractions.h"
#include "numeral_calculator.h"

/* Cases Covered
	
*/

START_TEST(test_subtract_II_I)
{
	char *difference = malloc(strlen("II") + strlen("I") + 1);
	subtract_numerals("II", "I", difference);
	ck_assert_str_eq("I", difference);
	free(difference);
}
END_TEST



Suite * subtractions_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Subtraction Tests");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_subtract_II_I);

	suite_add_tcase(s, tc_core);

	return s;
}

