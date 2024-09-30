#include <stdio.h>

int main() {
    int n1,n2,i;
    printf("Insert n1 = ");
    scanf("%d", &n1);
    printf("Insert n2 = ");
    scanf("%d", &n2);
    for (int i = n1; i>0; i--) {
        if (n1 % i == 0 && n2 % i == 0) {
            printf("SCD of %d and %d is %d\n",n1,n2,i);
            break;
        }
    }
}