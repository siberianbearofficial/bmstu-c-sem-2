#include <check.h>
#include <stdlib.h>

Suite *sqr_number_suite(void);
Suite *multiply_number_suite(void);
Suite *div_number_suite(void);
Suite *create_number_suite(void);

typedef Suite *(*suite_array_t)(void);

int main(void)
{
    int n_failed = 0;
    SRunner *sr = srunner_create(NULL);
    suite_array_t suite_arr[] = {sqr_number_suite, multiply_number_suite, div_number_suite, create_number_suite};
    int n_suites = 4;
    for (int i = 0; i < n_suites; i++)
        srunner_add_suite(sr, suite_arr[i]());
    srunner_run_all(sr, CK_VERBOSE);
    n_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return n_failed;
}
