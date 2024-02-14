nclude "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
        int m = 0, l, pl, s, p, h, lo, hs, w;
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
                        while (k[l] && *format)
                        {
                                if (*(format) == k[l])
                                {
                                        if (*format == '+')
                                                pl = 1;
                                        else if (*format == ' ')
                                                s = 1;
                                        else if (*format == '#')
                                                h = 1;
                                        else if (*format == 'l')
                                                lo = 1;
                                        else if (*format == 'h')
                                                hs = 1;
                                        else if (*format >= '0' || *format <= '9')
                                                w = w * 10 + *format;
                                        format++;
                                        l = 0;
                                }
                                else
                                        l++;
                        }
                        if (h == 1)
                                p = (*(format) == 'o') ? 3 : (*(format) == 'X') ? 4 : 2;
                        else
                                p = (*(format) == 'o') ? 1 : 0;
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
                                m += handle(i, 2, 0, lo, hs, w);
                        else if (*(format) == 'u')
                                m += handle(i, 10, 0, lo, hs, w);
                        else if (*(format) == 'o')
                                m += handle(i, 8, p, lo, hs, w);
                        else if (*(format) == 'X')
                                m += handle(i, 16, p, lo, hs, w);
                        else if (*(format) == 'x')
                                m += handle(i, 16, p, lo, hs, w);
                        else if (*(format) == 'S')
                                m += custom_specifier(va_arg(i, char *), w);
                        else if (*(format) == 'p')
                                m += handle((i, 16, 2, 0, 0, w);
                        else if (*(format) == 'r')
                                m += handle_r(va_arg(i, char *), w);
                        else if (*(format) == 'R')
                                m += handle_R(va_arg(i, char *), w);
                        else
                        {
                                format--;
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
