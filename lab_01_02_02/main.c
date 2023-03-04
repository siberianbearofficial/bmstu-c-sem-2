/**
 Принять с клавиатуры координаты xa, ya, xb, yb, xc, yc треугольника abc
 на плоскости. Найти и вывести на экран периметр P треугольника.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(double, double, double, double);

int main()
{
    char exit_code = EXIT_SUCCESS;

    // Input
    double xa, ya, xb, yb, xc, yc;
    if (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
    {
        // Output
        exit_code = EXIT_FAILURE;
        printf("Error");
    }
    else
    {
        // Calculations
        double a = distance(xc, yc, xb, yb);
        double b = distance(xa, ya, xc, yc);
        double c = distance(xa, ya, xb, yb);
        double p = a + b + c;

        // Output
        printf("Perimeter: %.6lf", p);
    }

    return exit_code;
}

double distance(double xa, double ya, double xb, double yb)
{
    return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
}