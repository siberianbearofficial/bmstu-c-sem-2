#include "string_array.h"

int append_word(const char *, string_array, int *);

int append_word(const char *word, string_array array, int *n)
{
    char exit_code = EXIT_SUCCESS;
    int i;
    for (i = 0; word[i] && i < W_LEN; i++)
        array[*n][i] = word[i];
    if (i < (W_LEN - 1))
    {
        array[*n][i] = '\0';
        (*n)++;
        exit_code |= word[i];
    }
    return exit_code;
}

int split_string(char *str, string_array words, int *words_count)
{
    *words_count = 0;
    const char *delim = " \n";
    if (strrchr(str, '\n'))
    {
        char *token = strtok(str, delim);
        do
        {
            if (!append_word(token, words, words_count))
                token = strtok(NULL, delim);
        }
        while (token);
    }
    return (char) (*words_count <= 0);
}
