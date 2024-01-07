#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define MIN_ARGS_COUNT 3
#define MAX_ARGS_COUNT 4

#define FILTER_ARG_IND 3

#define NOT_ENOUGH_ARGS_ERROR 2
#define TOO_MANY_ARGS_ERROR 3
#define INVALID_ARGS_ERROR 4
#define NO_LIB_ERROR 5

#define INPUT_FILE_ERROR 11
#define OUTPUT_FILE_ERROR 12

#define INPUT_FILE_MODE "r"
#define OUTPUT_FILE_MODE "w"

typedef int (*fn_read_array_t)(FILE *file, int *pb, int *count);

typedef int (*fn_write_array_t)(FILE *file, const int *pb, const int *pe);

typedef int (*fn_key_t)(const int *pb_src, const int *pe_src, int *pb_dst, int *count);

typedef int (*fn_intcmp_t)(const void *p, const void *q);

typedef void (*fn_mysort_t)(void *base, size_t count, size_t size, int (*cmp)(const void *, const void *));

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

    int exit_code = EXIT_SUCCESS;

    void *lib = dlopen("./libarray.so", RTLD_NOW);
    if (lib)
    {
        fn_read_array_t read_array = (fn_read_array_t) dlsym(lib, "read_array");
        fn_write_array_t write_array = (fn_write_array_t) dlsym(lib, "write_array");
        fn_key_t key = (fn_key_t) dlsym(lib, "key");
        fn_intcmp_t intcmp = (fn_intcmp_t) dlsym(lib, "intcmp");
        fn_mysort_t mysort = (fn_mysort_t) dlsym(lib, "mysort");

        int count = 0;
        exit_code = read_array(in_file, NULL, &count);
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
    }
    else
        exit_code = NO_LIB_ERROR;

    fclose(in_file);
    fclose(out_file);
    return exit_code;
}
