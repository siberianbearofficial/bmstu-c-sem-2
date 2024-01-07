#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ERROR 2

typedef long long matrix_element_t;
typedef matrix_element_t *matrix_row_t;
typedef matrix_row_t *matrix_t;

int free_matrix(size_t n, matrix_t matrix);

int malloc_matrix(size_t n, size_t m, matrix_t *matrix);

int input_matrix(size_t *n, size_t *m, matrix_t *matrix);

int print_matrix(size_t n, size_t m, matrix_t matrix);

int pop_row(size_t *n, const size_t *m, matrix_t matrix, size_t index);

int max(size_t n, size_t m, matrix_t matrix, size_t *mi, size_t *mj);

#endif //MATRIX_H
