#include <check.h>
#include <stdlib.h>

Suite *assoc_array_insert_suite(void);
Suite *assoc_array_find_suite(void);
Suite *assoc_array_remove_suite(void);
Suite *assoc_array_clear_suite(void);
Suite *assoc_array_each_suite(void);
Suite *assoc_array_min_suite(void);
Suite *assoc_array_max_suite(void);

typedef Suite *(*suite_array_t)(void);

int main(void)
{
    int n_failed = 0;
    SRunner *sr = srunner_create(NULL);
    suite_array_t suite_arr[] = {assoc_array_insert_suite, assoc_array_find_suite, assoc_array_remove_suite,
                                 assoc_array_clear_suite, assoc_array_each_suite, assoc_array_min_suite,
                                 assoc_array_max_suite};
    int n_suites = 7;
    for (int i = 0; i < n_suites; i++)
        srunner_add_suite(sr, suite_arr[i]());
    srunner_run_all(sr, CK_VERBOSE);
    n_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return n_failed;
}
