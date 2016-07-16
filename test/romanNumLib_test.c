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

/****************************************************************************************/
Suite * RomanNumberalLib_suite(void)
{
   Suite *s;
   TCase *tc_core;

   s = suite_create("RomanNumberalLibTest_suite");

   /* Core test case */
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, test_simple_addition_ipi);

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
