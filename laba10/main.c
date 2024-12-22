#include <stdio.h>
#include "triangle.h"

int main() {
    // Создаем массив треугольников
    Triangle triangles[3] = {
        init_triangle(3.0, 4.0, 5.0),
        init_triangle(6.0, 8.0, 10.0),
        init_triangle(7.0, 24.0, 25.0)
    };

    // Находим треугольник с наибольшей площадью
    Triangle largest = find_largest_area_triangle(triangles, 3);
    double largest_area = calculate_area(largest);

    printf("Треугольник с наибольшей площадью:\n");
    printf("Стороны: a = %.2f, b = %.2f, c = %.2f\n", largest.a, largest.b, largest.c);
    printf("Площадь: %.2f\n", largest_area);

    return 0;
}

