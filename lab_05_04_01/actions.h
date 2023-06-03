#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "binary_files.h"
#include "logic.h"
#include "constants.h"
#include "student.h"

int process(int argc, char **argv);

int print(const char *path, student_struct *student);

int sort(const char *path, student_struct *student1, student_struct *student2);

int filter(const char *src, const char *dst, const char *substr, student_struct *student);

int delete(const char *path, student_struct *student);

#endif //ACTIONS_H
