// Приняв с клавиатуры число строк и столбцов матрицы, заполнить
// прямоугольную целочисленную матрицу «ходом быка» с конца таким образом,
// чтобы минимальное число находилось в правом нижнем углу матрицы.
// Матрицу вывести на экран.

#include "main.h"

int main()
{
    char exit_code = EXIT_FAILURE;
    int n, m;
    if (!input_matrix_size(&n, &m))
    {
        matrix mtx;
        get_result(mtx, n, m);
        print_matrix(mtx, n, m);
        exit_code = EXIT_SUCCESS;
    }
    else
    {
        printf("Error");
    }
    return exit_code;
}