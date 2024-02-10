#include "main.h"
int handle_R(char *r)
{
	int i = 0, j, m;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "n0pqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (r[i])
	{
		j = 0;
		while (a[j])
		{
			if (r[i] == a[j])
			{
				r[i] = b[j];
				break;
			}
			j++;
		}
		if (!a[j])
		{
			j = 0;
			i++;
			continue;
		}
		i++;
	}
	m = write(1, r, strlen(r));
	return (m);
}
