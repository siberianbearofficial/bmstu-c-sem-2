// Найти первый и второй максимумы последовательности (возможно совпадающие).

#include "main.h"

int main(void)
{
    int exit_code;
    int max_1, max_2;
    if (!(exit_code = process(stdin, &max_1, &max_2)))
        printf("%d %d\n", max_1, max_2);
    return exit_code;
}
