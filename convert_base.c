#include "main.h"

int handle(va_list i, int b, char fo, int lo, int hs, int w, int h)
{
    unsigned long l = 0, k, m = 0, n, q;
    /*void *d;*/
    char *j, *o = "0123456789ABCDEF", *p = "0123456789abcdef", f[3];

    if (h)
        strcpy(f, (fo == 'o') ? "o1" : (fo == 'X') ? "X1" : (fo == 'x') ? "x1" : f);

    /*if (f[0] == 'p')
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
    }*/

        if (lo)
            q = va_arg(i, unsigned long);
        else if (hs)
            q = (short)va_arg(i, int);
        else
            q = va_arg(i, unsigned long);


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
        j = malloc(sizeof(unsigned long) * (l + 2));
        if (j == NULL)
        {
            va_end(i);
            return (-1);
        }
        j[l] = '\0';

        while (l > 0)
        {
            l--;
            n = (k % b);
            j[l] = (strcmp(f, "X") == 0 || strcmp(f, "X1") == 0) ? o[n] : p[n];
            k /= b;
            m++;
        }

        if (strcmp(f, "p") == 0 || strcmp(f, "x1") == 0)
        {
            if (w)
                m += padding(w, 2 + strlen(j));
            m += write(1, "0x", 2);
        }
        if (strcmp(f, "o1") == 0)
        {
            if (w)
                m += padding(w, 1 + strlen(j));
            m += write(1, "0", 1);
        }
        if (strcmp(f, "X1") == 0)
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
