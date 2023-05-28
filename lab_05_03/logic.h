#ifndef LOGIC_H
#define LOGIC_H

#include <stdlib.h>
#include <time.h>
#include "binary_files.h"

int generate_random_file(FILE *f);

int sort_file(FILE *f, int n);

int read_file(FILE *f, int n);

#endif //LOGIC_H
