#include "main.h"
int specifiers(char s, va_list i)
{
			if (*(format + 1) == 'c')
                                m += handle_c(va_arg(i, int));
                        else if (*(format + 1) == 's')
                                m += handle_s(va_arg(i, char *));
                        else if (*(format + 1) == '%')
                                m += write(1, "%", 1);
                        else if (*(format + 1) == 'i' || *(format + 1) == 'd')
                                m += handle_id((long)va_arg(i, int));
                        else if (*(format + 1) == 'b')
                                m += handle(va_arg(i, unsigned int), 2);
                        else if (*(format + 1) == 'u')
                                m += handle(va_arg(i, unsigned int), 10);
return (m);
}
