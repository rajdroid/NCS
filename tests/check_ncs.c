#include <check.h>
#include "../library.h"

/*
 * Purpose: To test NCS string length
 */
START_TEST(ncs_length_test1)
{
    char *str = ncs_new ("hello");
    size_t len = ncs_len (str);
    ck_assert_int_eq (len, 5);
}
END_TEST

/*
 * Purpose: To test null NCS string length
 */
START_TEST(ncs_length_test2)
{
    char *str = ncs_new ("");
    size_t len = ncs_len (str);
    ck_assert_int_eq (len, 0);
}
END_TEST


Suite *ncs_suite (void)
{
    Suite *s = suite_create("NCS");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, ncs_length_test1);
    tcase_add_test(tc_core, ncs_length_test2);
    suite_add_tcase(s, tc_core);

    return s;
}


int main ()
{
    int tcase_failed = 0;
    Suite *s;
    SRunner *sr;

    s = ncs_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    tcase_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (tcase_failed == 0) ? 0 : 1;
}
