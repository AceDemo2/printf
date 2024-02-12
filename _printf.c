#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int m = 0, l = 0, j, o = 0, n = 0, p;
	va_list i;
	char *k;

	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(i, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			k = "+ #";
			l = 0;
			while (k[l] && *format)
			{
				if (*(format) == k[l])
				{
					j = (o == 1) ? j : va_arg(i, int);
					o = 1;
					if (*format == ' ')
					{
						if (j >= 0 && n == 0)
						{
							m += write(1, format, 1);
							format++;
							l = 0;
						}
						else if (j <= 0 || j >= 0)
						{
							format++;
							l = 0;
						}
						else (*format)
						{
							format++;
							l = 0;
						}
					}
					else if (*format == '+' && j >= 0)
					{
						m += write(1, format, 1);
						format++;
						l = 0;
						n = 1;
					}
					else if (*format == '#')
					{
						format++;
						p = (*(format) == 'o') ? 3 : (*(format) == 'X') ? 4 : 2;
						break;
					}
					else
					{
						format++;
						l = 0;
					}
				}
				else
				{
					l++;
				}
			}
			n = 0;
			if (*(format) == 'c')
			{
				if (o == 1)
					m += handle_c(j);
				else
					m += handle_c(va_arg(i, int));
			}
			else if (*(format) == 's')
				m += handle_s(va_arg(i, char *));
			else if (*(format) == '%')
				m += write(1, "%", 1);
			else if (*(format) == 'i' || *(format) == 'd')
			{	
	       			if (o == 1)
                                        m += handle_id((long)j);
                                else
                                        m += handle_id((long)va_arg(i, int));
			}
			else if (*(format) == 'b')
				m += handle(va_arg(i, unsigned int), 2, 0);
			else if (*(format) == 'u')
				m += handle(va_arg(i, unsigned int), 10, 0);
			else if (*(format) == 'o')
			{
				if (o == 1)
					m += handle((unsigned int)j, 8, p);
				else
					m += handle(va_arg(i, unsigned int), 8, 0);
			}
			else if (*(format) == 'X')
			{
				if (o == 1)
                                        m += handle((unsigned int)j, 16, p);
                                else
					m += handle(va_arg(i, unsigned int), 16, 0);
			}
			else if (*(format) == 'x')
			{
				if (o == 1)
                                        m += handle((unsigned int)j, 16, p);
                                else
					m += handle(va_arg(i, unsigned int), 16, 0);
			}
			else if (*(format) == 'S')
				m += custom_specifier(va_arg(i, char *));
			else if (*(format) == 'p')
				m += handle_p(va_arg(i, void *));
			else if (*(format) == 'r')
				m += handle_r(va_arg(i, char *));
			else if (*(format) == 'R')
				m += handle_R(va_arg(i, char *));
			else
			{
				format--;
				m += write(1, format, 1);
			}
			if (*format == '\0')
			{
				va_end(i);
				return (-1);
			}
			format++;
			o = 0;
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
