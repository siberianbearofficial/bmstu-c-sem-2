#include "actions.h"

int get_mode(const char *mod_str);

int create(const char *path);

int print(const char *path);

int sort(const char *path);

int process(int argc, char **argv)
{
    int exit_code = EXIT_FAILURE;
    if (argc == ARGS_COUNT)
    {
        int mode = get_mode(argv[MODE_IND]);
        switch (mode)
        {
            case CREATE_ARGS:
                {
                    exit_code = create(argv[PATH_IND]);
                    break;
                }
            case PRINT_ARGS:
                {
                    exit_code = print(argv[PATH_IND]);
                    break;
                }
            case SORT_ARGS:
                {
                    exit_code = sort(argv[PATH_IND]);
                    break;
                }
        }
    }
    return exit_code;
}

int get_mode(const char *mod_str)
{
    int mode;
    if (!strcmp(mod_str, CREATE_KEY))
        mode = CREATE_ARGS;
    else if (!strcmp(mod_str, PRINT_KEY))
        mode = PRINT_ARGS;
    else if (!strcmp(mod_str, SORT_KEY))
        mode = SORT_ARGS;
    else
        mode = UNKNOWN_ARGS;
    return mode;
}

int create(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, WRITE_MODE);
    exit_code = !f || generate_random_file(f);
    fclose(f);
    return exit_code;
}

int print(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, READ_MODE);
    if (f)
    {
        int n;
        exit_code = get_file_size(f, &n) || read_file(f, n);
        fclose(f);
    }
    return exit_code;
}

int sort(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, READ_WRITE_MODE);
    if (f)
    {
        int n;
        exit_code = get_file_size(f, &n) || sort_file(f, n);
        fclose(f);
    }
    return exit_code;
}
