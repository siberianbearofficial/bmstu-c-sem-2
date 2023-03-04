/**
 С клавиатуры задаются координаты точек xq, yq, xr, yr отрезка qr
 и координаты произвольной точки xp, yp. Определить, не принадлежит
 или принадлежит точка отрезку, и вывести на экран 0 или 1 соответственно.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEGENERATE 2
#define EPS 0.000001

char point_belongs_segment(double, double, double, double, double, double);
char doubles_are_equal(double, double);

int main()
{
    char exit_code = EXIT_SUCCESS;

    // Input
    double xq, yq, xr, yr, xp, yp;
    printf("Enter coordinates: ");
    short rc = scanf("%lf%lf%lf%lf%lf%lf", &xq, &yq, &xr, &yr, &xp, &yp);

    if (rc == 6)
    {
        // Calculations
        char belongs = point_belongs_segment(xq, yq, xr, yr, xp, yp);

        if (belongs != DEGENERATE)
        {
            // Output
            printf("Point belongs to segment: %d", belongs);
        }
        else
            exit_code = EXIT_FAILURE;
    }
    else
    {
        exit_code = EXIT_FAILURE;
    }

    return exit_code;
}

char doubles_are_equal(double a, double b)
{
    return (char) (fabs(a - b) < EPS);
}

double distance(double xa, double ya, double xb, double yb)
{
    return sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
}

char point_belongs_segment(double xq, double yq, double xr, double yr, double xp, double yp)
{
    char belongs;
    double qp = distance(xq, yq, xp, yp);
    double rp = distance(xr, yr, xp, yp);
    double qr = distance(xq, yq, xr, yr);
    if (doubles_are_equal(qr, 0))
        belongs = DEGENERATE;
    else
        belongs = doubles_are_equal(qp + rp, qr);
    return belongs;
}