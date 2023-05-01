// Ввести две строки. Для каждого слова из первой строки (повторяющиеся в
// этой же строке слова не обрабатываются) определить, входит ли оно во
// вторую строку. Программа должна вывести пары «слово yes|no». Каждая пара
// выводится на отдельной строке. Слова выводятся в том порядке, в котором
// они встретились в первой строке.

#include "main.h"

int main()
{
    char str1[S_LEN], str2[S_LEN];

    // Str1 input
    fgets(str1, S_LEN, stdin);

    // Str2 input
    fgets(str2, S_LEN, stdin);

    // Str1 words
    int words1_count;
    string_array words1;
    split_string(str1, words1, &words1_count);

    // Str2 words
    int words2_count;
    string_array words2;
    split_string(str2, words2, &words2_count);

    for (int i = 0; i < words1_count; i++)
    {
        if (string_array_contains(words1[i], words2, words2_count))
            printf("%s yes\n", words1[i]);
        else
            printf("%s no\n", words1[i]);
    }

    return EXIT_SUCCESS;
}