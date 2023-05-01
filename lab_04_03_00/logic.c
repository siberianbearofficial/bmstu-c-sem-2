#include "logic.h"

char string_array_to_string(char *, string_array, int);

char append_word(const char *, string_array, int *);

char modify_word(char *);

char string_array_to_string(char *, string_array, int);

char append_word(const char *word, string_array array, int *n)
{
    int i;
    for (i = 0; word[i]; i++)
    {
        array[*n][i] = word[i];
    }
    array[*n][i] = '\0';
    (*n)++;
    return EXIT_SUCCESS;
}

char split_string(char *str, string_array words, int *words_count)
{
    *words_count = 0;
    const char *delim = " ,;:-.!?\n";
    char *token = strtok(str, delim);
    do
    {
        append_word(token, words, words_count);
        token = strtok(NULL, delim);
    }
    while (token);
    return (char) (*words_count > 0);
}

char modify_word(char *word)
{
    char exit_code = EXIT_SUCCESS;
    if (word[0] == '\0')
        exit_code = EXIT_FAILURE;
    else if (word[1] != '\0')
    {
        int j = 1;
        for (int i = 1; word[i]; i++)
        {
            if (word[i] != word[0])
            {
                word[j] = word[i];
                j++;
            }
        }
        word[j] = '\0';
    }
    return exit_code;
}

char string_array_to_string(char *result, string_array array, int n)
{
    for (int i = n - 2, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0; array[i][j]; j++, k++)
        {
            result[k] = array[i][j];
        }
        if (i)
            result[k] = ' ';
        else
            result[k] = '\0';
    }
    return EXIT_SUCCESS;
}

char remove_last_modify_words(char *result, string_array words, int n)
{
    char exit_code = (char) (n <= 1);
    for (int i = n - 2; i >= 0 && !exit_code; i--)
        exit_code = (char) ((exit_code + modify_word((char *) &words[i])) > 0);
    string_array_to_string(result, words, n);
    return exit_code;
}
