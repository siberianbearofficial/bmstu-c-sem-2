#include "matrix.h"

int free_matrix(size_t n, matrix_t matrix)
{
    for (size_t i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    return EXIT_SUCCESS;
}

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

int input_matrix(size_t *n, size_t *m, matrix_t *matrix)
{
    scanf("%zu%zu", n, m);
    int exit_code = malloc_matrix(*n, *m, matrix);

    for (size_t i = 0; !exit_code && i < *n; i++)
        for (size_t j = 0; !exit_code && j < *m; j++)
            exit_code = scanf("%lld", &((*matrix)[i][j])) != 1;

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

int pop_row(size_t *n, const size_t *m, matrix_t matrix, size_t index)
{
    free(matrix[index]);
    for (size_t i = index; i < *n - 1; i++)
        matrix[i] = matrix[i + 1];
    (*n)--;
    return EXIT_SUCCESS;
}

int max(size_t n, size_t m, matrix_t matrix, size_t *mi, size_t *mj)
{
    *mi = 0;
    *mj = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (matrix[i][j] > matrix[*mi][*mj])
            {
                *mi = i;
                *mj = j;
            }
        }
    }
    return EXIT_SUCCESS;
}
