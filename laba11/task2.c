#include <stdio.h>

typedef struct
{
char str[3];
int num;
} NumberRepr; // массив очень мал, так как символов больше 3

void format(NumberRepr* number)
{
sprintf(number->str, "%3d", number->num); // ограничим размер через snprintf
}
int main()
{
NumberRepr number = { .num = 1025 };
format(&number);
printf("str: %s\n", number.str);
printf("num: %d\n", number.num);
return 0;
}

