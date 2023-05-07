#include "string_array.h"

int move_string_in_array(int, int, string_array);

int is_delimiter(char);

int words_equal(const char *, const char *);

int move_string_in_array(int where_ind, int from_ind, string_array array)
{
    int i;
    for (i = 0; array[from_ind][i]; i++)
        array[where_ind][i] = array[from_ind][i];
    array[where_ind][i] = '\0';
    return EXIT_SUCCESS;
}

int remove_duplicates(string_array words, int *n)
{
    int k = 0;
    for (int i = 0; i < *n; i++)
    {
        int contains = 0;
        for (int j = 0; j < i && !contains; j++)
            if (words_equal(words[i], words[j]))
                contains = 1;
        if (!contains)
        {
            if (i != k)
                move_string_in_array(k, i, words);
            k++;
        }
    }
    (*n) = k;
    return EXIT_SUCCESS;
}

int string_array_contains(const char *word, string_array strings, int strings_count)
{
    int contains = 0;
    for (int i = 0; i < strings_count && !contains; i++)
        if (words_equal(word, strings[i]))
            contains = 1;
    return contains;
}

int is_delimiter(char d)
{
    char delim = 0;
    char delimiters[] = " ,;:-.!?\n";
    for (int i = 0; i < 9 && !delim; i++)
        delim = (char) (d == delimiters[i]);
    return delim;
}

int split_string(const char *str, string_array words, int *words_count)
{
    int exit_code = EXIT_SUCCESS;
    *words_count = 0;
    int k = 0;
    int word = 0;
    for (int i = 0; str[i] && !exit_code; i++)
    {
        if (is_delimiter(str[i]))
        {
            if (word)
            {
                if (k < W_LEN && *words_count < MAX_W)
                {
                    words[*words_count][k] = '\0';
                    word = 0;
                    k = 0;
                    (*words_count)++;
                }
            }
        }
        else
        {
            if (k >= W_LEN || *words_count >= MAX_W)
                exit_code = EXIT_FAILURE;
            else
            {
                words[*words_count][k] = str[i];
                k++;
                word = 1;
            }
        }
    }
    if (k && *words_count < MAX_W)
    {
        words[*words_count][k] = '\0';
        (*words_count)++;
    }
    return *words_count <= 0 || exit_code;
}

int words_equal(const char *w1, const char *w2)
{
    int equal = 1;
    int i = 0;
    while (w1[i] && w2[i] && equal)
    {
        if (w1[i] != w2[i])
            equal = 0;
        i++;
    }
    if (w1[i] || w2[i])
        equal = 0;
    return equal;
}
