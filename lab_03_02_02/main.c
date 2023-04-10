// Вставить строку из чисел −1 перед каждой строкой, в которой
// есть хотя бы два элемента, сумма цифр каждого из которых нечётна.

#include "main.h"

int main()
{
    char exit_code = EXIT_FAILURE;
    int n, m;
    if (!input_matrix_size(&n, &m))
    {
        matrix mtx;
        if (!input_matrix(mtx, n, m))
        {
            int b_n;
            big_matrix b_mtx;
            get_matrix(b_mtx, &b_n, mtx, n, m);
            print_big_matrix(b_mtx, b_n, m);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}