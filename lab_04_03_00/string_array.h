#ifndef LAB_04_03_00_STRING_ARRAY_H
#define LAB_04_03_00_STRING_ARRAY_H

#define W_LEN 16
#define MAX_W 16

#include <stdlib.h>
#include <string.h>

typedef char string_array[MAX_W][W_LEN];

int string_array_to_string(char *, string_array, int);

int get_last_word(string_array, int, char *);

int reverse_string_array(string_array, int);

int move_string_in_array(int, int, string_array);

int split_string(char *, string_array, int *);

#endif //LAB_04_03_00_STRING_ARRAY_H
