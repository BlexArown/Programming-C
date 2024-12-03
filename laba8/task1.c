#include <stdio.h>

float det2x2(float a, float b, float c, float d) {
    return a * d - b * c;
}

float det3x3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3) {
    return a1 * (b2 * c3 - b3 * c2) - a2 * (b1 * c3 - b3 * c1) + a3 * (b1 * c2 - b2 * c1);
}

void solve2x2() {
    float a1, a2, b1, b2, c1, c2;
    printf("Введите коэффициенты для уравнений:\n");
    printf("a1 * x + b1 * y = c1\n");
    printf("a2 * x + b2 * y = c2\n");
    printf("Введите a1, b1, c1: ");
    scanf("%f %f %f", &a1, &b1, &c1);
    printf("Введите a2, b2, c2: ");
    scanf("%f %f %f", &a2, &b2, &c2);

    float delta = det2x2(a1, b1, a2, b2);
    if (delta == 0) {
        printf("Система не имеет единственного решения (определитель равен 0).\n");
        return;
    }

    float delta_x = det2x2(c1, b1, c2, b2);
    float delta_y = det2x2(a1, c1, a2, c2);

    printf("Решение: x = %.2f, y = %.2f\n", delta_x / delta, delta_y / delta);
}

void solve3x3() {
    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
    printf("Введите коэффициенты для уравнений:\n");
    printf("a1 * x + b1 * y + c1 * z = d1\n");
    printf("a2 * x + b2 * y + c2 * z = d2\n");
    printf("a3 * x + b3 * y + c3 * z = d3\n");
    printf("Введите a1, b1, c1, d1: ");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
    printf("Введите a2, b2, c2, d2: ");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
    printf("Введите a3, b3, c3, d3: ");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);

    float delta = det3x3(a1, b1, c1, a2, b2, c2, a3, b3, c3);
    if (delta == 0) {
        printf("Система не имеет единственного решения (определитель равен 0).\n");
        return;
    }

    float delta_x = det3x3(d1, b1, c1, d2, b2, c2, d3, b3, c3);
    float delta_y = det3x3(a1, d1, c1, a2, d2, c2, a3, d3, c3);
    float delta_z = det3x3(a1, b1, d1, a2, b2, d2, a3, b3, d3);

    printf("Решение: x = %.2f, y = %.2f, z = %.2f\n", delta_x / delta, delta_y / delta, delta_z / delta);
}

int main() {
    int choice;
    printf("Выберите размерность системы:\n");
    printf("1. 2x2\n");
    printf("2. 3x3\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            solve2x2();
            break;
        case 2:
            solve3x3();
            break;
        default:
            printf("Неверный выбор. Завершение программы.\n");
    }

    return 0;
}

