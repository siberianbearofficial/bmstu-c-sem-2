#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "constants.h"

typedef struct student_struct
{
    char surname[SURNAME_LEN];
    char name[NAME_LEN];
    uint32_t marks[MARKS_COUNT];
} student_struct;

int print_student(student_struct *student);

#endif //STUDENT_H
