#include "main.h"
void dbuff(int a, char *b)
{
	int i = 1, d;
	char *c = "0123456789ABCDEF";

	while (a != 0)
	{
		d = a % 16;
		b[i] = c[d];
		a /= 16;
		i--;
	}
	if (i == 0)
		b[i] = 0;
}
