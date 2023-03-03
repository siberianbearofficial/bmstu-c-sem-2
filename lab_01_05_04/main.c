/**
 Составить программу для печати разложения на простые множители заданного
 натурального числа n. Если n равно 1, печатать ничего не надо.
*/

#include <stdio.h>
#include <math.h>

void print_prime_factorization(unsigned short);

int main()
{
    char exit_code;

    // Input
    float n;
    printf("Input n: ");

    if (scanf("%f", &n))
    {
        if (n > 1 && (ceilf(n) == floorf(n)))
        {
            print_prime_factorization((unsigned short) n);
            exit_code = 0;
        }
        else if (n != 1)
            exit_code = 1;
    }
    else
    {
        exit_code = 1;
    }

    return exit_code;
}

void print_prime_factorization(unsigned short n)
{
    // Calculations & Output
    printf("Prime factorization: ");

    unsigned short div = 2;
    while (n > 1)
    {
        while (!(n % div))
        {
            printf("%u ", div);
            n /= div;
        }
        if (div == 2)
            div++;
        else
            div += 2;
    }
}
