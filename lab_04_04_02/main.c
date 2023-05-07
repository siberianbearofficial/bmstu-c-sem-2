//Для представления даты выбрано следующее представление: «[D]D␣month␣YYYY»
//Месяц это одна из строк «january», «february», «march», «april», «may»,
//«june», «july», «august», «september», «october», «november», «december».
//Составные части даты могут разделяться произвольным количеством пробелов.
//Написание месяца не чувствительно к регистру символов.
//На вход программе подаётся произвольная строка. Строка может начинаться и
//заканчиваться произвольным количеством пробельных символов. Программа
//должна вывести только сообщение «YES», если в строке содержится правильная
//дата в указанном формате, и только «NO» — в противном случае. Обратите
//внимание, что проверить нужно не только валидность написания даты, но и
//валидность самой даты (например, дата «40 april 2010» правильная по
//написанию, но не по значению). Не забудьте про правила для високосных годов.

#include "main.h"

int main(void)
{
    char exit_code = EXIT_FAILURE;
    char str[S_LEN];
    if (!input_line(str))
    {
        if (!full_line(str))
        {
            string_array data;
            int data_len;
            if (!split_string(str, data, &data_len))
            {
                if (!valid_data(data, data_len))
                {
                    printf("YES");
                    exit_code = EXIT_SUCCESS;
                }
            }
        }
        if (exit_code)
        {
            printf("NO");
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}
