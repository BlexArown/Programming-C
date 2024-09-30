#include <stdio.h>

int main() {
    int a,b,n;
    printf("Insert a = ");
    scanf("%d", &a);
    printf("Insert b = ");
    scanf("%d", &b);
    for (n = a; n%a!=0 || n%b!=0; n++) {
    }
    printf("The first number that is divisible by %d and %d: %d\n",a,b,n);
    return 0;
}