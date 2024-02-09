#include "main.h"
int _printf(const char *format, ...)
{
	int l, m = 0, j, o;
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
					k[l + 1] = '\0';
					while (l >= 0)
					{
						k[l] = j % 10 + '0';
						m++;
						l--;
						j /= 10;
					}
					write(1, k, l + 1);
					free(k);
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
