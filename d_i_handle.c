#include "main.h"
int _printf(const char *format, ...)
{
	int l = 0, m = 0, j, o, n, p = 0;
	char *k;
	va_list i;

	va_start(i, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == 'i' || *(format + 1) == 'd')
				{
					j = va_arg(i, int);
					if (j < 0)
					{
						m += write(1, "-", 1);
						j = -j;
						p = 1;
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
					k = malloc(sizeof(char) * (p == 1) ? l + 2 : l + 1);
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
					write(1, k, strlen(k));
					free(k);
					format += 2;
				}
		}
		else
		{
			write(1, format, 1);
			m++;
		}
		format++;
	}
	va_end(i);
	return (m);
}
