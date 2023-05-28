#include "student.h"

int print_student(Student *student)
{
    printf("%s %s, marks: %d %d %d %d\n", student->surname, student->name,
           student->marks[0], student->marks[1], student->marks[2], student->marks[3]);
    return EXIT_SUCCESS;
}
