#include <check.h>
#include <stdlib.h>

Suite *squarify_suite(void);
Suite *adjust_suite(void);
Suite *multiply_suite(void);
Suite *power_suite(void);
Suite *copy_suite(void);

typedef Suite *(*suite_array_t)(void);

int main(void)
{
    int n_failed = 0;
    SRunner *sr = srunner_create(NULL);
    suite_array_t suite_arr[] = {squarify_suite, adjust_suite, multiply_suite, power_suite, copy_suite};
    int n_suites = 5;
    for (int i = 0; i < n_suites; i++)
        srunner_add_suite(sr, suite_arr[i]());
    srunner_run_all(sr, CK_VERBOSE);
    n_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return n_failed;
}
