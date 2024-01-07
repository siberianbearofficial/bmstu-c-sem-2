#include <stdlib.h>
#include <math.h>

#include "matrix.h"

int malloc_matrix(size_t n, size_t m, matrix_t *matrix)
{
    *matrix = malloc(sizeof(matrix_row_t) * n);
    if (!*matrix)
        return MEMORY_ERROR;

    int exit_code = EXIT_SUCCESS;

    size_t i;
    for (i = 0; !exit_code && i < n; i++)
    {
        (*matrix)[i] = malloc(sizeof(matrix_element_t) * m);
        if (!(*matrix)[i])
            exit_code = MEMORY_ERROR;
    }

    if (exit_code)
        free_matrix(i, *matrix);

    return exit_code;
}

int free_matrix(size_t n, matrix_t matrix)
{
    for (size_t i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    return EXIT_SUCCESS;
}

int input_matrix(size_t *n, size_t *m, matrix_t *matrix)
{
    int buffer;
    int exit_code = scanf("%d", &buffer) != 1 || buffer <= 0;
    if (exit_code)
        return exit_code;
    *n = (size_t) buffer;

    exit_code = scanf("%d", &buffer) != 1 || buffer <= 0;
    if (exit_code)
        return exit_code;
    *m = (size_t) buffer;

    exit_code = malloc_matrix(*n, *m, matrix);
    if (exit_code)
        return exit_code;

    size_t i;
    for (i = 0; !exit_code && i < *n; i++)
        for (size_t j = 0; !exit_code && j < *m; j++)
            exit_code = scanf("%lld", &((*matrix)[i][j])) != 1;

    if (exit_code)
        free_matrix(*n, *matrix);

    return exit_code;
}

int print_matrix(size_t n, size_t m, matrix_t matrix)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%lld ", matrix[i][j]);
        printf("\n");
    }
    return EXIT_SUCCESS;
}

matrix_element_t column_low_average(size_t n, matrix_t matrix, size_t index)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += (double) matrix[i][index];
    return (matrix_element_t) floor(sum / (double) n);
}

matrix_element_t row_min(size_t m, matrix_t matrix, size_t index)
{
    matrix_element_t min = matrix[index][0];
    for (size_t j = 0; j < m; j++)
        if (matrix[index][j] < min)
            min = matrix[index][j];
    return min;
}

int max(size_t n, size_t m, matrix_t matrix, size_t *max_i, size_t *max_j)
{
    *max_i = 0;
    *max_j = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (matrix[i][j] >= matrix[*max_i][*max_j])
            {
                *max_i = i;
                *max_j = j;
            }
        }
    }
    return EXIT_SUCCESS;
}

int add_row(size_t *n, const size_t *m, matrix_t *matrix)
{
    matrix_t tmp_matrix = realloc(*matrix, sizeof(matrix_row_t) * ++(*n));
    if (!tmp_matrix)
        return MEMORY_ERROR;

    *matrix = tmp_matrix;
    (*matrix)[*n - 1] = malloc(sizeof(matrix_element_t) * *m);
    return EXIT_SUCCESS;
}

int add_column(const size_t *n, size_t *m, const matrix_t *matrix)
{
    int exit_code = EXIT_SUCCESS;
    for (size_t i = 0; !exit_code && i < *n; i++)
    {
        matrix_row_t tmp_row = realloc((*matrix)[i], sizeof(matrix_element_t) * (*m + 1));
        if (!tmp_row)
            exit_code = MEMORY_ERROR;
        (*matrix)[i] = tmp_row;
    }
    (*m)++;
    return exit_code;
}

int pop_row(size_t *n, matrix_t matrix, size_t index)
{
    free(matrix[index]);
    for (size_t i = index; i < *n - 1; i++)
        matrix[i] = matrix[i + 1];
    (*n)--;
    return EXIT_SUCCESS;
}

int pop_column(const size_t *n, size_t *m, matrix_t matrix, size_t index)
{
    for (size_t i = 0; i < *n; i++)
        for (size_t j = index; j < *m - 1; j++)
            matrix[i][j] = matrix[i][j + 1];
    (*m)--;
    return EXIT_SUCCESS;
}

int squarify_matrix(size_t *n, size_t *m, matrix_t matrix)
{
    while (*n > *m)
    {
        size_t max_i, max_j;
        max(*n, *m, matrix, &max_i, &max_j);
        pop_row(n, matrix, max_i);
    }
    while (*m > *n)
    {
        size_t max_i, max_j;
        max(*n, *m, matrix, &max_i, &max_j);
        pop_column(n, m, matrix, max_j);
    }
    return EXIT_SUCCESS;
}

int adjust_matrix(size_t *n, size_t *m, matrix_t *matrix, size_t new_n, size_t new_m)
{
    while (*n < new_n)
    {
        // округлённые к нижнему целому средние арифметические элементов столбцов
        add_row(n, m, matrix);
        for (size_t j = 0; j < *m; j++)
            (*matrix)[*n - 1][j] = column_low_average(*n - 1, *matrix, j);
    }
    while (*m < new_m)
    {
        // минимумы по строкам
        add_column(n, m, matrix);
        for (size_t i = 0; i < *n; i++)
            (*matrix)[i][*m - 1] = row_min(*m - 1, *matrix, i);
    }
    return EXIT_SUCCESS;
}

int multiply_matrix(size_t n, size_t m, matrix_t a, matrix_t b, matrix_t c)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for (size_t k = 0; k < m; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    return EXIT_SUCCESS;
}

int copy_matrix(size_t n, size_t m, matrix_t dst, matrix_t src)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            dst[i][j] = src[i][j];
    return EXIT_SUCCESS;
}

int power_matrix(size_t n, size_t m, int x, matrix_t matrix, matrix_t result)
{
    if (x == 0)
    {
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                result[i][j] = i == j;
    }
    else if (x == 1)
        copy_matrix(n, m, result, matrix);
    else if (x > 1)
    {
        multiply_matrix(n, m, matrix, matrix, result);
        if (x > 2)
        {
            matrix_t buffer;
            malloc_matrix(n, m, &buffer);
            for (int i = 0; i < x - 2; i++)
            {
                multiply_matrix(n, m, result, matrix, buffer);
                copy_matrix(n, m, result, buffer);
            }
            free_matrix(n, buffer);
        }
    }
    return EXIT_SUCCESS;
}
