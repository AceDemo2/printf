#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	char l = '%', *j;
	int m = 0, k, n = 0;
	va_list i;

	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(i, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			if (*(format + 1) == 'c')
			{
				k = va_arg(i, int);
                                write(1, &k, 1);
			}
			else if (*(format + 1) == 's')
			{
				j = va_arg(i, char *);
                                j = (j == NULL) ? "(null)" : j;
                                write(1, j, strlen(j));
			}
			else if (*(format + 1) == '%')
				write(1, &l, 1);
			else
			{
				write(1, format, 1);
				n = 1;
			}
			m = (*(format + 1) != 's') ? m + 1 : m + (int)strlen(j);
			format = (n == 1) ? format + 1 : format + 2;
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
