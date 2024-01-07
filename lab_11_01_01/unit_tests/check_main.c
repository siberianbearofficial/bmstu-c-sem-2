#include <check.h>
#include <stdlib.h>

Suite *all_suite(void);
Suite *d_suite(void);
Suite *i_suite(void);
Suite *o_suite(void);
Suite *x_suite(void);
Suite *lx_suite(void);
Suite *hx_suite(void);
Suite *lo_suite(void);
Suite *ho_suite(void);
Suite *li_suite(void);
Suite *hi_suite(void);
Suite *ld_suite(void);
Suite *hd_suite(void);
Suite *c_suite(void);
Suite *s_suite(void);

typedef Suite *(*suite_array_t)(void);

int main(void)
{
    int n_failed = 0;
    SRunner *sr = srunner_create(NULL);
    suite_array_t suite_arr[] = {all_suite, d_suite, i_suite, o_suite, x_suite, lx_suite, hx_suite, lo_suite, ho_suite, li_suite, hi_suite, ld_suite, hd_suite, c_suite, s_suite};
    int n_suites = 15;
    for (int i = 0; i < n_suites; i++)
        srunner_add_suite(sr, suite_arr[i]());
    srunner_run_all(sr, CK_VERBOSE);
    n_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return n_failed;
}
