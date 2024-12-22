#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct {
    double a;
    double b;
    double c;
} Triangle;

// Прототипы функций
Triangle init_triangle(double a, double b, double c);
double calculate_area(Triangle t);
Triangle find_largest_area_triangle(Triangle triangles[], int size);

#endif // TRIANGLE_H

