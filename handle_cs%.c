#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    int count = 0;
    char c;
    const char *str;

    va_list args;
    va_start(args, format);

    while (format && *format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
                case 's':
                    str = va_arg(args, const char *);
                    if (str) {
                        while (*str) {
                            count += write(1, str, 1);
                            str++;
                        }
                    }
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    break;
            }
        } else {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);
    return count;
}

