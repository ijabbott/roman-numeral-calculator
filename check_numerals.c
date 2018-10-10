#include <stdlib.h>
#include <check.h>

START_TEST(test_add_I_I)
{
	char *sum = malloc(strlen("I") + strlen("I") + 1);
	add_numerals("I", "I", sum);
	ck_assert_str_eq("II", sum);
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

