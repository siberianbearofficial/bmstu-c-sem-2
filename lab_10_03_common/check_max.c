#include <check.h>
#include <stdlib.h>
#include "associative_array.h"

START_TEST(assoc_array_max_full)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "f", 10);
    assoc_array_insert(arr, "abc", 5);

    int *num;
    int return_code = assoc_array_max(arr, &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 10);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_max_empty)
{
    assoc_array_t arr = assoc_array_create();

    int *num;
    int return_code = assoc_array_max(arr, &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_max_null)
{
    int *num;
    int return_code = assoc_array_max(NULL, &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(assoc_array_max_num_null)
{
    assoc_array_t arr = assoc_array_create();

    int return_code = assoc_array_max(arr, NULL);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

Suite *assoc_array_max_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("assoc_array_max");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, assoc_array_max_full);
    tcase_add_test(tc_core, assoc_array_max_empty);
    tcase_add_test(tc_core, assoc_array_max_null);
    tcase_add_test(tc_core, assoc_array_max_num_null);
    suite_add_tcase(s, tc_core);
    return s;
}
