#include "main.h"
int handle_id(int j, int lo, int h, int w)
{
 long int o; 
	 int l = 0, m = 0, n;
	char *k;
	j = (lo) ? (long)j : (h) ? (short)j : j;
					if (j < 0)
					{
						m += write(1, "-", 1);
						j = -j;
					}
					else if (j == 0)
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
					k = malloc(l + 1);
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
					
