#include "logic.h"

int is_delimiter(char);

int words_equal(const char *, const char *);

int is_delimiter(char d)
{
    char delim = 0;
    char delimiters[] = " ,;:-.!?\n";
    for (int i = 0; i < 9 && !delim; i++)
    {
        if (d == delimiters[i])
        {
            delim = 1;
        }
    }
    return delim;
}

int split_string(const char *str, string_array words, int *words_count)
{
    *words_count = 0;
    int i = 0;
    int k = 0;
    int word = 0;
    while (str[i])
    {
        if (is_delimiter(str[i]))
        {
            if (word)
            {
                words[*words_count][k] = '\0';
                word = 0;
                k = 0;
                (*words_count)++;
            }
        }
        else
        {
            words[*words_count][k] = str[i];
            k++;
            word = 1;
        }
        i++;
    }
    if (k)
    {
        words[*words_count][k] = '\0';
        (*words_count)++;
    }
    return *words_count > 0;
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

int string_array_contains(const char *word, string_array strings, int strings_count)
{
    int contains = 0;
    for (int i = 0; i < strings_count && !contains; i++)
    {
        if (words_equal(word, strings[i]))
        {
            contains = 1;
        }
    }
    return contains;
}