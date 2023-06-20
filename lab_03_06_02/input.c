#include "input.h"

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