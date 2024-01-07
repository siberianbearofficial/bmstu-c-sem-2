#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

#define MEMORY_ERROR 10

typedef long long matrix_element_t;
typedef matrix_element_t *matrix_row_t;
typedef matrix_row_t *matrix_t;

int malloc_matrix(size_t n, size_t m, matrix_t *matrix);

int free_matrix(size_t n, matrix_t matrix);

int input_matrix(size_t *n, size_t *m, matrix_t *mtx);

int print_matrix(size_t n, size_t m, matrix_t matrix);

int squarify_matrix(size_t *n, size_t *m, matrix_t matrix);

int adjust_matrix(size_t *n, size_t *m, matrix_t *matrix, size_t new_n, size_t new_m);

int multiply_matrix(size_t n, size_t m, matrix_t a, matrix_t b, matrix_t c);

int copy_matrix(size_t n, size_t m, matrix_t dst, matrix_t src);

int power_matrix(size_t n, size_t m, int x, matrix_t matrix, matrix_t result);

#endif //MATRIX_H
