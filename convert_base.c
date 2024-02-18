#include "main.h"
int handle(va_list i, int b, char fo, int lo, int hs, int w, int h)
{

        unsigned long l = 0, k, m = 0, n, q;
        void *d;
        char *j, *o = "0123456789ABCDEF", *p = "0123456789abcdef", *f;
        *f = fo;
        if (h)
                *f = (fo == 'o') ? "o1" : (fo == 'X') ? "X1" : (fo == 'X') ? "x1" : *f;
        if (*f == "p")
        {
                d = va_arg(i, void *);
                if (d == NULL)
                {
                        m += write(1, "(nil)", 5);
                        va_end(i);
                        return (m);
                }
                else
                        q = (unsigned long)d;
        }
        else
        {
                if (lo)
                        q = va_arg(i, unsigned long);
                else if (hs)
                        q = (short)va_arg(i, int);
                else
                        q = va_arg(i, unsigned long);
        }
        k = q;
        if (q == 0)
        {
                write(1, "0", 1);
                m = 1;
        }
        else
        {
                while (q != 0)
                {
                        q /= b;
                        l++;
                }
                if (*f == "p")
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
                        n = (k % b);
                        j[l] = (*f == "X" || *f == "X1") ? o[n]: p[n];
                        k /= b;
                        m++;
                }
                if (*f == "p" || *f == "x1")
                {
                        if (w)
                                m += padding(w, 2 + strlen(j));
                        m += write(1, "0x", 2);
                }
                if (*f == "o1")
                {
                        if (w)
                                m += padding(w, 1 + strlen(j));
                        m += write(1, "0", 1);
                }
                if (*f == "X1")
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
