/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 32

void binary_output(unsigned);
unsigned move(unsigned, char);

int main()
{
    char exit_code = EXIT_SUCCESS;

    // Input
    unsigned a;
    float n;
    printf("Input a & n: ");

    if ((scanf("%u%f", &a, &n) == 2) && (floorf(n) == ceilf(n)) && ((int) n >= 0))
    {
        // Calculations
        a = move(a, (char) ((int) n % LENGTH));

        // Output
        binary_output(a);
    }
    else
    {
        exit_code = EXIT_FAILURE;
    }

    if (exit_code)
    {
        printf("Error: bad input");
    }

    return exit_code;
}

unsigned move(unsigned a, char n)
{
    a = (a << n) | (a >> (LENGTH - n));
    return a;
}

void binary_output(unsigned dec)
{
    printf("Result: ");
    for (char i = LENGTH - 1; i >= 0; i--)
    {
        printf("%u", (dec >> i) & 1);
    }
}
