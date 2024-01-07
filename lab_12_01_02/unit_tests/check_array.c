#include <check.h>
#include "array.h"



START_TEST(filter_array_nothing)
{
    int src_len = 6;
    int src[] = {1, 4, 9, 16, 25, 36};
    int correct_dst_len = 6;
    int correct_dst[] = {1, 4, 9, 16, 25, 36};
    
    int dst[correct_dst_len];

    int dst_len = filter_array(dst, correct_dst_len, src, src_len);

    ck_assert_int_eq(dst_len, correct_dst_len);
    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], correct_dst[i]);
}
END_TEST

START_TEST(filter_array_some)
{
    int src_len = 6;
    int src[] = {1, 5, 9, 7, 25, 6};
    int correct_dst_len = 3;
    int correct_dst[] = {1, 9, 25};
    
    int dst[correct_dst_len];

    int dst_len = filter_array(dst, correct_dst_len, src, src_len);

    ck_assert_int_eq(dst_len, correct_dst_len);
    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], correct_dst[i]);
}
END_TEST

START_TEST(filter_array_everything)
{
    int src_len = 3;
    int src[] = {3, 35, -999};
    int correct_dst_len = 0;
    int correct_dst[] = {};
    
    int dst[correct_dst_len];

    int dst_len = filter_array(dst, correct_dst_len, src, src_len);

    ck_assert_int_eq(dst_len, correct_dst_len);
    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], correct_dst[i]);
}
END_TEST

START_TEST(filter_array_no_buffer)
{
    int src_len = 6;
    int src[] = {1, 4, 9, 16, 25, 36};
    int correct_dst_len = 6;

    int dst_len = filter_array(NULL, 1, src, src_len);

    ck_assert_int_eq(dst_len, correct_dst_len);
}
END_TEST

Suite *filter_array_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("filter_array");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, filter_array_nothing);
    tcase_add_test(tc_core, filter_array_some);
    tcase_add_test(tc_core, filter_array_everything);
    tcase_add_test(tc_core, filter_array_no_buffer);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(shift_array_zero)
{
    int k = 0;
    int len = 6;
    int src[] = {1, 4, 9, 16, 25, 36};
    int correct[] = {1, 4, 9, 16, 25, 36};

    shift_array(src, len, k);

    for (int i = 0; i < len; i++)
        ck_assert_int_eq(src[i], correct[i]);
}
END_TEST

START_TEST(shift_array_gt_zero_lt_len)
{
    int k = 4;
    int len = 6;
    int src[] = {1, 4, 9, 16, 25, 36};
    int correct[] = {25, 36, 1, 4, 9, 16};

    shift_array(src, len, k);

    for (int i = 0; i < len; i++)
        ck_assert_int_eq(src[i], correct[i]);
}
END_TEST

START_TEST(shift_array_len)
{
    int k = 6;
    int len = 6;
    int src[] = {1, 4, 9, 16, 25, 36};
    int correct[] = {1, 4, 9, 16, 25, 36};

    shift_array(src, len, k);

    for (int i = 0; i < len; i++)
        ck_assert_int_eq(src[i], correct[i]);
}
END_TEST

START_TEST(shift_array_gt_len)
{
    int k = 10;
    int len = 6;
    int src[] = {1, 4, 9, 16, 25, 36};
    int correct[] = {25, 36, 1, 4, 9, 16};

    shift_array(src, len, k);

    for (int i = 0; i < len; i++)
        ck_assert_int_eq(src[i], correct[i]);
}
END_TEST

Suite *shift_array_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("shift_array");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, shift_array_zero);
    tcase_add_test(tc_core, shift_array_gt_zero_lt_len);
    tcase_add_test(tc_core, shift_array_len);
    tcase_add_test(tc_core, shift_array_gt_len);
    suite_add_tcase(s, tc_core);
    return s;
}
