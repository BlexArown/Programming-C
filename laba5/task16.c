#include <stdio.h>
void main(){
	int a,i;
	scanf("%d",&a);
	scanf("%d",&i);
	a = a ^ (1 << i);
	printf("%d", a);
}
