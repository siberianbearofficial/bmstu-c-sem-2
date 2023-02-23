/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>

char binary_output(unsigned);
unsigned move(unsigned, int);

int main()
{
    char exit_code;

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

char binary_output(unsigned dec)
{
    char exit_code = 0;

    if (dec > 0)
    {
        unsigned char sym;
        char insignificant_zeros = 1;
        printf("Result: ");
        for (char i = 31; i >= 0; i--)
        {
            sym = (dec >> i) & 1;
            if (sym)
                insignificant_zeros = 0;
            if (!insignificant_zeros)
                printf("%u", sym);
        }
    }
    else
    {
        exit_code = 1;
    }

    return exit_code;
}