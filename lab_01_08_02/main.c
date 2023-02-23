/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>

short binary_output(unsigned long);
unsigned move(unsigned, int);

int main()
{
    short exit_code;

    // Input
    unsigned a;
    int n;
    printf("Input a & n: ");
    short rc = scanf("%u%d", &a, &n);

    if (rc == 2)
    {
        // Calculations
        a = move(a, n);

        // Output
        exit_code = binary_output(a);
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

unsigned move(unsigned a, int n)
{
    a = (a << n) | (a >> (32 - n));
    return a;
}

short binary_output(unsigned long dec)
{
    short exit_code = 0;

    if (dec > 0)
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
            }
            else if (insignificant_zeros == 0)
            {
                printf("0");
            }
            v /= 2;
        }
    }
    else
    {
        exit_code = 1;
    }

    return exit_code;
}