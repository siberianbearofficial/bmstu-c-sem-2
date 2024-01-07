#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"


int main(void)
{
    size_t n, m;
    matrix_t matrix;
    int exit_code = input_matrix(&n, &m, &matrix);
    if (exit_code)
        return exit_code;

    size_t mi, mj;
    max(n, m, matrix, &mi, &mj);

    pop_row(&n, &m, matrix, mi);

    print_matrix(n, m, matrix);

    free_matrix(n, matrix);

    return exit_code;
}
