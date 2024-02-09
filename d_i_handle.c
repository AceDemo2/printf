#include "main.h"
int _printf(const char *format, ...)
{
	int m = 0;
	va_list i;

	va_start(i, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == 'i' || *(format + 1) == 'd')
				{
					format += 2;
					m += handle_id((long)va_arg(i, int));
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
