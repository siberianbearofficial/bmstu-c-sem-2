// Ввести две строки. Для каждого слова из первой строки (повторяющиеся в
// этой же строке слова не обрабатываются) определить, входит ли оно во
// вторую строку. Программа должна вывести пары «слово yes|no». Каждая пара
// выводится на отдельной строке. Слова выводятся в том порядке, в котором
// они встретились в первой строке.

#include "main.h"

int main(void)
{
    char exit_code = EXIT_FAILURE;
    char str1[S_LEN], str2[S_LEN];

    if (!input_line(str1))
    {
        if (!input_line(str2))
        {
            int words1_count;
            string_array words1;
            if (!split_string(str1, words1, &words1_count))
            {
                int words2_count;
                string_array words2;
                if (!split_string(str2, words2, &words2_count))
                {
                    remove_duplicates(words1, &words1_count);
                    printf("Result: ");
                    for (int i = 0; i < words1_count; i++)
                    {
                        if (string_array_contains(words1[i], words2, words2_count))
                            printf("%s yes\n", words1[i]);
                        else
                            printf("%s no\n", words1[i]);
                    }
                    exit_code = EXIT_SUCCESS;
                }
            }
        }
    }

    return exit_code;
}
