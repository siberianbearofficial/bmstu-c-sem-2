/**
 Составить программу для печати разложения на простые множители заданного
 натурального числа n.Если n равно 1, печатать ничего не надо.
*/

#include <stdio.h>

void print_prime_factorization(long);

int main()
{
    short exit_code = 0;

    // Input
    long n;
    printf("Input n: ");
    short rc = scanf("%ld", &n);

    if (rc == 1 && n > 1)
    {
        print_prime_factorization(n);
    }
    else if (n < 1)
    {
        exit_code = 1;
    }

    return exit_code;
}

void print_prime_factorization(long n)
{
    // Calculations & Output
    printf("Prime factorization: ");

    long div = 2;
    while (n > 1)
    {
        while (n % div == 0)
        {
            printf("%ld ", div);
            n /= div;
        }
        if (div == 2)
            div++;
        else
            div += 2;
    }
}