/**
 С клавиатуры задаётся время в секундах. Перевести в часы, минуты, секунды
 и вывести на экран.
*/

#include <stdio.h>

int main() {
    // Input
    long long int seconds;
    scanf("%lld", &seconds);

    // Calculations
    long long int hours = seconds / 60 / 60;
    long long int minutes = seconds / 60 % 60;
    seconds %= 60;

    // Output
    printf("Time: %lld : %lld : %lld", hours, minutes, seconds);
    return 0;
}