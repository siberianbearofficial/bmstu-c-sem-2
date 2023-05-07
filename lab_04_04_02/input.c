#include "input.h"

int full_line(const char *str)
{
    char exit_code = EXIT_FAILURE;
    if (str && *str)
    {
        int i = strlen(str);
        exit_code = i < 1 || str[i - 1] != '\n';
    }
    return exit_code;
}

int input_line(char *str)
{
    return !fgets(str, S_LEN, stdin);
}
