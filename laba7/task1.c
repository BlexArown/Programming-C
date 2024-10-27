#include <stdio.h>
#include <ctype.h>

int main() {
    char input[256];
    printf("Введите предложение: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (i == 0 || (input[i - 1] == ' ')) {
            printf("?"); // Добавляем ?
        }
        printf("%c", input[i]);
    }

    return 0;
}