#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "binary_files.h"

int read_file(FILE *f, int n);

int sort_file(FILE *f, int n);

int filter_file(FILE *fin, FILE *fout, const char *substr, int n);

int delete_file(FILE *f, int n);

#endif //LOGIC_H
