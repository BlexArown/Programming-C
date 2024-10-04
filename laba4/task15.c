#include <stdio.h>

int main() {
    char letters[] = {'F', 'E', 'D', 'C', 'B', 'C'};
    int string = 6,i,j;

    for (i = 0; i < string; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < string - i; j++) {
            printf("%c", letters[i]);
        }
        printf("\n");
    }

    return 0;
}