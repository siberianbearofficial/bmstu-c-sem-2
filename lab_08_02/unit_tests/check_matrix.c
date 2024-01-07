#include <stdlib.h>
#include <check.h>

#include "matrix.h"



START_TEST(squarify_delete_columns_simple)
{
    size_t n = 3, m = 4, correct_n = 3;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    matrix[1][0] = 5;
    matrix[1][1] = 6;
    matrix[1][2] = 7;
    matrix[1][3] = 8;
    matrix[2][0] = 9;
    matrix[2][1] = 10;
    matrix[2][2] = 11;
    matrix[2][3] = 12;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 5;
    correct[1][1] = 6;
    correct[1][2] = 7;
    correct[2][0] = 9;
    correct[2][1] = 10;
    correct[2][2] = 11;

    int exit_code = squarify_matrix(&n, &m, matrix);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(squarify_delete_columns_several_max)
{
    size_t n = 3, m = 4, correct_n = 3;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 12;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    matrix[1][0] = 5;
    matrix[1][1] = 6;
    matrix[1][2] = 7;
    matrix[1][3] = 8;
    matrix[2][0] = 9;
    matrix[2][1] = 10;
    matrix[2][2] = 11;
    matrix[2][3] = 12;
    
    correct[0][0] = 1;
    correct[0][1] = 12;
    correct[0][2] = 3;
    correct[1][0] = 5;
    correct[1][1] = 6;
    correct[1][2] = 7;
    correct[2][0] = 9;
    correct[2][1] = 10;
    correct[2][2] = 11;

    int exit_code = squarify_matrix(&n, &m, matrix);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(squarify_delete_rows_simple)
{
    size_t n = 4, m = 3, correct_n = 3;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    matrix[3][0] = 10;
    matrix[3][1] = 11;
    matrix[3][2] = 12;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;

    int exit_code = squarify_matrix(&n, &m, matrix);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(squarify_delete_rows_several_max)
{
    size_t n = 4, m = 3, correct_n = 3;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    matrix[3][0] = 10;
    matrix[3][1] = 11;
    matrix[3][2] = 12;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;

    int exit_code = squarify_matrix(&n, &m, matrix);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(squarify_ready)
{
    size_t n = 3, m = 3, correct_n = 3;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;

    int exit_code = squarify_matrix(&n, &m, matrix);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

Suite *squarify_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("squarify");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, squarify_delete_columns_simple);
    tcase_add_test(tc_core, squarify_delete_columns_several_max);
    tcase_add_test(tc_core, squarify_delete_rows_simple);
    tcase_add_test(tc_core, squarify_delete_rows_several_max);
    tcase_add_test(tc_core, squarify_ready);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(adjust_simple)
{
    size_t n = 3, m = 3, correct_n = 5;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[0][3] = 1;
    correct[0][4] = 1;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[1][3] = 4;
    correct[1][4] = 4;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;
    correct[2][3] = 7;
    correct[2][4] = 7;
    correct[3][0] = 4;
    correct[3][1] = 5;
    correct[3][2] = 6;
    correct[3][3] = 4;
    correct[3][4] = 4;
    correct[4][0] = 4;
    correct[4][1] = 5;
    correct[4][2] = 6;
    correct[4][3] = 4;
    correct[4][4] = 4;

    int exit_code = adjust_matrix(&n, &m, &matrix, correct_n, correct_n);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(adjust_same_elements)
{
    size_t n = 3, m = 3, correct_n = 5;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 5;
    matrix[0][1] = 5;
    matrix[0][2] = 5;
    matrix[1][0] = 5;
    matrix[1][1] = 5;
    matrix[1][2] = 5;
    matrix[2][0] = 5;
    matrix[2][1] = 5;
    matrix[2][2] = 5;
    
    correct[0][0] = 5;
    correct[0][1] = 5;
    correct[0][2] = 5;
    correct[0][3] = 5;
    correct[0][4] = 5;
    correct[1][0] = 5;
    correct[1][1] = 5;
    correct[1][2] = 5;
    correct[1][3] = 5;
    correct[1][4] = 5;
    correct[2][0] = 5;
    correct[2][1] = 5;
    correct[2][2] = 5;
    correct[2][3] = 5;
    correct[2][4] = 5;
    correct[3][0] = 5;
    correct[3][1] = 5;
    correct[3][2] = 5;
    correct[3][3] = 5;
    correct[3][4] = 5;
    correct[4][0] = 5;
    correct[4][1] = 5;
    correct[4][2] = 5;
    correct[4][3] = 5;
    correct[4][4] = 5;

    int exit_code = adjust_matrix(&n, &m, &matrix, correct_n, correct_n);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(adjust_ready)
{
    size_t n = 3, m = 3, correct_n = 3;
    
    matrix_t matrix, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;

    int exit_code = adjust_matrix(&n, &m, &matrix, correct_n, correct_n);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) matrix[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(correct_n, correct);
}
END_TEST

Suite *adjust_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("adjust");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, adjust_simple);
    tcase_add_test(tc_core, adjust_same_elements);
    tcase_add_test(tc_core, adjust_ready);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(multiply_simple)
{
    size_t n = 3, m = 3, p = 3, q = 3, correct_n = 3;
    
    matrix_t a, b, c, correct;
    malloc_matrix(n, m, &a);
    malloc_matrix(p, q, &b);
    malloc_matrix(n, q, &c);
    malloc_matrix(correct_n, correct_n, &correct);
    
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;
    
    b[0][0] = 10;
    b[0][1] = 11;
    b[0][2] = 12;
    b[1][0] = 13;
    b[1][1] = 14;
    b[1][2] = 15;
    b[2][0] = 16;
    b[2][1] = 17;
    b[2][2] = 18;
    
    correct[0][0] = 84;
    correct[0][1] = 90;
    correct[0][2] = 96;
    correct[1][0] = 201;
    correct[1][1] = 216;
    correct[1][2] = 231;
    correct[2][0] = 318;
    correct[2][1] = 342;
    correct[2][2] = 366;

    int exit_code = multiply_matrix(n, m, a, b, c);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) c[i][j], (int) correct[i][j]);
    
    free_matrix(n, a);
    free_matrix(p, b);
    free_matrix(n, c);
    free_matrix(correct_n, correct);
}
END_TEST

Suite *multiply_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("multiply");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, multiply_simple);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(power_simple)
{
    size_t n = 3, m = 3, correct_n = 3;
    int x = 3;
    
    matrix_t matrix, result, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(n, m, &result);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 468;
    correct[0][1] = 576;
    correct[0][2] = 684;
    correct[1][0] = 1062;
    correct[1][1] = 1305;
    correct[1][2] = 1548;
    correct[2][0] = 1656;
    correct[2][1] = 2034;
    correct[2][2] = 2412;

    int exit_code = power_matrix(n, m, x, matrix, result);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) result[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(n, result);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(power_0)
{
    size_t n = 3, m = 3, correct_n = 3;
    int x = 0;
    
    matrix_t matrix, result, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(n, m, &result);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 1;
    correct[0][1] = 0;
    correct[0][2] = 0;
    correct[1][0] = 0;
    correct[1][1] = 1;
    correct[1][2] = 0;
    correct[2][0] = 0;
    correct[2][1] = 0;
    correct[2][2] = 1;

    int exit_code = power_matrix(n, m, x, matrix, result);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) result[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(n, result);
    free_matrix(correct_n, correct);
}
END_TEST

START_TEST(power_1)
{
    size_t n = 3, m = 3, correct_n = 3;
    int x = 1;
    
    matrix_t matrix, result, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(n, m, &result);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;

    int exit_code = power_matrix(n, m, x, matrix, result);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) result[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(n, result);
    free_matrix(correct_n, correct);
}
END_TEST

Suite *power_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("power");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, power_simple);
    tcase_add_test(tc_core, power_0);
    tcase_add_test(tc_core, power_1);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(copy_simple)
{
    size_t n = 3, m = 3, correct_n = 3;
    
    matrix_t matrix, result, correct;
    malloc_matrix(n, m, &matrix);
    malloc_matrix(n, m, &result);
    malloc_matrix(correct_n, correct_n, &correct);
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    correct[0][0] = 1;
    correct[0][1] = 2;
    correct[0][2] = 3;
    correct[1][0] = 4;
    correct[1][1] = 5;
    correct[1][2] = 6;
    correct[2][0] = 7;
    correct[2][1] = 8;
    correct[2][2] = 9;

    int exit_code = copy_matrix(n, m, result, matrix);

    ck_assert_int_eq(exit_code, EXIT_SUCCESS);
    
    for (size_t i = 0; i < correct_n; i++)
        for (size_t j = 0; j < correct_n; j++)
            ck_assert_int_eq((int) result[i][j], (int) correct[i][j]);
    
    free_matrix(n, matrix);
    free_matrix(n, result);
    free_matrix(correct_n, correct);
}
END_TEST

Suite *copy_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("copy");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, copy_simple);
    suite_add_tcase(s, tc_core);
    return s;
}
