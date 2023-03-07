/**
 С клавиатуры задаётся время в секундах. Перевести в часы, минуты, секунды
 и вывести на экран.
*/

#include <stdio.h>
#include <stdlib.h>

long long int get_hours(long long int);
long long int get_minutes(long long int);
long long int get_seconds(long long int);

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
        // Calculations
        long long int hours = get_hours(seconds);
        long long int minutes = get_minutes(seconds);
        seconds = get_seconds(seconds);

        // Output
        printf("Time: %lld : %lld : %lld", hours, minutes, seconds);
    }

    return exit_code;
}

long long int get_hours(long long int seconds)
{
    return seconds / 60 / 60;
}

long long int get_minutes(long long int seconds)
{
    return seconds / 60 % 60;
}

long long int get_seconds(long long int seconds)
{
    return seconds % 60;
}