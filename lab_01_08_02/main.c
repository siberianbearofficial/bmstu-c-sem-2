/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>

void binary_output(unsigned long);
unsigned int move(unsigned int, int);

int main()
{
    short exit_code = 0;

    // Input
    unsigned int a;
    int n;
    printf("Input a & n: ");
    short rc = scanf("%u%d", &a, &n);

    if (rc == 2)
    {
        // Calculations
        a = move(a, n);

        // Output
        binary_output(a);
    } else
    {
        exit_code = 1;
    }

    return exit_code;
}

unsigned int move(unsigned int a, int n)
{
    a = (a << n) | (a >> (32 - n));
    return a;
}

void binary_output(unsigned long dec)
{
    unsigned long v = 2147483648;
    short insignificant_zeros = 1;

    printf("Result: ");

    for (short i = 1; i <= 32; i++)
    {
        if (dec >= v)
        {
            printf("1");
            dec -= v;
            insignificant_zeros = 0;
        } else if (insignificant_zeros == 0)
        {
            printf("0");
        }
        v /= 2;
    }
}