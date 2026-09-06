#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
int a = 70000;
int neg = -10;
float f = 12.99;
char str[] = "123abc";
if (a < SHRT_MIN || a > SHRT_MAX)
printf("Rejected: %d is out of short range\n", a);
else
printf("%hd\n", (short)a);
if (neg < 0)
printf("Rejected: negative value cannot be converted safely\n");
else
printf("%u\n", (unsigned int)neg);
printf("float -> int\n");
printf("Before: %.2f\nAfter : %d\n", f, (int)f);
char *end;
long value = strtol(str, &end, 10);
if (*end != '\0')
printf("Rejected: invalid numeric string '%s'\n", str);
else
printf("%ld\n", value);
return 0;
}