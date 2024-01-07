#include <check.h>
#include "array.h"

START_TEST(simple_test)
{
    int input[] = {5, 2, 7, 4, 8, 7, 6, 3, 8, 8, 86, 1, 7, 3, 6, 3, 2, -2, 0};
    int output[] = {86, 6, 3, 2};
    
    int *pb_dst, *pe_dst;
    int exit_code = key(input, input + 19, &pb_dst, &pe_dst);
    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    for (int i = 0; i < 4; i++)
        ck_assert_int_eq(pb_dst[i], output[i]);
    free(pb_dst);
}
END_TEST

START_TEST(nothing_to_filter)
{
    int input[] = {10, 3, 1};
    int output[] = {10, 3};
    
    int *pb_dst, *pe_dst;
    int exit_code = key(input, input + 3, &pb_dst, &pe_dst);
    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    for (int i = 0; i < 2; i++)
        ck_assert_int_eq(pb_dst[i], output[i]);
    free(pb_dst);
}
END_TEST

START_TEST(everything_to_filter)
{
    int input[] = {1, 2, 3};
    
    int *pb_dst, *pe_dst;
    int exit_code = key(input, input + 3, &pb_dst, &pe_dst);
    ck_assert_int_eq(exit_code, EMPTY_DST_ARRAY_ERROR);
}
END_TEST

START_TEST(null_pointers)
{
    int *pb_dst, *pe_dst;
    int exit_code = key(NULL, NULL, &pb_dst, &pe_dst);
    ck_assert_int_eq(exit_code, NULL_POINTERS_ERROR);
}
END_TEST

START_TEST(invalid_pointers)
{
	int input[] = {5, 2, 7, 4, 8, 7, 6, 3, 8, 8, 86, 1, 7, 3, 6, 3, 2, -2, 0};
	
    int *pb_dst, *pe_dst;
    int exit_code = key(input + 19, input, &pb_dst, &pe_dst);
    ck_assert_int_eq(exit_code, INVALID_POINTERS_ERROR);
}
END_TEST

Suite *test_key_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("test_key");
    tc_core = tcase_create("core");
    
    tcase_add_test(tc_core, simple_test);
    tcase_add_test(tc_core, nothing_to_filter);
    tcase_add_test(tc_core, everything_to_filter);
    tcase_add_test(tc_core, null_pointers);
    tcase_add_test(tc_core, invalid_pointers);
    
    suite_add_tcase(s, tc_core);
    return s;
}

