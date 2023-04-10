#include "logic.h"

char get_result(int *result, matrix mtx, int n)
{
    char exit_code = EXIT_FAILURE;
    *result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            if ((abs(mtx[i][j]) % 10 == 5) && (exit_code || (mtx[i][j] > *result)))
            {
                *result = mtx[i][j];
                exit_code = EXIT_SUCCESS;
            }
        }
    }
    return exit_code;
}