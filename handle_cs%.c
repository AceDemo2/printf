#include "main.h"
int _printf(const char *format, ...)
{       
	char *j;
        va_list i;
        va_start(i, format);
        while (*format)
        {
                if (*format == '%')
		{
			switch (*(format + 1))
			{
                        	case 'c':
                                	j = va_arg(i, int);
					write(1, j, 1);
					break;
				case 's':
					j = va_arg(i, char *);
					write(1, j, strlen(j));
					break;
				case '%':
					write(1, '%', 1);
					break;
				default:
					break;
			}
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(i);
}
