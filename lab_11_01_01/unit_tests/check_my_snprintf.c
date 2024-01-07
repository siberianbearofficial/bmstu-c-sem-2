#include <check.h>
#include "my_snprintf.h"

#include <stdio.h>
#include <string.h>




START_TEST(all_no_specifiers)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello world");

    int m = my_snprintf(answer, n, "Hello world");

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(all_many_specifiers)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %c%c world", 'a', 'b');

    int m = my_snprintf(answer, n, "Hello %c%c world", 'a', 'b');

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(all_not_space_after_specifier)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %c. world", 'a');

    int m = my_snprintf(answer, n, "Hello %c. world", 'a');

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(all_small_buffer)
{
    int n = 6;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hi %s", "Very long string");

    int m = my_snprintf(answer, n, "Hi %s", "Very long string");

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *all_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("all");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, all_no_specifiers);
    tcase_add_test(tc_core, all_many_specifiers);
    tcase_add_test(tc_core, all_not_space_after_specifier);
    tcase_add_test(tc_core, all_small_buffer);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(d_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %d world", 14);

    int m = my_snprintf(answer, n, "Hello %d world", 14);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(d_negative)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %d world", -14);

    int m = my_snprintf(answer, n, "Hello %d world", -14);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *d_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("d");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, d_simple);
    tcase_add_test(tc_core, d_negative);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(i_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %i world", 14);

    int m = my_snprintf(answer, n, "Hello %i world", 14);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(i_negative)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %i world", -14);

    int m = my_snprintf(answer, n, "Hello %i world", -14);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *i_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("i");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, i_simple);
    tcase_add_test(tc_core, i_negative);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(o_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %o world", 14);

    int m = my_snprintf(answer, n, "Hello %o world", 14);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *o_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("o");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, o_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(x_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %x world", 149);

    int m = my_snprintf(answer, n, "Hello %x world", 149);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *x_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("x");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, x_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(lx_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %lx world", 146545545543424);

    int m = my_snprintf(answer, n, "Hello %lx world", 146545545543424);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *lx_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("lx");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, lx_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(hx_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %hx world", 11);

    int m = my_snprintf(answer, n, "Hello %hx world", 11);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *hx_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("hx");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, hx_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(lo_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %lo world", 145654667652463474);

    int m = my_snprintf(answer, n, "Hello %lo world", 145654667652463474);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *lo_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("lo");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, lo_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(ho_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %ho world", 9);

    int m = my_snprintf(answer, n, "Hello %ho world", 9);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *ho_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("ho");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, ho_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(li_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %li world", 14456475453364);

    int m = my_snprintf(answer, n, "Hello %li world", 14456475453364);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(li_negative)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %li world", -14456475453364);

    int m = my_snprintf(answer, n, "Hello %li world", -14456475453364);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *li_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("li");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, li_simple);
    tcase_add_test(tc_core, li_negative);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(hi_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %hi world", 4);

    int m = my_snprintf(answer, n, "Hello %hi world", 4);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(hi_negative)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %hi world", -4);

    int m = my_snprintf(answer, n, "Hello %hi world", -4);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *hi_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("hi");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, hi_simple);
    tcase_add_test(tc_core, hi_negative);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(ld_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %ld world", 1456475463453644);

    int m = my_snprintf(answer, n, "Hello %ld world", 1456475463453644);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(ld_negative)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %ld world", -1456475463453644);

    int m = my_snprintf(answer, n, "Hello %ld world", -1456475463453644);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *ld_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("ld");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, ld_simple);
    tcase_add_test(tc_core, ld_negative);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(hd_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %hd world", 4);

    int m = my_snprintf(answer, n, "Hello %hd world", 4);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(hd_negative)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %hd world", -1);

    int m = my_snprintf(answer, n, "Hello %hd world", -1);

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *hd_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("hd");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, hd_simple);
    tcase_add_test(tc_core, hd_negative);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(c_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %c world", 'f');

    int m = my_snprintf(answer, n, "Hello %c world", 'f');

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(c_zero)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %c world", '\0');

    int m = my_snprintf(answer, n, "Hello %c world", '\0');

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *c_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("c");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, c_simple);
    tcase_add_test(tc_core, c_zero);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(s_simple)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %s world", "dear");

    int m = my_snprintf(answer, n, "Hello %s world", "dear");

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

START_TEST(s_empty)
{
    int n = 50;
    char answer[n], correct[n];
    int correct_m = snprintf(correct, n, "Hello %s world", "");

    int m = my_snprintf(answer, n, "Hello %s world", "");

    ck_assert_int_eq(m, correct_m);
    ck_assert_int_eq(strcmp(answer, correct), 0);
}
END_TEST

Suite *s_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("s");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, s_simple);
    tcase_add_test(tc_core, s_empty);
    suite_add_tcase(s, tc_core);
    return s;
}
