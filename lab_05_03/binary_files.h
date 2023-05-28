#ifndef BINARY_FILES_H
#define BINARY_FILES_H

#include <stdio.h>
#include <stdlib.h>

int get_file_size(FILE *f, int *size);

int get_number_by_pos(FILE *f, int pos, int *num);

int put_number_by_pos(FILE *f, int pos, int num);

#endif //BINARY_FILES_H
