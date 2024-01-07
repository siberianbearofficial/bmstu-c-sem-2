#include <check.h>
#include "number.h"



START_TEST(sqr_number_simple)
{
    number_t a, b;
    create_number(&a, 121);
    create_number(&b, 0);

    int return_code = sqr_number(a, b);
    int num = to_int_number(b);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_int_eq(num, 14641);
    delete_number(a);
    delete_number(b);
}
END_TEST

Suite *sqr_number_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("sqr_number");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, sqr_number_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(multiply_number_simple)
{
    number_t a, b, c;
    create_number(&a, 121);
    create_number(&b, 4);
    create_number(&c, 0);

    int return_code = multiply_number(a, b, c);
    int num = to_int_number(c);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_int_eq(num, 484);
    delete_number(a);
    delete_number(b);
    delete_number(c);
}
END_TEST

Suite *multiply_number_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("multiply_number");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, multiply_number_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(div_number_simple)
{
    number_t a, b, c;
    create_number(&a, 121);
    create_number(&b, 4);
    create_number(&c, 0);

    int return_code = div_number(a, b, c);
    int num = to_int_number(c);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_int_eq(num, 30);
    delete_number(a);
    delete_number(b);
    delete_number(c);
}
END_TEST

START_TEST(div_number_zero)
{
    number_t a, b, c;
    create_number(&a, 4);
    create_number(&b, 9);
    create_number(&c, 0);

    int return_code = div_number(a, b, c);

    ck_assert_int_eq(return_code, ZERO_ERROR);
    delete_number(a);
    delete_number(b);
    delete_number(c);
}
END_TEST

Suite *div_number_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("div_number");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, div_number_simple);
    tcase_add_test(tc_core, div_number_zero);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(create_number_simple)
{
    number_t a;
    create_number(&a, 121);

    int num = to_int_number(a);

    ck_assert_int_eq(num, 121);
    delete_number(a);
}
END_TEST

Suite *create_number_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("create_number");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, create_number_simple);
    suite_add_tcase(s, tc_core);
    return s;
}
