#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "binary_files.h"
#include "constants.h"

int read_file(FILE *f, int n, student_struct *student);

int sort_file(FILE *f, int n, student_struct *student1, student_struct *student2);

int filter_file(FILE *fin, FILE *fout, const char *substr, int n, student_struct *student);

int delete_file(FILE *f, int n, student_struct *student);

#endif //LOGIC_H
