/**
 C клавиатуры вводятся величины сопротивлений трёх резисторов, R1, R2, R3,
 соединённых параллельно. Найти и вывести на экран сопротивление R всего
 соединения.
*/

#include <stdio.h>

int main()
{
    // Input
    double r1, r2, r3;
    scanf("%lf%lf%lf", &r1, &r2, &r3);

    // Calculations
    double r = 1 / (1 / r1 + 1 / r2 + 1 / r3);

    // Output
    printf("Total resistance: %.6lf", r);
    return 0;
}