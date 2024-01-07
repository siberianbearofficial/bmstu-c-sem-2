#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ERROR 2

typedef long long array_element_t;
typedef array_element_t *array_t;

int malloc_array(size_t n, array_t *array);

int input_array(size_t *n, array_t *array);

int print_array(size_t n, array_t array);

int filter_array(size_t *n, array_t array);

#endif //ARRAY_H
