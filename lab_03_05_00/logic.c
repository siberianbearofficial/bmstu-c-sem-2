#include "logic.h"

char reverse(int *, int);

char prime(int);

char get_p_nums_and_inds(matrix, int, int, int *, int *, int *, int *);

char set_p_nums_by_inds(matrix, int, int, int, const int *, const int *, const int *);

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

char reverse_prime_numbers(matrix mtx, int n, int m)
{
    char exit_code = EXIT_FAILURE;

    int p_nums[N * M];
    int i_inds[N * M];
    int j_inds[N * M];
    int k = 0;
    
    get_p_nums_and_inds(mtx, n, m, &k, (int *) p_nums, (int *) i_inds, (int *) j_inds);

    if (k > 0)
    {
        reverse((int *) &p_nums, k);
        set_p_nums_by_inds(mtx, n, m, k, (const int *) p_nums, (const int *) i_inds, (const int *) j_inds);
        exit_code = EXIT_SUCCESS;
    }
    return exit_code;
}

char set_p_nums_by_inds(matrix mtx, int n, int m, int k, const int *p_nums, const int *i_inds, const int *j_inds)
{
    for (int i = 0; i < k; i++)
    {
        mtx[i_inds[i]][j_inds[i]] = p_nums[i];
    }
    return EXIT_SUCCESS;
}

char get_p_nums_and_inds(matrix mtx, int n, int m, int *k, int *p_nums, int *i_inds, int *j_inds)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (prime(mtx[i][j]))
            {
                p_nums[*k] = mtx[i][j];
                i_inds[*k] = i;
                j_inds[*k] = j;
                (*k)++;
            }
        }
    }
    return EXIT_SUCCESS;
}