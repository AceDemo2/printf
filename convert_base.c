#include "main.h"
int handle(va_list i, int b, int f, int lo, int hs, int w)
{

        unsigned long l = 0, k, m = 0, n, b;
        void *d;
        char *j, *o = "0123456789ABCDEF", *p = "0123456789abcdef";
        if (f == "p")
        {
                d = va_arg(i, void *);
                if (d == NULL)
                {
                        m += write(1, "(nil)", 5);
                        va_end(i);
                        return (m);
                }
                else
                        b = (unsigned long)d;
        }
        else
        {
                if (lo)
                        b = va_arg(i, unsigned long);
                else if (hs)
                        b = (short)va_arg(i, int);
                else
                        b = va_arg(i, unsigned long);
        }
        k = b;
        if (b == 0)
        {
                write(1, "0", 1);
                m = 1;
        }
        else
        {
                while (b != 0)
                {
                        b /= c;
                        l++;
                }
                if (p == 2)
                {
                        j = malloc(sizeof(unsigned long) * l + 2);
                        if (j == NULL)
                        {
                                va_end(i);
                                return(-1);
                        }
                }
                else
                {
                        j = malloc(sizeof(unsigned int) * l + 2);
                        if (j == NULL)
                        {
                                va_end(i);
                                return(-1);
                        }
                }
                j[l] = '\0';
                while(l > 0)
                {
                        l--;
                        n = (k % c);
                        j[l] = (f == "X" || f == "X1") ? o[n]: p[n];
                        k /= c;
                        m++;
                }
                if (f == "p" || f == "x1")
                {
                        if (w)
                                m += padding(w, 2 + strlen(j));
                        m += write(1, "0x", 2);
                }
                if (a == "o1")
                {
                        if (w)
                                m += padding(w, 1 + strlen(j));
                        m += write(1, "0", 1);
                }
                if (a == "X1")
                {
                        if (w)
                                m += padding(w, 2 + strlen(j));
                        m += write(1, "0X", 2);
                }
                write(1, j, strlen(j));
                free(j);
                l = 0;
        }
        return (m);
}
