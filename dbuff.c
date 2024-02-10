#include "main.h"
void dbuff(int a, char *b)
{
	int i = 2, d;
	char *c = "0123456789ABCDEF";

	while (i > 0)
	{
		i--;
		d = a % 16;
		b[i] = c[d];
		a /= 16;
	}
}
