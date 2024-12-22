#include <stdio.h>

#define SQR(x) x * x // разворачивается как y+1 * y+1, а не (y+1)*(y+1)
int main() {
int y = 5;
int z = SQR(y + 1);
printf("z = %d\n", z);
return 0;
}

