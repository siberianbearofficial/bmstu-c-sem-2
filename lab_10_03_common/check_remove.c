#include <check.h>
#include <stdlib.h>
#include "associative_array.h"

START_TEST(assoc_array_remove_exists)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int return_code = assoc_array_remove(arr, "a");
    int *num;
    int find_return_code = assoc_array_find(arr, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(find_return_code, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_remove_not_exists)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int return_code = assoc_array_remove(arr, "b");
    int *num;
    int find_return_code = assoc_array_find(arr, "b", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_NOT_FOUND);
    ck_assert_int_eq(find_return_code, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_remove_null)
{
    int return_code = assoc_array_remove(NULL, "a");

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(assoc_array_remove_empty_key)
{
    assoc_array_t arr = assoc_array_create();

    int return_code = assoc_array_remove(arr, "");

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

Suite *assoc_array_remove_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("assoc_array_remove");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, assoc_array_remove_exists);
    tcase_add_test(tc_core, assoc_array_remove_not_exists);
    tcase_add_test(tc_core, assoc_array_remove_null);
    tcase_add_test(tc_core, assoc_array_remove_empty_key);
    suite_add_tcase(s, tc_core);
    return s;
}
