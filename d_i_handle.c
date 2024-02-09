#include "main.h"
int _printf(const char *format, ...)
{
	long int l = 0, m = 0, j, o, n;
	char *k;
	va_list i;

	va_start(i, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == 'i' || *(format + 1) == 'd')
				{
					m = handle_id((long)va_arg(i, int);
				}
		}
		else
		{
			write(1, format, 1);
			m++;
			format++;
		}
	}
	va_end(i);
	return (m);
}
