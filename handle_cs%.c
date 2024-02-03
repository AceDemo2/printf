#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	char l = '%', *j;
	int m = 0, k;
	va_list i;

	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
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
				write(1, format, 1);
				m++;
				format += 1;
				break;
			}
		}
		write(1, format, 1);
		m++;
		format++;
	}
	va_end(i);
	return (m);
}
