#include <check.h>
#include <stdlib.h>
#include "associative_array.h"

START_TEST(assoc_array_find_exists)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int *num;
    int return_code = assoc_array_find(arr, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 1);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_find_not_exists)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int *num;
    int return_code = assoc_array_find(arr, "b", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_find_null)
{
    int *num;
    int return_code = assoc_array_find(NULL, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(assoc_array_find_empty_key)
{
    assoc_array_t arr = assoc_array_create();

    int *num;
    int return_code = assoc_array_find(arr, "", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

Suite *assoc_array_find_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("assoc_array_find");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, assoc_array_find_exists);
    tcase_add_test(tc_core, assoc_array_find_not_exists);
    tcase_add_test(tc_core, assoc_array_find_null);
    tcase_add_test(tc_core, assoc_array_find_empty_key);
    suite_add_tcase(s, tc_core);
    return s;
}
