#ifndef BINARY_FILES_H
#define BINARY_FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "student.h"

int put_student_by_pos(FILE *f, int pos, student_struct *student);

int get_student_by_pos(FILE *f, int pos, student_struct *student);

int get_file_size(FILE *f, int *size);

int cut(FILE *f, int size);

#endif //BINARY_FILES_H
