#include "string_array.h"

int append_word(const char *, string_array, int *);

int append_word(const char *word, string_array array, int *n)
{
    char exit_code = EXIT_SUCCESS;
    if (*n < MAX_W)
    {
        int i;
        for (i = 0; i < W_LEN && word[i]; i++)
            array[*n][i] = word[i];
        if (i < (W_LEN - 1))
        {
            array[*n][i] = '\0';
            (*n)++;
        }
        else
            exit_code = EXIT_FAILURE;
    }
    return exit_code;
}

int split_string(char *str, string_array words, int *words_count)
{
    *words_count = 0;
    const char *delim = " \t\n";
    if (strrchr(str, '\n') && str[0] != '\n')
    {
        char *token = strtok(str, delim);

        while (token)
        {
            if (!append_word(token, words, words_count))
                token = strtok(NULL, delim);
            else
                token = NULL;
        }

    }
    return (char) (*words_count <= 0);
}
