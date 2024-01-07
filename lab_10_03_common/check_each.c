#include <check.h>
#include <stdlib.h>
#include "associative_array.h"

void action(const char *key, int *val, void *param)
{
    (void) key;
    (*val) += *((int *) param);
}

START_TEST(assoc_array_each_full)
{
    assoc_array_t arr = assoc_array_create();
    assoc_array_insert(arr, "a", 1);
    int *param = malloc(sizeof(int));
    *param = 5;

    int return_code = assoc_array_each(arr, action, param);
    int *num;
    assoc_array_find(arr, "a", &num);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 6);

    free(param);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_each_empty)
{
    assoc_array_t arr = assoc_array_create();
    int *param = malloc(sizeof(int));
    *param = 5;

    int return_code = assoc_array_each(arr, action, param);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_OK);

    free(param);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(assoc_array_each_null)
{
    int return_code = assoc_array_each(NULL, action, NULL);

    ck_assert_int_eq(return_code, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

Suite *assoc_array_each_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("assoc_array_each");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, assoc_array_each_full);
    tcase_add_test(tc_core, assoc_array_each_empty);
    tcase_add_test(tc_core, assoc_array_each_null);
    suite_add_tcase(s, tc_core);
    return s;
}
