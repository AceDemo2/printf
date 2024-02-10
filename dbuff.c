#include "main.h"
void dbuff(int a, char *b)
{
	int i = 1;
	while (a != 0)
	{
		b[i] = a % 16;
		a /= 16;
		i--;
	}
}
