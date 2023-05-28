#include "actions.h"

int get_mode(const char *mod_str);

int create(const char *path);

int print(const char *path);

int sort(const char *path);

int process(int argc, char **argv)
{
    int exit_code = EXIT_FAILURE;
    if (argc == 3)
    {
        int mode = get_mode(argv[1]);
        switch (mode)
        {
            case 0:
                {
                    exit_code = create(argv[2]);
                    break;
                }
            case 1:
                {
                    exit_code = print(argv[2]);
                    break;
                }
            case 2:
                {
                    exit_code = sort(argv[2]);
                    break;
                }
        }
    }
    return exit_code;
}

int get_mode(const char *mod_str)
{
    int mode;
    if (!strcmp(mod_str, "c"))
        mode = 0;
    else if (!strcmp(mod_str, "p"))
        mode = 1;
    else if (!strcmp(mod_str, "s"))
        mode = 2;
    else
        mode = 100;
    return mode;
}

int create(const char *path)
{
    int exit_code = EXIT_FAILURE;
    FILE *f = fopen(path, "wb");
    exit_code = !f || generate_random_file(f) || fclose(f);
    return exit_code;
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
    return exit_code;
}
