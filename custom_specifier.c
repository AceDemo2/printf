#include "main.h"
int custom_specifier(char *c)
{
	int m = 0, i = 0, j = 0, k = 0, l = 0;
	char *d;

	c = (c == NULL) ? "(nill)" : c;
	while (c[k])
	{
		if (c[k] < 32 || c[k] >= 127)
			l += 4;
		else
			l++;
		k++;
	}
	d = malloc(sizeof(char) * l + 1);
	if (d == NULL)
		return (-1);
	while (c[i])
	{
		if (c[i] < 32 || c[i] >= 127)
		{
			d[j] = '\\';
			d[j + 1] = 'x';
			dbuff((int)c[i], &d[j + 2]);
			j += 4;
		}
		else
		{
			d[j] = c[i];
			j++;
		}
		i++;
	}
	m += write(1, d, strlen(d));
	free(d);
	return (m);
}
