#include <stdlib.h>
#include <check.h>
#include "check_subtractions.h"
#include "numeral_calculator.h"

#define MAX_LENGTH 12 // MMMCCCXXXIII

/* Cases Covered
	- Subtracting numerals that contain all of the same character
	- Subtracting numerals that contain different characters
	- Subtracting from a numeral that will cause it to expand into smaller numerals
*/

START_TEST(test_subtract_II_I)
{
	char *difference = malloc(MAX_LENGTH);
	subtract_numerals("II", "I", difference);
	ck_assert_str_eq("I", difference);
	free(difference);
}
END_TEST

START_TEST(test_subtract_XV_VIII)
{
	char *difference = malloc(MAX_LENGTH);
	subtract_numerals("XV", "VIII", difference);
	ck_assert_str_eq("VII", difference);
	free(difference);
}
END_TEST

START_TEST(test_subtract_XL_I)
{
	char *difference = malloc(MAX_LENGTH);
	subtract_numerals("XL", "I", difference);
	ck_assert_str_eq("XXXIX", difference);
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
	tcase_add_test(tc_core, test_subtract_XV_VIII);
	tcase_add_test(tc_core, test_subtract_XL_I);

	suite_add_tcase(s, tc_core);

	return s;
}

