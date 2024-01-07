/*
 * Вариант 2:
 * Удалять строки или столбцы с максимальным элементом в матрице.
 * Если обнаружено несколько, считать целевым максимум, который был бы встречен последним при обходе по строкам.
 *
 * Добавлять всегда сначала новые строки, потом — столбцы.
 * Добавлять в новые строки округлённые к нижнему целому средние арифметические элементов столбцов.
 * Добавлять в новые столбцы минимумы по строкам.
 */

#include <stdio.h>

#include "matrix.h"

int main(void)
{
    size_t n, m;
    matrix_t a;
    int exit_code = input_matrix(&n, &m, &a);
    if (!exit_code)
    {
        size_t p, q;
        matrix_t b;
        exit_code = input_matrix(&p, &q, &b);
        if (!exit_code)
        {
            squarify_matrix(&n, &m, a);
            squarify_matrix(&p, &q, b);

            if (n > p)
                exit_code = adjust_matrix(&p, &q, &b, n, m);
            else if (p > n)
                exit_code = adjust_matrix(&n, &m, &a, p, q);

            if (!exit_code)
            {
                int x, y;
                exit_code = scanf("%d", &x) != 1 || x < 0;
                if (!exit_code)
                {
                    exit_code = scanf("%d", &y) != 1 || y < 0;
                    if (!exit_code)
                    {
                        matrix_t result;
                        exit_code = malloc_matrix(n, m, &result);
                        if (!exit_code)
                        {
                            power_matrix(n, m, x, a, result);
                            copy_matrix(n, m, a, result);
                            power_matrix(p, q, y, b, result);
                            copy_matrix(p, q, b, result);
                            multiply_matrix(n, m, a, b, result);
                            print_matrix(n, m, result);
                            free_matrix(n, result);
                        }
                    }
                }
            }
            free_matrix(n, b);
        }
        free_matrix(n, a);
    }

    return exit_code;
}
