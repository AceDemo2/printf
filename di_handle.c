#include "main.h"
int handle_id(va_list i, int lo, int hs int w)
{
	void j;
	long l = 0, m = 0, n, o;
	char *k;
        
	if (lo == 1)
        {
                (long)j = va_arg(i, long);
        }
        else if (hs == 1)
        {
                (short)j = va_arg(i, int);
        }
        else
                j = (long)j;

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
					if (w)
                                		m += padding(w, strlen(k));
					write(1, k, strlen(k));
					free(k);
  l = 0;
  return (m);
}
					
