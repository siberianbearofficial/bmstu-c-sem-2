#include "binary_files.h"

int put_student_by_pos(FILE *f, int pos, Student *student)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, pos * sizeof(Student), SEEK_SET))
    {
        if (fwrite(student, sizeof(Student), 1, f) == 1)
        {
            fflush(f);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}

int get_student_by_pos(FILE *f, int pos, Student *student)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, pos * sizeof(Student), SEEK_SET))
        exit_code = fread(student, sizeof(Student), 1, f) != 1;
    return exit_code;
}

int get_file_size(FILE *f, int *size)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, 0, SEEK_END))
    {
        int size_in_bytes = ftell(f);
        if (size_in_bytes > 0 && !(size_in_bytes % sizeof(Student)))
        {
            *size = size_in_bytes / sizeof(Student);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}

int cut(FILE *f, int size)
{
    return ftruncate(f->_fileno, size * sizeof(Student));
}
