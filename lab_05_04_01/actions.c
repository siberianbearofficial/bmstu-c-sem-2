#include "actions.h"

int get_mode(const char *mod_str);

int process(int argc, char **argv)
{
    int exit_code = UNKNOWN_ARGS;
    if (argc >= MIN_ARGS_COUNT)
    {
        int mode = get_mode(argv[MODE_IND]);
        switch (mode)
        {
            case SORT_ARGS:
                {
                    if (argc == SORT_ARGS_COUNT)
                        exit_code = sort(argv[PATH_IND]);
                    break;
                }
            case FILTER_ARGS:
                {
                    if (argc == FILTER_ARGS_COUNT)
                        exit_code = filter(argv[SRC_IND], argv[DST_IND], argv[SUBSTR_IND]);
                    break;
                }
            case DELETE_ARGS:
                {
                    if (argc == DELETE_ARGS_COUNT)
                        exit_code = delete(argv[PATH_IND]);
                    break;
                }
        }
    }
    return exit_code;
}

int get_mode(const char *mod_str)
{
    int mode;
    if (!strcmp(mod_str, SORT_KEY))
        mode = SORT_ARGS;
    else if (!strcmp(mod_str, FILTER_KEY))
        mode = FILTER_ARGS;
    else if (!strcmp(mod_str, DELETE_KEY))
        mode = DELETE_ARGS;
    else
        mode = UNKNOWN_ARGS;
    return mode;
}

int print(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, READ_MODE);
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
    FILE *f = fopen(path, READ_WRITE_MODE);
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
    FILE *fin = fopen(src, READ_MODE);
    FILE *fout = fopen(dst, WRITE_MODE);
    if (fin && fout)
    {
        int n;
        exit_code = get_file_size(fin, &n) || filter_file(fin, fout, substr, n) || fclose(fin) || fclose(fout);
    }
    if (!exit_code)
        print(dst);
    return exit_code;
}

int delete(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, READ_WRITE_MODE);
    if (f)
    {
        int n;
        exit_code = get_file_size(f, &n) || delete_file(f, n) || fclose(f);
    }
    if (!exit_code)
        print(path);
    return exit_code;
}
