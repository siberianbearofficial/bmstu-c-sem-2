/**
 С клавиатуры задаются координаты точек xq, yq, xr, yr отрезка qr
 и координаты произвольной точки xp, yp. Определить, не принадлежит
 или принадлежит точка отрезку, и вывести на экран 0 или 1 соответственно.
*/

#include <stdio.h>

int point_belongs_segment();
double max();
double min();

int main() {
    // Input
    double xq, yq, xr, yr, xp, yp;
    scanf("%lf%lf%lf%lf%lf%lf", &xq, &yq, &xr, &yr, &xp, &yp);

    // Calculations
    int belongs = point_belongs_segment(xq, yq, xr, yr, xp, yp);

    // Output
    printf("Point belongs to segment: %d", belongs);
    return 0;
}

double max(double a, double b) {
    double max_a_b = a;
    if (b > a) max_a_b = b;
    return max_a_b;
}

double min(double a, double b) {
    double min_a_b = a;
    if (b < a) min_a_b = b;
    return min_a_b;
}

int point_belongs_segment(double xq, double yq, double xr, double yr, double xp, double yp) {
    double k_qr = (yr - yq) / (xr - xq);
    double k_qp = (yp - yq) / (xp - xq);

    int appropriate_line = k_qr == k_qp;
    int appropriate_x_value = min(xq, xr) <= xp && xp <= max(xq, xr);
    int appropriate_y_value = min(yq, yr) <= yp && yp <= max(yq, yr);
    int belongs = appropriate_line && appropriate_x_value && appropriate_y_value;

    return belongs;
}