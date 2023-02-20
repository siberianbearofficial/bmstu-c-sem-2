/**
 C клавиатуры вводятся величины сопротивлений трёх резисторов, R1, R2, R3,
 соединённых параллельно. Найти и вывести на экран сопротивление R всего
 соединения.
*/

#include <stdio.h>

int main() {
    // Input
    double R1, R2, R3;
    scanf("%lf%lf%lf", &R1, &R2, &R3);

    // Calculations
    double R = 1 / (1 / R1 + 1 / R2 + 1 / R3);

    // Output
    printf("Total resistance: %.6lf", R);
    return 0;
}