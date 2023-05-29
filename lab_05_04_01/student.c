#include "student.h"

int print_student(student_struct *student)
{
    printf("%s\n%s\n%d\n%d\n%d\n%d\n", student->surname, student->name,
    student->marks[0], student->marks[1], student->marks[2], student->marks[3]);
    return EXIT_SUCCESS;
}
