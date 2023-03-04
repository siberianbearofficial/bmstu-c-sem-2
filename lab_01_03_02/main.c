/**
 C клавиатуры вводятся величины сопротивлений трёх резисторов, R1, R2, R3,
 соединённых параллельно. Найти и вывести на экран сопротивление R всего
 соединения.
*/

#include <stdio.h>
#include <stdlib.h>

double total_resistance(double, double, double);

int main()
{
    char exit_code = EXIT_SUCCESS;

    // Input
    double r1, r2, r3;
    if (scanf("%lf%lf%lf", &r1, &r2, &r3) != 3 || r1 <= 0 || r2 <= 0 || r3 <= 0)
    {
        exit_code = EXIT_FAILURE;

        // Output
        printf("Error");
    }
    else
    {
        // Calculations
        double r = total_resistance(r1, r2, r3);

        // Output
        printf("Total resistance: %.6lf", r);
    }

    return exit_code;
}

double total_resistance(double r1, double r2, double r3)
{
    return 1 / (1 / r1 + 1 / r2 + 1 / r3);
}