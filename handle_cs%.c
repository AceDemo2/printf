#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    va_start(args, format);


    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    count += write(1, &va_arg(args, int), 1);
                    break;
                case 's':
                    count += write(1, va_arg(args, char *), 1);
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

