/**
 Приняв с клавиатуры по концевому признаку (до первого отрицательного числа) элементы непустой последовательности
 неотрицательных чисел x, вычислить и вывести на экран значение g(x).
*/

#include <stdio.h>
#include <math.h>


double input_sequence_and_calculate_result();


int main() {
    // Input & Calculations
    double res = input_sequence_and_calculate_result();

    // Output
    printf("Result: %lf", res);
    return 0;
}


double input_sequence_and_calculate_result() {
    int n = 0;

    double sum = 0;
    double x;

    while (1) {
        scanf("%lf", &x);
        if (x < 0) break;
        n++;
        sum += sqrt(n + x);
    }

    double res;
    if (n == 0)
        res = 0;
    else
        res = 1. / n * sum;

    return res;
}