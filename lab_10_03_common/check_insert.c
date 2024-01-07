#include <check.h>
#include <stdlib.h>
#include "associative_array.h"

START_TEST(assoc_array_insert_empty)
{
    assoc_array_t arr = assoc_array_create();

    int return_code = assoc_array_insert(arr, "a", 1);
    int *num;
    assoc_array_find(arr, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 1);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_insert_new)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int return_code = assoc_array_insert(arr, "b", 5);
    int *num;
    assoc_array_find(arr, "b", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 5);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_insert_exists)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);

    int return_code = assoc_array_insert(arr, "a", 5);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_KEY_EXISTS);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_insert_null)
{
    int return_code = assoc_array_insert(NULL, "a", 5);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(assoc_array_insert_empty_key)
{
    assoc_array_t arr = assoc_array_create();

    int return_code = assoc_array_insert(arr, "", 5);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);

    assoc_array_destroy(&arr);
}
END_TEST

Suite *assoc_array_insert_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("assoc_array_insert");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, assoc_array_insert_empty);
    tcase_add_test(tc_core, assoc_array_insert_new);
    tcase_add_test(tc_core, assoc_array_insert_exists);
    tcase_add_test(tc_core, assoc_array_insert_null);
    tcase_add_test(tc_core, assoc_array_insert_empty_key);
    suite_add_tcase(s, tc_core);
    return s;
}
