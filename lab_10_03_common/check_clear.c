#include <check.h>
#include <stdlib.h>
#include "associative_array.h"

START_TEST(assoc_array_clear_full)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int return_code = assoc_array_clear(arr);
    int *num;
    int find_return_code = assoc_array_find(arr, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(find_return_code, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_clear_empty)
{
    assoc_array_t arr = assoc_array_create();

    int return_code = assoc_array_clear(arr);
    int *num;
    int find_return_code = assoc_array_find(arr, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(find_return_code, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_clear_null)
{
    int return_code = assoc_array_clear(NULL);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

Suite *assoc_array_clear_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("assoc_array_clear");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, assoc_array_clear_full);
    tcase_add_test(tc_core, assoc_array_clear_empty);
    tcase_add_test(tc_core, assoc_array_clear_null);
    suite_add_tcase(s, tc_core);
    return s;
}
