#include <check.h>
#include <stdlib.h>

Suite *push_back_suite(void);
Suite *pop_back_suite(void);
Suite *pop_front_suite(void);
Suite *remove_duplicates_suite(void);
Suite *sort_suite(void);

typedef Suite *(*suite_array_t)(void);

int main(void)
{
    int n_failed = 0;
    SRunner *sr = srunner_create(NULL);
    suite_array_t suite_arr[] = {push_back_suite, pop_back_suite, pop_front_suite, remove_duplicates_suite, sort_suite};
    int n_suites = 5;
    for (int i = 0; i < n_suites; i++)
        srunner_add_suite(sr, suite_arr[i]());
    srunner_run_all(sr, CK_VERBOSE);
    n_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return n_failed;
}
