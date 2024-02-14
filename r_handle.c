#include "main.h"
int handle_r(char *r, int w)
{
	int i = 0, j, l, m = 0;
	char *a, b;
	
	if (r == NULL)
		return (-1);
	j = strlen(r);
	a = malloc(sizeof(char) * j + 1);
	if (a == NULL)
		return (-1);
	l = j - 1;
	while (i <= j / 2)
	{
		b = r[i];
		a[i] = r[l];
		a[l] = b;
		i++;
		l--;
	}
	if (w)
        	m += padding(w, j);
	m += write(1, a, j);
	free(a);
	return (m);
}
