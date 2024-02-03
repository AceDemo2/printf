#include "main.h"
int _printf(const char *format, ...)
{       
	char *j;
	char l = '%';
        int k, m = 0, n = 0;
	va_list i;
	if (format == NULL)
		return (-1);
	va_start(i, format);
	while (*format)
        {
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case 'c':
                                	k = va_arg(i, int);
					write(1, &k, 1);
					m++;
					format += 2;
					break;
				case 's':
					j = va_arg(i, char *);
					if (j == NULL)
						j = "(null)";
					write(1, j, strlen(j));
					m += strlen(j);
					format += 2;
					break;
				case '%':
					write(1, &l, 1);
					m++;
					format += 2;
					break;
				default:
					write(1, (format), 1);
					m++;
					format += 1;
					break;
			}
		}
		else if (*(format) == '%' && *(format + 1) == '\0')
			return (-1);
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
