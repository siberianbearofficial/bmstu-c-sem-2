#ifndef LAB_04_04_02_STRING_ARRAY_H
#define LAB_04_04_02_STRING_ARRAY_H

#define W_LEN 130
#define MAX_W 128

#include <stdlib.h>
#include <string.h>

typedef char string_array[MAX_W][W_LEN];

int split_string(char *, string_array, int *);

#endif //LAB_04_04_02_STRING_ARRAY_H
