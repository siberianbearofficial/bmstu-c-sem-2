#include "output.h"

char print_big_matrix(big_matrix mtx, int n, int m)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}