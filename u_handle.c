#include "main.h"
int handle(unsigned int b, int c)
{
	unsigned int i = 0, k = 0, l, m = 0;
	char * j;

	if (b == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	l = b;
	while (u != 0)
	{
		u /= c;
		i++;
	}
	j = malloc(sizeof(int) * i);
	if (j == NULL)
		return (-1);
	j[k] = '\0';
	while (k > 0)
	{
		k--;
		j[k] = l % c + '0';
		m++;
		l /= c;
	}
	write(1, j, strlen(j));
	free(j);
	return (m);
}
