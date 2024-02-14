#include "main.h"
int handle_id(long j)
{
	long l = 0, m = 0, n, o;
	char *k;
	j = (lo) ? j : (hs) ? (short)j : j;
					if (j < 0)
					{
						m += write(1, "-", 1);
						j = -j;
						w--;;
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
					k = malloc(sizeof(char) * l + 1);
					if (k == NULL)
					{
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
					if (w)
                                		m += padding(w, strlen(k));
					write(1, k, strlen(k));
					free(k);
  l = 0;
  return (m);
}
					
