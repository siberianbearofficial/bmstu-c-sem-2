#ifndef LAB_04_04_02_LOGIC_H
#define LAB_04_04_02_LOGIC_H

#include <stdio.h>  // TODO: remove this lib
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include <ctype.h>

char split_string(char *, string_array, int *);

char valid_data(string_array, int);

int get_month(const char *);

int valid_year(int);

int valid_day(int, int, int);

#endif //LAB_04_04_02_LOGIC_H
