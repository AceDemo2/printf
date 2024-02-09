#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int m = 0, n = 0;
	va_list i;

	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(i, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == 'c')
				m += handle_c(va_arg(i, int));
			else if (*(format + 1) == 's')
				m += handle_s(va_arg(i, char *));
			else if (*(format + 1) == '%')
				m += write(1, "%", 1);
			else if (*(format + 1) == 'i' || *(format + 1) == 'd')
				m += handle_id((long)va_arg(i, int));
			else
			{
				m += write(1, format, 1);
				n = 1;
			}
			format = (n == 1) ? format + 1 : format + 2;
		}
		else
		{
			m += write(1, format, 1);
			format++;
		}
	}
	va_end(i);
	return (m);
}
