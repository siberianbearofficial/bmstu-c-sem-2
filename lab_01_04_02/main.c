/**
 С клавиатуры задаётся время в секундах. Перевести в часы, минуты, секунды
 и вывести на экран.
*/

#include <stdio.h>
#include <stdlib.h>

void print_formatted(long long int);

int main()
{
    char exit_code = EXIT_SUCCESS;

    // Input
    long long int seconds;
    if (scanf("%lld", &seconds) != 1 || seconds < 0)
    {
        exit_code = EXIT_FAILURE;

        // Output
        printf("Error");
    }
    else
    {
        print_formatted(seconds);
    }

    return exit_code;
}

void print_formatted(long long int seconds)
{
    // Calculations
    long long int hours = seconds / 60 / 60;
    long long int minutes = seconds / 60 % 60;
    seconds %= 60;

    // Output
    printf("Time: %lld : %lld : %lld", hours, minutes, seconds);
}