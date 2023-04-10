// Для квадратной матрицы найти максимальное число, которое заканчивается
// на цифру 5 и расположено под побочной диагональю.

#include "main.h"

int main()
{
    char exit_code = EXIT_FAILURE;
    int n;
    if (!input_matrix_size(&n))
    {
        matrix mtx;
        if (!input_matrix(mtx, n))
        {
            int result;
            if (!get_result(&result, mtx, n))
            {
                printf("Result: %d", result);
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