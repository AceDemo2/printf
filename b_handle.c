#include "main.h"
int handle_b(unsigned int b)
{
	unsigned int l = 0, k, m = 0;
	char *j;
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
			b /= 2;
			l++;
		}
		j = malloc(sizeof(unsigned int) * l);
		if (j == NULL)
		{
			return(-1);
		}
		j[l] = '\0';
		while(l > 0)
		{
			l--;
			j[l] = (k % 2) + '0';
			k /= 2;
			m++;
		}
		write(1, j, strlen(j));
		free(j);
		l = 0;
	}
	return (m);
}
