#include "main.h"
int handle(unsigned long b, int c, int a, int lo, int h)
{
	unsigned long l = 0, k, m = 0, n;
	char *j, *o = "0123456789ABCDEF", *p = "0123456789abcdef";
	k = b;
	b = (lo) ? (unsigned long)b : (h) ? (unsigned short)b : b;
	if (b == 0)
	{
		write(1, "0", 1);
		m = 1;
	}
	else
	{
		while (b != 0)
		{
			b /= c;
			l++;
		}
		if (a == 2)
		{
			j = malloc(sizeof(unsigned long) * l + 2);
                	if (j == NULL)
                        	return(-1);
		}
		else
		{
			j = malloc(sizeof(unsigned int) * l + 2);
			if (j == NULL)
				return(-1);
		}
		j[l] = '\0';
		while(l > 0)
		{
			l--;
			n = (k % c);
			j[l] = (a == 1 || a == 2) ? p[n] : (a == 4) ? o[n]: o[n];
			k /= c;
			m++;
		}
		if (a == 2)
			m += write(1, "0x", 2);
		if (a == 3)
			m += write(1, "0", 1);
		if (a == 4)
			m += write(1, "0X", 2);
		write(1, j, strlen(j));
		free(j);
		l = 0;
	}
	return (m);
}
