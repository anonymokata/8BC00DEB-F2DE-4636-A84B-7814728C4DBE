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

START_TEST (test_simple_addition_iiipv)
{
    romanNumbersAdd("iii", "v", buf);
    ck_assert_str_eq(buf, "viii");
}
END_TEST

START_TEST (test_simple_addition_ivpi)
{
    romanNumbersAdd("iv", "i", buf);
    ck_assert_str_eq(buf, "v");
}
END_TEST

START_TEST (test_simple_addition_ipiv)
{
    romanNumbersAdd("i", "iv", buf);
    ck_assert_str_eq(buf, "v");
}
END_TEST

START_TEST (test_simple_addition_vpiv)
{
    romanNumbersAdd("v", "iv", buf);
    ck_assert_str_eq(buf, "ix");
}
END_TEST

START_TEST (test_simple_addition_vpv)
{
    romanNumbersAdd("v", "v", buf);
    ck_assert_str_eq(buf, "x");
}
END_TEST

START_TEST (test_simple_addition_ixpv)
{
    romanNumbersAdd("ix", "v", buf);
    ck_assert_str_eq(buf, "xiv");
}
END_TEST

START_TEST (test_simple_addition_ixpix)
{
    romanNumbersAdd("ix", "ix", buf);
    ck_assert_str_eq(buf, "xviii");
}
END_TEST

START_TEST (test_simple_addition_ipix)
{
    romanNumbersAdd("i", "ix", buf);
    ck_assert_str_eq(buf, "x");
}
END_TEST

START_TEST (test_multidigit_addition_xpx)
{
    romanNumbersAdd("x", "xi", buf);
    ck_assert_str_eq(buf, "xxi");
}
END_TEST

START_TEST (test_simple_addition_xxpxxx)
{
    romanNumbersAdd("xx", "xxx", buf);
    ck_assert_str_eq(buf, "l");
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
    tcase_add_test(tc_core, test_simple_addition_iiipv);
    tcase_add_test(tc_core, test_simple_addition_ivpi);
    tcase_add_test(tc_core, test_simple_addition_ipiv);
    tcase_add_test(tc_core, test_simple_addition_vpiv);
    tcase_add_test(tc_core, test_simple_addition_vpv);
    tcase_add_test(tc_core, test_simple_addition_ixpv);
    tcase_add_test(tc_core, test_simple_addition_ixpix);
    tcase_add_test(tc_core, test_simple_addition_ipix);

    tcase_add_test(tc_core, test_multidigit_addition_xpx);
    tcase_add_test(tc_core, test_simple_addition_xxpxxx);

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
