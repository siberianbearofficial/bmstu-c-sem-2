// Элементы матрицы, которые являются простыми числами, в порядке обхода
// матрицы по строкам поместить в одномерный массив, развернуть массив, и
// вернуть элементы из массива в матрицу в том же порядке, в котором они
// помещались в массив. Если в матрице нет простых чисел, считать ситуацию
// ошибочной.

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
            if (!reverse_prime_numbers(mtx, n, m))
            {
                print_matrix(mtx, n, m);
                exit_code = EXIT_SUCCESS;
            }
        }
    }
    if (exit_code)
    {
        printf("Error");
    }
    return exit_code;
}