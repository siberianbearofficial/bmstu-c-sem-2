#include "input.h"

char input_matrix(matrix mtx, int n, int m)
{
    char exit_code = EXIT_SUCCESS;
    printf("Input matrix:\n");
    for (int i = 0; (i < n) && !exit_code; i++)
    {
        for (int j = 0; (j < m) && !exit_code; j++)
        {
            if (scanf("%d", &mtx[i][j]) != 1)
            {
                exit_code = EXIT_FAILURE;
            }
        }
    }
    return exit_code;
}

char input_matrix_size(int *n, int *m)
{
    char exit_code = EXIT_FAILURE;
    printf("Input matrix size: ");
    if (scanf("%d%d", n, m) == 2)
    {
        if (*n > 0 && *n <= N)
        {
            if (*m > 0 && *m <= M)
            {
                exit_code = EXIT_SUCCESS;
            }
        }
    }
    return exit_code;
}