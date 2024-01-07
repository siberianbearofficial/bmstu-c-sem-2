#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_ARRAY_ERROR 20
#define MEMORY_ERROR 21
#define INVALID_INPUT_ERROR 10
#define INVALID_OUTPUT_ERROR 22
#define INVALID_POINTERS_ERROR 30
#define NULL_POINTERS_ERROR 32
#define EMPTY_DST_ARRAY_ERROR 33

int read_array(FILE *file, int **pb, int **pe);

int write_array(FILE *file, const int *pb, const int *pe);

int delete_array(int *array);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

int intcmp(const void *p, const void *q);

void mysort(void *base, size_t count, size_t size, int (*cmp)(const void*, const void*));

#endif //ARRAY_H
