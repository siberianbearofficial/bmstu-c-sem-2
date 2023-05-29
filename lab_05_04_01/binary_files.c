#include "binary_files.h"

int put_student_by_pos(FILE *f, int pos, student_struct *student)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, pos * sizeof(student_struct), SEEK_SET))
    {
        if (fwrite(student, sizeof(student_struct), STRUCTS_COUNT, f) == STRUCTS_COUNT)
        {
            fflush(f);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}

int get_student_by_pos(FILE *f, int pos, student_struct *student)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, pos * sizeof(student_struct), SEEK_SET))
        exit_code = fread(student, sizeof(student_struct), STRUCTS_COUNT, f) != STRUCTS_COUNT;
    return exit_code;
}

int get_file_size(FILE *f, int *size)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, 0, SEEK_END))
    {
        int size_in_bytes = ftell(f);
        if (size_in_bytes > 0 && !(size_in_bytes % sizeof(student_struct)))
        {
            *size = size_in_bytes / sizeof(student_struct);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}

int cut(FILE *f, int size)
{
    return ftruncate(fileno(f), size * sizeof(student_struct));
}
