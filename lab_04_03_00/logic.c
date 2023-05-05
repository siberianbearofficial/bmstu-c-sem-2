#include "logic.h"

char string_array_to_string(char *, string_array, int);

char append_word(const char *, string_array, int *);

char modify_word(char *);

char string_array_to_string(char *, string_array, int);

char get_last_word(string_array, int, char *);

char append_word(const char *word, string_array array, int *n)
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

char split_string(char *str, string_array words, int *words_count)
{
    *words_count = 0;
    const char *delim = " ,;:-.!?\n";
    if (strrchr(str, '\n'))
    {
        char *token = strtok(str, delim);
        do
            if (!append_word(token, words, words_count))
                token = strtok(NULL, delim);
        while (token);
    }
    return (char) (*words_count <= 0);
}

char modify_word(char *word)
{
    char exit_code = EXIT_FAILURE;
    if (word[1] != '\0')
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
        exit_code = EXIT_SUCCESS;
    }
    return exit_code;
}

char string_array_to_string(char *result, string_array array, int n)
{
    int k = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (array[i][0])
        {
            for (int j = 0; array[i][j]; j++, k++)
                result[k] = array[i][j];
            result[k] = ' ';
            k++;
        }
    }
    result[k - (k > 1 && result[k - 1] == ' ')] = '\0';
    return EXIT_SUCCESS;
}

char get_last_word(string_array words, int n, char *last_word)
{
    int i;
    for (i = 0; words[n - 1][i]; i++)
        last_word[i] = words[n - 1][i];
    last_word[i] = '\0';
    return EXIT_SUCCESS;
}

char remove_last_modify_words(char *result, string_array words, int n)
{
    char exit_code = (char) (n <= 1);
    char last_word[W_LEN];
    get_last_word(words, n, (char *) &last_word);
    for (int i = n - 2; i >= 0 && !exit_code; i--)
        if (strcmp(last_word, words[i]))
            exit_code = (char) ((exit_code + modify_word((char *) &words[i])) > 0);
        else
            words[i][0] = '\0';
    string_array_to_string(result, words, n);
    return exit_code;
}
