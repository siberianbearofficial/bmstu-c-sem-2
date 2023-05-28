#include "binary_files.h"

int get_number_by_pos(FILE *f, int pos, int *num)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, pos * sizeof(*num), SEEK_SET))
    {
        int buf[1];
        if (fread(&buf, sizeof(*num), 1, f) == 1)
        {
            *num = buf[0];
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}

int put_number_by_pos(FILE *f, int pos, int num)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, pos * sizeof(num), SEEK_SET))
    {
        int buf[1] = {num};
        if (fwrite(&buf, sizeof(num), 1, f) == 1)
        {
            fflush(f);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}

int get_file_size(FILE *f, int *size)
{
    int exit_code = EXIT_FAILURE;
    if (!fseek(f, 0, SEEK_END))
    {
        int size_in_bytes = ftell(f);
        if (size_in_bytes > 0 && !(size_in_bytes % sizeof(int)))
        {
            *size = size_in_bytes / sizeof(int);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}
