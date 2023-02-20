/**
 Составить программу для печати разложения на простые множители заданного
 натурального числа n.Если n равно 1, печатать ничего не надо.
*/

#include <stdio.h>

int main() {
    // Input
    long long int n;
    scanf("%lld", &n);

    // Calculations & Output
    printf("Prime factorization: ")
    if (n != 1) {
        long long int div = 2;
        while (n > 1) {
            while (n % div == 0) {
                printf("%lld ", div);
                n = n / div;
            }
            if (div == 2) div++;
            else div += 2;
        }
    }

    return 0;
}