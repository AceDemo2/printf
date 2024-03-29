#include "main.h"
int handle_id(va_list i, int pl, int s, int lo, int hs, int w)
{
	long j;
	long l = 0, m = 0, n, o;
	char *k;
        
	if (lo)
        {
                j = va_arg(i, long);
        }
        else if (hs)
        {
                j = (short)va_arg(i, int);
        }
	else
	{
		j = va_arg(i, int);
	}
	if (j >= 0 && pl)
	{
		w--;
		m += write(1, "+", 1);
	}
	else if (j >= 0 && s && !pl)
	{
		w--;
		m += write(1, " ", 1);
	}
	else if (j < 0)
	{
		m += write(1, "-", 1);
		j = -1 * j;
		w--;
	}
	if (j == 0)
		l++;
	else
	{
		o = j;
		while (o != 0)
		{
			o = o / 10;
			l++;
		}
	}
	k = malloc(sizeof(unsigned long) * l + 2);
	if (k == NULL)
	{
		va_end(i);
		return (-1);
	}
	k[l] = '\0';
	n = l - 1;
	while (n >= 0)
	{
		k[n] = j % 10 + '0';
		m++;
		n--;
		j /= 10;
	}
	if (w > l)
        m += padding(w, strlen(k));
	write(1, k, strlen(k));
	free(k);
	return (m);
}
