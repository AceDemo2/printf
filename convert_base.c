#include "main.h"
int handle(va_list i, int c, int a, int lo, int hs, int w)
{

	unsigned long l = 0, k, m = 0, n, b;
	char *j, *o = "0123456789ABCDEF", *p = "0123456789abcdef";
	if (lo == 1)
		b = va_arg(i, unsigned long);
	if (hs == 1)
		b = (short)va_arg(i, int);
	else
		b = va_arg(i, unsigned long);
	k = b;
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
			{
				va_end(i);
                        	return(-1);
			}
		}
		else
		{
			j = malloc(sizeof(unsigned int) * l + 2);
			if (j == NULL)
			{
				va_end(i);
				return(-1);
			}
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
		{
			if (w)
				m += padding(w, 2 + strlen(j));
			m += write(1, "0x", 2);
		}
		if (a == 3)
		{
			if (w)
                                m += padding(w, 1 + strlen(j));
			m += write(1, "0", 1);
		}
		if (a == 4)
		{
			if (w)
                                m += padding(w, 2 + strlen(j));
			m += write(1, "0X", 2);
		}
		write(1, j, strlen(j));
		free(j);
		l = 0;
	}
	return (m);
}
