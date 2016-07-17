#include <stdlib.h>
#include <stdio.h>
#include <check.h>

#include "../src/romanNumLib.h"

static char buf[80];

/****************************************************************************************/
START_TEST (test_simple_addition_ipi)
{
    romanNumbersAdd("i", "i", buf);
    ck_assert_str_eq(buf, "ii");
}
END_TEST

START_TEST (test_simple_addition_iipiii)
{
    romanNumbersAdd("ii", "iii", buf);
    ck_assert_str_eq(buf, "v");
}
END_TEST

START_TEST (test_simple_addition_iiipiii)
{
    romanNumbersAdd("iii", "iii", buf);
    ck_assert_str_eq(buf, "vi");
}
END_TEST

START_TEST (test_simple_addition_iipii)
{
    romanNumbersAdd("ii", "ii", buf);
    ck_assert_str_eq(buf, "iv");
}
END_TEST

START_TEST (test_simple_addition_vpiii)
{
    romanNumbersAdd("v", "iii", buf);
    ck_assert_str_eq(buf, "viii");
}
END_TEST

/****************************************************************************************/
Suite * RomanNumberalLib_suite(void)
{
   Suite *s;
   TCase *tc_core;

   s = suite_create("RomanNumberalLibTest_suite");

   /* Core test case */
   tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_simple_addition_ipi);
    tcase_add_test(tc_core, test_simple_addition_iipiii);
    tcase_add_test(tc_core, test_simple_addition_iiipiii);
    tcase_add_test(tc_core, test_simple_addition_iipii);
    tcase_add_test(tc_core, test_simple_addition_vpiii);

   suite_add_tcase(s, tc_core);

   return s;
}


int main(void)
{
   int number_failed;
   Suite *s;
   SRunner *sr;

   s = RomanNumberalLib_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
