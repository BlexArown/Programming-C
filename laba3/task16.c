#include <stdio.h>
int main(){
    int a,i;
    printf("Insert a = ");
    scanf("%d", &a);
    for (i=2; i<a; i++){
        if (a%i==0) break;
    }
    if (i==a) puts("Good");
    return 0;
}