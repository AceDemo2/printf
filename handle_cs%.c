#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	char l = '%', *j = NULL;
	int m = 0, k, n = 0;
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
				break;
			case 's':
				j = (j == NULL) ? "(null)" : va_arg(i, char *);
				write(1, j, strlen(j));
				break;
			case '%':
				write(1, &l, 1);
				break;
			default:
				n = 1;
				write(1, format, 1);
				break;
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
