// По матрице получить и вывести на экран одномерный массив, присвоив
// его 𝑘-тому элементу значение 1, если в 𝑘-ом столбце чередуются
// положительные и отрицательные элементы, и значение 0 в иных случаях.

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
            int arr[M];
            get_arr((int *) &arr, mtx, n, m);
            print_arr((const int *) arr, m);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}