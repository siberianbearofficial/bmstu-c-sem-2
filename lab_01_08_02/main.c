/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>
#include <math.h>

void binary_output(unsigned);
unsigned move(unsigned, char);

int main()
{
    char exit_code;

    // Input
    unsigned long a;
    float n;
    printf("Input a & n: ");

    if ((scanf("%lu%f", &a, &n) == 2) && (floorf(n) == ceilf(n)) && a < 4294967296)
    {
        // Calculations
        a = move(a, (char) ((int) n % 32));

        // Output
        binary_output(a);
        exit_code = 0;
    }
    else
    {
        printf("Error: bad input");
        exit_code = 1;
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
    char i = 32;
    while (i--)
    {
        printf("%d", (dec >> i) & 1);
    }
}