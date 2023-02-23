/**
 С клавиатуры задаются координаты точек xq, yq, xr, yr отрезка qr
 и координаты произвольной точки xp, yp. Определить, не принадлежит
 или принадлежит точка отрезку, и вывести на экран 0 или 1 соответственно.
*/

#include <stdio.h>

short point_belongs_segment(double, double, double, double, double, double);
double max(double, double);
double min(double, double);

int main()
{
    short exit_code = 0;

    // Input
    double xq, yq, xr, yr, xp, yp;
    printf("Enter coordinates: ");
    short rc = scanf("%lf%lf%lf%lf%lf%lf", &xq, &yq, &xr, &yr, &xp, &yp);

    if (rc == 6)
    {
        // Calculations
        short belongs = point_belongs_segment(xq, yq, xr, yr, xp, yp);

        if (belongs != -1)
        {
            // Output
            printf("Point belongs to segment: %d", belongs);
        }
        else
            exit_code = 1;
    }
    else
    {
        exit_code = 1;
    }

    return exit_code;
}

double max(double a, double b)
{
    double max_a_b = a;
    if (b > a)
        max_a_b = b;
    return max_a_b;
}

double min(double a, double b)
{
    double min_a_b = a;
    if (b < a)
        min_a_b = b;
    return min_a_b;
}

short point_belongs_segment(double xq, double yq, double xr, double yr, double xp, double yp)
{
    short belongs = 0;

    short is_rq_vertical_line = xr == xq;
    short is_pq_vertical_line = xp == xq;

    short appropriate_line;
    short appropriate_x_value;
    short appropriate_y_value;

    if (is_rq_vertical_line)
    {
        if (yr == yq)
        {
            belongs = -1;
        }
        else
        {
            appropriate_line = xr == xp;
            appropriate_y_value = min(yq, yr) <= yp && yp <= max(yq, yr);
            belongs = appropriate_line && appropriate_y_value;
        }
    }
    else if (!is_pq_vertical_line)
    {
        appropriate_line = ((yr - yq) / (xr - xq)) == ((yp - yq) / (xp - xq));
        appropriate_x_value = min(xq, xr) <= xp && xp <= max(xq, xr);
        appropriate_y_value = min(yq, yr) <= yp && yp <= max(yq, yr);
        belongs = appropriate_line && appropriate_x_value && appropriate_y_value;
    }

    return belongs;
}