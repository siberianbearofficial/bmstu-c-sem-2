#include <string.h>

#include "array.h"

#define MIN_ARGS_COUNT 3
#define MAX_ARGS_COUNT 4

#define FILTER_ARG_IND 3

#define NOT_ENOUGH_ARGS_ERROR 2
#define TOO_MANY_ARGS_ERROR 3
#define INVALID_ARGS_ERROR 4

#define INPUT_FILE_ERROR 11
#define OUTPUT_FILE_ERROR 12

#define INPUT_FILE_MODE "r"
#define OUTPUT_FILE_MODE "w"

int main(int argc, char **argv)
{
    if (argc < MIN_ARGS_COUNT)
        return NOT_ENOUGH_ARGS_ERROR;
    if (argc > MAX_ARGS_COUNT)
        return TOO_MANY_ARGS_ERROR;

    // Input
    FILE *in_file = fopen(argv[1], INPUT_FILE_MODE);
    if (!in_file)
        return INPUT_FILE_ERROR;

    // Output
    FILE *out_file = fopen(argv[2], OUTPUT_FILE_MODE);
    if (!out_file)
    {
        fclose(in_file);
        return OUTPUT_FILE_ERROR;
    }

    int count = 0;
    int exit_code = read_array(in_file, NULL, &count);
    if (!exit_code)
    {
        int *pb = malloc(sizeof(int) * count);
        if (pb)
        {
            read_array(in_file, pb, &count);

            int *pe = pb + count;

            if (argc == MAX_ARGS_COUNT && !strcmp(argv[FILTER_ARG_IND], "f"))
            {
                int new_count = 0;
                exit_code = key((const int *) pb, (const int *) pe, NULL, &new_count);
                if (!exit_code)
                {
                    int *pb_dst = malloc(sizeof(int) * new_count);
                    if (pb_dst)
                    {
                        key((const int *) pb, (const int *) pe, pb_dst, &new_count);
                        free(pb);
                        pb = pb_dst;
                        pe = pb_dst + new_count;
                        count = new_count;
                    }
                }
            }
            else if (argc == MAX_ARGS_COUNT)
                exit_code = INVALID_ARGS_ERROR;

            if (!exit_code)
            {
                mysort(pb, (size_t) (pe - pb), sizeof(int), intcmp);
                exit_code = write_array(out_file, pb, pe);
            }

            free(pb);
        }
    }

    fclose(in_file);
    fclose(out_file);
    return exit_code;
}
