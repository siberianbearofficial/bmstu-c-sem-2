#include "logic.h"

char different_signs(int, int);

char get_arr(int *arr, matrix mtx, int n, int m)
{
    for (int j = 0; (j < m); j++)
        arr[j] = mtx[0][j];
    for (int j = 0; (j < m); j++)
    {
        int result = 1;
        for (int i = 1; (i < n) && result; i++)
        {
            if (!different_signs(arr[j], mtx[i][j]))
            {
                result = 0;
            }
            arr[j] = mtx[i][j];
        }
        if (n > 1)
            arr[j] = result;
        else
            arr[j] = 0;
    }
    return EXIT_SUCCESS;
}

char different_signs(int a, int b)
{
    return (char) ((a * b) < 0);
}