#include <stdio.h>
int main(){
    int s=0,n,a;
    printf("Insert a: \n");
    scanf("%d", &a);
for (n=2; n<a; n++) {
    if (a%n == 0) s++;
    }
if (s==0) puts("Good");
}