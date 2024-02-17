#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
        int m = 0, l, pl, s, h, lo, hs, w;
        char* p;
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
                        k = "+ #lh0123456789";
                        l = 0;
                        pl = 0;
                        s = 0;
                        h = 0;
                        lo = 0;
                        hs = 0;
                        w = 0;
                        /*w1 = 0;
                        rd = 0;*/
                        while (k[l] && *format)
                        {
                                if (*(format) == k[l])
                                {
                                        if (*format == '+')
                                                pl++;
                                        else if (*format == ' ')
                                                s++;
                                        else if (*format == '#')
                                                h++;
                                        else if (*format == 'l')
                                                lo++;
                                        else if (*format == 'h')
                                                hs++;
                                        else if (*format >= '0' || *format <= '9')
                                        {
                                                w = w * 10 + (*format - '0');
                                                /*w1++;*/
                                        }
                                        format++;
                                        l = 0;
                                }
                                else
                                        l++;
                        }
                        if (h)
                                p = (*(format) == 'o') ? "o1" : (*(format) == 'X') ? "X1" : "x1";
                        else
                                p = (*(format) == 'X') ? "X" : ;
                        /*rd = pl + s + h + lo + hs + w1;*/
                        if (*format == '\0')
                        {
                                va_end(i);
                                return (-1);
                        }
                        if (*(format) == 'c')
                        {
                                m += handle_c(va_arg(i, int), w);
                        }
                        else if (*(format) == 's')
                                m += handle_s(va_arg(i, char *), w);
                        else if (*(format) == '%')
                                m += write(1, "%", 1);
                        else if (*(format) == 'i' || *(format) == 'd')
                        {
                                m += handle_id(i, pl, s, lo, hs, w);
                        }
                        else if (*(format) == 'b')
                                m += handle(i, 2, format, lo, hs, w);
                        else if (*(format) == 'u')
                                m += handle(i, 10, format, lo, hs, w);
                        else if (*(format) == 'o')
                                m += handle(i, 8, format, lo, hs, w);
                        else if (*(format) == 'X')
                                m += handle(i, 16, format, lo, hs, w);
                        else if (*(format) == 'x')
                                m += handle(i, 16, format, lo, hs, w);
                        else if (*(format) == 'S')
                                m += custom_specifier(va_arg(i, char *), w);
                        else if (*(format) == 'p')
                                m += handle(i, format, 2, 0, 0, w);
                        else if (*(format) == 'r')
                                m += handle_r(va_arg(i, char *), w);
                        else if (*(format) == 'R')
                                m += handle_R(va_arg(i, char *), w);
                        else
                        {

                                format -= 2;
                                m += write(1, format, 1);
                        }
                        format++;
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
