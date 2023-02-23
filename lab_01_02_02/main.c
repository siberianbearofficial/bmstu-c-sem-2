/**
 Принять с клавиатуры координаты xa, ya, xb, yb, xc, yc треугольника abc
 на плоскости. Найти и вывести на экран периметр P треугольника.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    // Input
    double xa, ya, xb, yb, xc, yc;
    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);

    // Calculations
    double a = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
    double b = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
    double c = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    double p = a + b + c;

    // Output
    printf("Perimeter: %.6lf", p);
    return 0;
}