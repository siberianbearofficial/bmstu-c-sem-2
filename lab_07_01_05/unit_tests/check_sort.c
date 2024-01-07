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

START_TEST(simple_test)
{
    int input[] = {5, 2, 7, 4, 8, 7, 6, 3, 8, 8, 86, 1, 7, 3, 6, 3, 2, -2, 0};
    int output[] = {-2, 0, 1, 2, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 8, 86};
    
    mysort(input, 19, sizeof(int), intcmp);
    
    for (int i = 0; i < 19; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(everything_is_sorted)
{
    int input[] = {50, 50, 51, 55, 57, 57, 58, 59, 66, 68, 69, 70, 83, 85, 86, 92, 92, 94, 99, 100};
    int output[] = {50, 50, 51, 55, 57, 57, 58, 59, 66, 68, 69, 70, 83, 85, 86, 92, 92, 94, 99, 100};
    
    mysort(input, 20, sizeof(int), intcmp);
    
    for (int i = 0; i < 20; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(everything_is_sorted_desc)
{
    int input[] = {100, 99, 94, 92, 92, 86, 85, 83, 70, 69, 68, 66, 59, 58, 57, 57, 55, 51, 50, 50};
    int output[] = {50, 50, 51, 55, 57, 57, 58, 59, 66, 68, 69, 70, 83, 85, 86, 92, 92, 94, 99, 100};
    
    mysort(input, 20, sizeof(int), intcmp);
    
    for (int i = 0; i < 20; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(identic_elements)
{
    int input[] = {3, 3, 3, 3, 3};
    int output[] = {3, 3, 3, 3, 3};
    
    mysort(input, 5, sizeof(int), intcmp);
    
    for (int i = 0; i < 5; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(one_element)
{
    int input[] = {-3};
    int output[] = {-3};
    
    mysort(input, 1, sizeof(int), intcmp);
    
    for (int i = 0; i < 1; i++)
        ck_assert_int_eq(input[i], output[i]);
}
END_TEST

START_TEST(simple_test_char)
{
    char input[] = {'5', '2', '7', '4', '8'};
    char output[] = {'2', '4', '5', '7', '8'};
    
    mysort(input, 5, sizeof(char), charcmp);
    
    for (int i = 0; i < 5; i++)
        ck_assert_int_eq((int) input[i], (int) output[i]);
}
END_TEST

START_TEST(simple_test_str)
{
    char input[][2] = {"5", "2", "7", "4", "8"};
    char output[][2] = {"2", "4", "5", "7", "8"};
    
    mysort(input, 5, sizeof(*input), mystrcmp);
    
    for (int i = 0; i < 5; i++)
        ck_assert_pstr_eq((const char *) (input + i), (const char *) (output + i));
}
END_TEST

START_TEST(simple_test_double)
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
    
    tcase_add_test(tc_core, simple_test);
    tcase_add_test(tc_core, everything_is_sorted);
    tcase_add_test(tc_core, everything_is_sorted_desc);
    tcase_add_test(tc_core, identic_elements);
    tcase_add_test(tc_core, one_element);
    
    tcase_add_test(tc_core, simple_test_char);
    tcase_add_test(tc_core, simple_test_str);
    tcase_add_test(tc_core, simple_test_double);
    
    suite_add_tcase(s, tc_core);
    return s;
}

