// Упорядочить строки матрицы по возрастанию произведения их элементов

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
            sort_matrix(mtx, n, m);
            print_matrix(mtx, n, m);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}