#ifndef STUDENT_H
#define STUDENT_H

#define SURNAME_LEN 25
#define NAME_LEN 10
#define MARKS_COUNT 4

#include <stdio.h>
#include <stdlib.h>

typedef struct student_struct
{
    char surname[SURNAME_LEN];
    char name[NAME_LEN];
    unsigned int marks[MARKS_COUNT];
} student_struct;

int print_student(student_struct *student);

#endif //STUDENT_H
