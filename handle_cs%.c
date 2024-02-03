#include "main.h"
int _printf(const char *format, ...)
{       
	char *j;
	char l = '%';
        int k, m = 0;
	va_list i;
	va_start(i, format);
	while (*format)
        {
		if (*format == '%')
		{
			switch (*(format + 1))
			{
				case 'c':
                                	k = va_arg(i, int);
					write(1, &k, 1);
					m++;
					break;
				case 's':
					j = va_arg(i, char *);
					write(1, j, strlen(j));
					m += strlen(j);
					break;
				case '%':
					write(1, l, 1);
					m++;
					break;
				default:
					break;
			}
		}
		else
			write(1, format, 1);
			m++;
		format++;
	}
	va_end(i);
	return (m);
}
