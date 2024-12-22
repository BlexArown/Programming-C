#include <stdio.h>

#define SQR(x) ((x) * (x))  // Добавлены скобки

int main() {
    int y = 5;
    int z = SQR(y + 1);
    printf("z = %d\n", z);  // Ожидается 36 (6*6)
    return 0;
}

