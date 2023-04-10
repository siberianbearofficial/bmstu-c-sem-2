#include "logic.h"

int multiply_elements(const int *, int);

char swap_lines(matrix, int, int, int);

int multiply_elements(const int *elements, int length)
{
    int elements_multiplication = 1;
    for (int i = 0; i < length; i++)
        elements_multiplication *= elements[i];
    return elements_multiplication;
}

char swap_lines(matrix mtx, int from, int where, int length)
{
    for (int j = 0; j < length; j++)
    {
        int x = mtx[where][j];
        mtx[where][j] = mtx[from][j];
        mtx[from][j] = x;
    }
    return EXIT_SUCCESS;
}

char sort_matrix(matrix mtx, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int row[M];
        for (int j = 0; j < m; j++)
            row[j] = mtx[i][j];
        int key = multiply_elements(mtx[i], m);

        int j = i - 1;

        while ((j >= 0) && (multiply_elements(mtx[j], m) > key))
        {
            swap_lines(mtx, j + 1, j, m);
            j--;
        }
        for (int k = 0; k < m; k++)
            mtx[j + 1][k] = row[k];
    }
    return EXIT_SUCCESS;
}