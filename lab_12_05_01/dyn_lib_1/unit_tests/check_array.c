#include <check.h>
#include "array.h"

int doublecmp(const void *a, const void *b)
{
    if (*((double *)a) > (*(double *)b))
        return 1;
    if (*((double *)a) < (*(double *)b))
        return -1;
    return 0;
}

int mystrcmp(const void *a, const void *b)
{
    return strcmp((const char *) a, (const char *) b);
}

int charcmp(const void *a, const void *b)
{
    if (*((char *)a) > (*(char *)b))
        return 1;
    if (*((char *)a) < (*(char *)b))
        return -1;
    return 0;
}

START_TEST(mysort_simple_test)
{
    int input[] = {5, 2, 7, 4, 8, 7, 6, 3, 8, 8, 86, 1, 7, 3, 6, 3, 2, -2, 0};
    int output[] = {-2, 0, 1, 2, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 8, 86};

    mysort(input, 19, sizeof(int), intcmp);

    for (int i = 0; i < 19; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(mysort_everything_is_sorted)
{
    int input[] = {50, 50, 51, 55, 57, 57, 58, 59, 66, 68, 69, 70, 83, 85, 86, 92, 92, 94, 99, 100};
    int output[] = {50, 50, 51, 55, 57, 57, 58, 59, 66, 68, 69, 70, 83, 85, 86, 92, 92, 94, 99, 100};

    mysort(input, 20, sizeof(int), intcmp);

    for (int i = 0; i < 20; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(mysort_everything_is_sorted_desc)
{
    int input[] = {100, 99, 94, 92, 92, 86, 85, 83, 70, 69, 68, 66, 59, 58, 57, 57, 55, 51, 50, 50};
    int output[] = {50, 50, 51, 55, 57, 57, 58, 59, 66, 68, 69, 70, 83, 85, 86, 92, 92, 94, 99, 100};

    mysort(input, 20, sizeof(int), intcmp);

    for (int i = 0; i < 20; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(mysort_identic_elements)
{
    int input[] = {3, 3, 3, 3, 3};
    int output[] = {3, 3, 3, 3, 3};

    mysort(input, 5, sizeof(int), intcmp);

    for (int i = 0; i < 5; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(mysort_one_element)
{
    int input[] = {-3};
    int output[] = {-3};

    mysort(input, 1, sizeof(int), intcmp);

    for (int i = 0; i < 1; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(mysort_simple_test_char)
{
    char input[] = {'5', '2', '7', '4', '8'};
    char output[] = {'2', '4', '5', '7', '8'};

    mysort(input, 5, sizeof(char), charcmp);

    for (int i = 0; i < 5; i++)
        ck_assert_int_eq((int) input[i], (int) output[i]);
}
END_TEST

START_TEST(mysort_simple_test_str)
{
    char input[][2] = {"5", "2", "7", "4", "8"};
    char output[][2] = {"2", "4", "5", "7", "8"};

    mysort(input, 5, sizeof(*input), mystrcmp);

    for (int i = 0; i < 5; i++)
        ck_assert_pstr_eq((const char *) (input + i), (const char *) (output + i));
}
END_TEST

START_TEST(mysort_simple_test_double)
{
    double input[] = {5.0, 2.0, 7.0, 4.0, 8.0};
    double output[] = {2.0, 4.0, 5.0, 7.0, 8.0};

    mysort(input, 5, sizeof(double), doublecmp);

    for (int i = 0; i < 5; i++)
        ck_assert_double_eq(input[i], output[i]);
}
END_TEST

Suite *test_sort_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("test_sort");
    tc_core = tcase_create("core");

    tcase_add_test(tc_core, mysort_simple_test);
    tcase_add_test(tc_core, mysort_everything_is_sorted);
    tcase_add_test(tc_core, mysort_everything_is_sorted_desc);
    tcase_add_test(tc_core, mysort_identic_elements);
    tcase_add_test(tc_core, mysort_one_element);

    tcase_add_test(tc_core, mysort_simple_test_char);
    tcase_add_test(tc_core, mysort_simple_test_str);
    tcase_add_test(tc_core, mysort_simple_test_double);

    suite_add_tcase(s, tc_core);
    return s;
}

START_TEST(key_simple_test)
{
    int input[] = {5, 2, 7, 4, 8, 7, 6, 3, 8, 8, 86, 1, 7, 3, 6, 3, 2, -2, 0};
    int output[] = {86, 6, 3, 2};

    int count = 4;
    int pb_dst[4];
    int exit_code = key(input, input + 19, pb_dst, &count);
    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    for (int i = 0; i < 4; i++)
        ck_assert_int_eq(pb_dst[i], output[i]);
}
END_TEST

START_TEST(key_nothing_to_filter)
{
    int input[] = {10, 3, 1};
    int output[] = {10, 3};

    int pb_dst[2];
    int count = 2;
    int exit_code = key(input, input + 3, pb_dst, &count);
    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    for (int i = 0; i < 2; i++)
        ck_assert_int_eq(pb_dst[i], output[i]);
}
END_TEST

START_TEST(key_everything_to_filter)
{
    int input[] = {1, 2, 3};

    int count = 3;
    int pb_dst[3];
    int exit_code = key(input, input + 3, pb_dst, &count);
    ck_assert_int_eq(exit_code, EMPTY_DST_ARRAY_ERROR);
}
END_TEST

START_TEST(key_null_pointers)
{
    int count = 5;
    int pb_dst[5];
    int exit_code = key(NULL, NULL, pb_dst, &count);
    ck_assert_int_eq(exit_code, NULL_POINTERS_ERROR);
}
END_TEST

START_TEST(key_no_buffer)
{
    int input[] = {5, 2, 7, 4, 8, 7, 6, 3, 8, 8, 86, 1, 7, 3, 6, 3, 2, -2, 0};
    int output[] = {86, 6, 3, 2};

    int count = 0;
    int exit_code = key(input, input + 19, NULL, &count);
    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    if (count)
    {
        int pb_dst[count];
        key(input, input + 19, pb_dst, &count);
        for (int i = 0; i < count; i++)
            ck_assert_int_eq(pb_dst[i], output[i]);
    }
}
END_TEST

Suite *test_key_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("test_key");
    tc_core = tcase_create("core");

    tcase_add_test(tc_core, key_simple_test);
    tcase_add_test(tc_core, key_nothing_to_filter);
    tcase_add_test(tc_core, key_everything_to_filter);
    tcase_add_test(tc_core, key_null_pointers);
    tcase_add_test(tc_core, key_no_buffer);

    suite_add_tcase(s, tc_core);
    return s;
}
