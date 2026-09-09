#include <stdio.h>
#include <stdlib.h>
int main()
{
int a = 70000;
short s = (short)a;
int neg = -10;
unsigned int u = (unsigned int)neg;
float f = 12.99;
int i = (int)f;
char str[] = "123abc";
int num = atoi(str);
printf("int -> short\n");
printf("Before: %d\nAfter : %hd\n\n", a, s);
printf("signed -> unsigned\n");
printf("Before: %d\nAfter : %u\n\n", neg, u);
printf("float -> int\n");
printf("Before: %.2f\nAfter : %d\n\n", f, i);
printf("string -> int\n");
printf("Before: %s\nAfter : %d\n", str, num);
return 0;
}
