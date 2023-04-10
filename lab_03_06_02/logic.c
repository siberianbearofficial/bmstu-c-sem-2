#include "logic.h"

char get_result(matrix mtx, int n, int m)
{
    int k = 1;
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (j % 2)
                mtx[i][j] = k;
            else
                mtx[n - i - 1][j] = k;
            k++;
        }
    }
    return EXIT_SUCCESS;
}