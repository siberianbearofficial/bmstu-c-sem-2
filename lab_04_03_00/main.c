// Для решения этой задачи нужно использовать функции стандартной библиотеки.
// Требуется написать программу, которая запрашивает у пользователя строку и
// разбивает оную на слова. В результате разбора строки должен быть сформирован
// массив слов.
// Из слов, отличных от последнего, составляется новая строка. Слова в
// результирующую строку помещаются в обратном порядке с одним пробелом в
// качестве разделителя. После последнего слова пробел не добавляется.
// Прежде, чем очередное слово помещается в результирующую строку, оно
// подвергается преобразованию:
// Удалить из слова все последующие вхождения первой буквы.
// Если результирующая строка не пустая, она выводится на экран следующим
// образом: printf("Result:␣%s\n", new_str);

#include "main.h"

int main()
{
    char str[S_LEN];

    // Str input
    fgets(str, S_LEN, stdin);

    // Str words
    int words_count;
    string_array words;
    split_string(str, words, &words_count);

    // Result
    char result_string[S_LEN];
    remove_last_modify_words((char *) &result_string, words, words_count);
    printf("Result: %s\n", result_string);

    // ahbshdfbaa fafhdfdghbajfuh sdjhsjhssjhsjs oiereireioeorei jifduhdifuhj  TODO: move this test to generator

    return EXIT_SUCCESS;
}