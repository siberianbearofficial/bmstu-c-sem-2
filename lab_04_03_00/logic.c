#include "logic.h"

int modify_word(char *);

int modify_word(char *word)
{
    if (word[0] != '\0')
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
    return EXIT_SUCCESS;
}

int remove_last_modify_words(char *result, string_array words, int n)
{
    char last_word[W_LEN];
    result[0] = '\0';
    if (!get_last_word(words, n, (char *) &last_word))
    {
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (strcmp(last_word, words[i]))
            {
                modify_word((char *) &words[i]);
                move_string_in_array(k, i, words);
                k++;
            }
        }
        reverse_string_array(words, k);
        string_array_to_string(result, words, k);
    }
    return (char) (n <= 1) || !*result;
}
