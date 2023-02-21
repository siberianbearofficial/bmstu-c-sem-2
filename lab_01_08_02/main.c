/**
 Вводятся беззнаковое целое число длиной 4 байта a и целое число n. Числа вводятся в
 десятичной системе счисления. Необходимо циклически сдвинуть значение переменной a
 на n позиций влево. Результат вывести в двоичной системе счисления.
*/

#include <stdio.h>


void binary_output(unsigned long long int);


unsigned int move(unsigned int, int);


int main() {
    // Input
    unsigned int a;
    int n;
    scanf("%u%d", &a, &n);

    // Calculations
    a = move(a, n);

    // Output
    binary_output(a);
    return 0;
}


unsigned int move(unsigned int a, int n) {
    a = (a << n) | (a >> (32 - n));
    return a;
}


void binary_output(unsigned long long int dec) {
    unsigned long long int v = 2147483648;
    int insignificant_zeros = 1;

    printf("Result: ");

    for (int i = 1; i <= 32; i++) {
        if (dec >= v) {
            printf("1");
            dec -= v;
            insignificant_zeros = 0;
        } else if (insignificant_zeros == 0) {
            printf("0");
        }
        v /= 2;
    }
}