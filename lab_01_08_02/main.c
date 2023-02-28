/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>

void binary_output(unsigned);
unsigned move(unsigned, char);

int main()
{
    char exit_code = 0;

    // Input
    unsigned a;
    int n;
    printf("Input a & n: ");

    if (scanf("%u%d", &a, &n) == 2)
    {
        // Calculations
        a = move(a, (char) (n % 32));

        // Output
        binary_output(a);
    }
    else
    {
        exit_code = 1;
    }

    if (exit_code)
    {
        printf("Error: bad input");
    }

    return exit_code;
}

unsigned move(unsigned a, char n)
{
    a = (a << n) | (a >> (32 - n));
    return a;
}

void binary_output(unsigned dec)
{
    printf("Result: ");
    for (char i = 31; i >= 0; i--)
    {
        printf("%u", (dec >> i) & 1);
    }
}