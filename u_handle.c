#include "main.h"
int handle_u(unsigned int u)
{
	unsigned int i = 0, j, k = 0, l, m = 0;

	if (u == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	l = u;
	while (u != 0)
	{
		u /= 10;
		i++;
	}
	j = malloc(sizeof(int) * i);
	if (j == NULL)
		return (-1);
	j[k] = '\0';
	while (k > 0)
	{
		k--;
		j[k] = l % 10 + '0';
		m++;
		l /= 10;
	}
	write(1, j, strlen(j));
	free(j);
	return (m);
}
