#include "actions.h"

int get_mode(const char *mod_str);

int process(int argc, char **argv)
{
    int exit_code = UNKNOWN_ARGS;
    if (argc >= 2)
    {
        int mode = get_mode(argv[1]);
        switch (mode)
        {
            case SORT_ARGS:
                {
                    if (argc == SORT_ARGS_COUNT)
                        exit_code = sort(argv[2]);
                    break;
                }
            case FILTER_ARGS:
                {
                    if (argc == FILTER_ARGS_COUNT)
                        exit_code = filter(argv[2], argv[3], argv[4]);
                    break;
                }
            case DELETE_ARGS:
                {
                    if (argc == DELETE_ARGS_COUNT)
                        exit_code = delete(argv[2]);
                    break;
                }
        }
    }
    return exit_code;
}

int get_mode(const char *mod_str)
{
    int mode;
    if (!strcmp(mod_str, "sb"))
        mode = SORT_ARGS;
    else if (!strcmp(mod_str, "fb"))
        mode = FILTER_ARGS;
    else if (!strcmp(mod_str, "db"))
        mode = DELETE_ARGS;
    else
        mode = UNKNOWN_ARGS;
    return mode;
}

int print(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, "rb");
    if (f)
    {
        int n;
        exit_code = get_file_size(f, &n) || read_file(f, n) || fclose(f);
    }
    return exit_code;
}

int sort(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, "rb+");
    if (f)
    {
        int n;
        exit_code = get_file_size(f, &n) || sort_file(f, n) || fclose(f);
    }
    if (!exit_code)
        print(path);
    return exit_code;
}

int filter(const char *src, const char *dst, const char *substr)
{
    int exit_code = EXIT_FAILURE;
    FILE *fin = fopen(src, "rb");
    FILE *fout = fopen(dst, "wb");
    if (fin && fout)
    {
        int n;
        exit_code = get_file_size(fin, &n) || filter_file(fin, fout, substr, n) || fclose(fin) || fclose(fout);
    }
    if (!exit_code)
        print(dst);  // TODO: remove this print
    return exit_code;
}

int delete(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, "rb+");
    if (f)
    {
        int n;
        exit_code = get_file_size(f, &n) || delete_file(f, n) || fclose(f);
    }
    if (!exit_code)
        print(path);  // TODO: remove this print
    return exit_code;
}
