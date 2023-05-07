#ifndef LAB_04_02_02_STRING_ARRAY_H
#define LAB_04_02_02_STRING_ARRAY_H

#define W_LEN 16
#define MAX_W 16

#include <stdlib.h>

typedef char string_array[MAX_W][W_LEN];

int split_string(const char *, string_array, int *);

int string_array_contains(const char *, string_array, int);

int remove_duplicates(string_array, int *);

#endif //LAB_04_02_02_STRING_ARRAY_H
