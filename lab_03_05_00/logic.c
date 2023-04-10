#include "logic.h"

char reverse(int *, int);

char prime(int);

char reverse(int *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int new_arr_i = arr[n - i - 1];
        arr[n - i - 1] = arr[i];
        arr[i] = new_arr_i;
    }
    return EXIT_SUCCESS;
}

char prime(int x)
{
    char is_prime = 1;
    if (x > 2)
    {
        is_prime = 1;
        for (int i = 2; (i < ((int) sqrt(x)) + 1) && is_prime; i++)
        {
            if (!(x % i))
            {
                is_prime = 0;
            }
        }
    }
    else if (x != 2)
    {
        is_prime = 0;
    }
    return is_prime;
}

char get_result(matrix mtx, int n, int m)
{
    char exit_code = EXIT_SUCCESS;

    int prime_numbers[N * M];
    int i_indexes[N * M];
    int j_indexes[N * M];

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (prime(mtx[i][j]))
            {
                prime_numbers[k] = mtx[i][j];
                i_indexes[k] = i;
                j_indexes[k] = j;
                k++;
            }
        }
    }

    if (k > 0)
    {
        reverse((int *) &prime_numbers, k);
        for (int i = 0; i < k; i++)
        {
            mtx[i_indexes[i]][j_indexes[i]] = prime_numbers[i];
        }
    }
    else
    {
        exit_code = EXIT_FAILURE;
    }
    return exit_code;
}