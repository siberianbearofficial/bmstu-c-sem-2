#include "logic.h"

char get_bull_matrix(matrix mtx, int n, int m)
{
    int k = 1;
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if ((!(j % 2) && (m % 2)) || ((j % 2) && !(m % 2)))
                mtx[i][j] = k;
            else
                mtx[n - i - 1][j] = k;
            k++;
        }
    }
    return EXIT_SUCCESS;
}