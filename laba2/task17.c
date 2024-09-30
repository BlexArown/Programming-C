#include <stdio.h>

int main() {
    int n=2,flag=0,b;
    printf("Insert b = ");
    scanf("%d", &b);
    while (b%n!=0) {
        n++;
        if (n==b) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("%d is a prime number.\n",b);
    } else {
        printf("%d is not a prime number.\n",b);
    }
    return 0;
}