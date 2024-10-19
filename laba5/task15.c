#include <stdio.h>

int main(){
	int x,y,i,j;
	printf("Insert x:");
	scanf("%d", &x);
	printf("Insert y:");
	scanf("%d", &y);
	printf("Insert i:");
	scanf("%d", &i);
	printf("Insert j:");
	scanf("%d", &j);
	// Извлекаем i-й бит из x и сдвигаем его на j-ю позицию
	int bit_i = (x >> i) &1; // Получаем i+й бит из x
	y = (y & ~(1 << j)) | (bit_i << j); // Очищаем j-ю позицию в y и устанавливаем бит
	printf("Результат: %d\n", y);
	return 0;
}
