#include <stdio.h>
#include <math.h>
#include "triangle.h"

// Функция инициализации треугольника
Triangle init_triangle(double a, double b, double c) {
    Triangle t = {a, b, c};
    return t;
}

// Функция расчета площади треугольника по формуле Герона
double calculate_area(Triangle t) {
    double p = (t.a + t.b + t.c) / 2.0; // Полупериметр
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

// Функция нахождения треугольника с наибольшей площадью
Triangle find_largest_area_triangle(Triangle triangles[], int size) {
    Triangle max_triangle = triangles[0];
    double max_area = calculate_area(triangles[0]);
    for (int i = 1; i < size; i++) {
        double area = calculate_area(triangles[i]);
        if (area > max_area) {
            max_area = area;
            max_triangle = triangles[i];
        }
    }
    return max_triangle;
}

