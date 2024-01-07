#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "number.h"

#define SHORT_LINE_ERROR 12
#define LONG_LINE_ERROR 13
#define INVALID_COMMAND_ERROR 14
#define INVALID_INPUT_ERROR 15

int input_line(FILE *file, char **str, size_t *length, size_t max_length);

int main(void)
{
    char *str = NULL;
    size_t length;
    int exit_code = input_line(stdin, &str, &length, 5);
    if (!exit_code)
    {
        if (!strcmp(str, "out"))
        {
            exit_code = input_line(stdin, &str, &length, 10);
            if (!exit_code)
            {
                char *end_ptr;
                int n = (int) strtol(str, &end_ptr, 10);
                if (end_ptr && n > 0)
                {
                    number_t a;
                    exit_code = create_number(&a, n);
                    if (!exit_code)
                    {
                        output_number(a);
                        delete_number(a);
                    }
                }
                else
                    exit_code = INVALID_INPUT_ERROR;
            }
        }
        else if (!strcmp(str, "mul"))
        {
            exit_code = input_line(stdin, &str, &length, 10);
            if (!exit_code)
            {
                char *end_ptr;
                int n = (int) strtol(str, &end_ptr, 10);
                if (end_ptr && n > 0)
                {
                    exit_code = input_line(stdin, &str, &length, 10);
                    if (!exit_code)
                    {
                        int m = (int) strtol(str, &end_ptr, 10);
                        if (end_ptr && m > 0)
                        {
                            number_t a, b, c;
                            exit_code = create_number(&a, n);
                            if (!exit_code)
                            {
                                exit_code = create_number(&b, m);
                                if (!exit_code)
                                {
                                    exit_code = create_number(&c, 0);
                                    if (!exit_code)
                                    {
                                        exit_code = multiply_number(a, b, c);
                                        if (!exit_code)
                                            output_number(c);
                                        delete_number(c);
                                    }
                                    delete_number(b);
                                }
                                delete_number(a);
                            }
                        }
                        else
                            exit_code = INVALID_INPUT_ERROR;
                    }
                }
                else
                    exit_code = INVALID_INPUT_ERROR;
            }
        }
        else if (!strcmp(str, "sqr"))
        {
            exit_code = input_line(stdin, &str, &length, 10);
            if (!exit_code)
            {
                char *end_ptr;
                int n = (int) strtol(str, &end_ptr, 10);
                if (end_ptr && n > 0)
                {
                    number_t a, b;
                    exit_code = create_number(&a, n);
                    if (!exit_code)
                    {
                        exit_code = create_number(&b, 0);
                        if (!exit_code)
                        {
                            sqr_number(a, b);
                            output_number(b);
                            delete_number(b);
                        }
                        delete_number(a);
                    }
                }
                else
                    exit_code = INVALID_INPUT_ERROR;
            }
        }
        else if (!strcmp(str, "div"))
        {
            exit_code = input_line(stdin, &str, &length, 10);
            if (!exit_code)
            {
                char *end_ptr;
                int n = (int) strtol(str, &end_ptr, 10);
                if (end_ptr && n > 0)
                {
                    exit_code = input_line(stdin, &str, &length, 10);
                    if (!exit_code)
                    {
                        int m = (int) strtol(str, &end_ptr, 10);
                        if (end_ptr && m > 0)
                        {
                            number_t a, b, c;
                            exit_code = create_number(&a, n);
                            if (!exit_code)
                            {
                                exit_code = create_number(&b, m);
                                if (!exit_code)
                                {
                                    exit_code = create_number(&c, 0);
                                    if (!exit_code)
                                    {
                                        exit_code = div_number(a, b, c);
                                        if (!exit_code)
                                            output_number(c);
                                        delete_number(c);
                                    }
                                    delete_number(b);
                                }
                                delete_number(a);
                            }
                        }
                        else
                            exit_code = INVALID_INPUT_ERROR;
                    }
                }
                else
                    exit_code = INVALID_INPUT_ERROR;
            }
        }
        else
            exit_code = INVALID_COMMAND_ERROR;
    }
    free(str);
    return exit_code;
}

int full_line(const char *str, size_t length, size_t max_length)
{
    char return_code = EXIT_FAILURE;
    if (str && *str)
    {
        if (length < 1)
            return_code = SHORT_LINE_ERROR;
        else if (length > max_length && str[length - 1] != '\n')
            return_code = LONG_LINE_ERROR;
        else
            return_code = EXIT_SUCCESS;
    }
    return return_code;
}

int input_line(FILE *file, char **str, size_t *length, size_t max_length)
{
    char *line = malloc(sizeof(char) * (max_length + 2));
    if (!line)
        return MEMORY_ERROR;

    int return_code = EXIT_FAILURE;
    if (fgets(line, (int) max_length + 2, file))
    {
        *length = strlen(line);
        return_code = full_line(line, *length, max_length);

        if (!return_code)
        {
            if (line[*length - 1] == '\n')
                line[--(*length)] = '\0';
            char *buffer = realloc(*str, sizeof(char) * (*length + 1));
            if (buffer)
            {
                *str = buffer;
                strcpy(*str, line);
            }
            else
                return_code = MEMORY_ERROR;
        }
    }

    free(line);

    return return_code;
}
