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

    int *pb, *pe;
    int exit_code = read_array(in_file, &pb, &pe);

    if (!exit_code)
    {
        if (argc == MAX_ARGS_COUNT && !strcmp(argv[FILTER_ARG_IND], "f"))
        {
            int *pb_dst, *pe_dst;
            exit_code = key((const int *) pb, (const int *) pe, &pb_dst, &pe_dst);

            if (!exit_code)
            {
                delete_array(pb);
                pb = pb_dst;
                pe = pe_dst;
            }
        }
        else if (argc == MAX_ARGS_COUNT)
            exit_code = INVALID_ARGS_ERROR;

        if (!exit_code)
        {
            mysort(pb, (size_t) (pe - pb), sizeof(int), intcmp);
            exit_code = write_array(out_file, pb, pe);
        }

        delete_array(pb);
    }

    fclose(in_file);
    fclose(out_file);
    return exit_code;
}
