#include "logic.h"

char digits_sum(int, int *);

char odd_digits_sum(int, char *);

char digits_sum(int x, int *sum)
{
    x = abs(x);
    if (x >= 10)
    {
        *sum = 0;
        while (x >= 10)
        {
            *sum += x % 10;
            x /= 10;
        }
        *sum += x;
    }
    else
    {
        *sum = x;
    }
    return EXIT_SUCCESS;
}

char odd_digits_sum(int x, char *digits_sum_is_odd)
{
    int sum;
    digits_sum(x, &sum);
    *digits_sum_is_odd = (char) (sum % 2);
    return EXIT_SUCCESS;
}

char get_matrix(big_matrix b_mtx, int *b_n, matrix mtx, int n, int m)
{
    *b_n = 0;
    for (int i = 0; i < n; i++)
    {
        char count = 0;
        for (int j = 0; (j < m) && (count < 2); j++)
        {
            char digits_sum_is_odd;
            odd_digits_sum(mtx[i][j], &digits_sum_is_odd);
            if (digits_sum_is_odd)
                count++;
        }

        for (int j = 0; j < m; j++)
        {
            if (count >= 2)
            {
                b_mtx[*b_n][j] = -1;
                b_mtx[*b_n + 1][j] = mtx[i][j];
            }
            else
            {
                b_mtx[*b_n][j] = mtx[i][j];
            }
        }
        if (count >= 2)
            (*b_n)++;
        (*b_n)++;
    }
    return EXIT_SUCCESS;
}