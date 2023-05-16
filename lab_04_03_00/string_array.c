#include "string_array.h"

int append_word(const char *, string_array, int *);

int change_strings_in_array(int, int, string_array);

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
    }
    else
        exit_code = EXIT_FAILURE;
    return exit_code;
}

int split_string(char *str, string_array words, int *words_count)
{
    *words_count = 0;
    const char *delim = " ,;:-.!?\n";
    if (strrchr(str, '\n'))
    {
        char *token = strtok(str, delim);
        while (token)
            if (!append_word(token, words, words_count))
                token = strtok(NULL, delim);
            else
                token = NULL;
    }
    return (char) (*words_count <= 0);
}

int string_array_to_string(char *result, string_array array, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++, k++)
    {
        for (int j = 0; array[i][j]; j++, k++)
            result[k] = array[i][j];
        result[k] = ' ';
    }
    result[k - (k > 1 && result[k - 1] == ' ')] = '\0';  // TODO: try to simplify
    return EXIT_SUCCESS;
}

int move_string_in_array(int where_ind, int from_ind, string_array array)
{
    int i;
    for (i = 0; array[from_ind][i]; i++)
        array[where_ind][i] = array[from_ind][i];
    array[where_ind][i] = '\0';
    return EXIT_SUCCESS;
}

int change_strings_in_array(int i1, int i2, string_array array)
{
    char tmp[W_LEN];
    int i;
    for (i = 0; array[i1][i]; i++)
        tmp[i] = array[i1][i];
    tmp[i] = '\0';
    move_string_in_array(i1, i2, array);
    for (i = 0; tmp[i]; i++)
        array[i2][i] = tmp[i];
    array[i2][i] = '\0';
    return EXIT_SUCCESS;
}

int reverse_string_array(string_array array, int n)
{
    for (int i = 0; i < n / 2; i++)
        change_strings_in_array(i, n - i - 1, array);
    return EXIT_SUCCESS;
}

int get_last_word(string_array words, int n, char *last_word)
{
    if (n > 0)
    {
        int i;
        for (i = 0; words[n - 1][i]; i++)
            last_word[i] = words[n - 1][i];
        last_word[i] = '\0';
    }
    return (char) (n <= 0);
}
