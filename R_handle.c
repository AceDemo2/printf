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
		i++;
	}
	m = write(1, r, strlen(r));
	return (m);
}
