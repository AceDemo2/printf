#include "main.h"
int handle_R(char *r)
{

        int i = 0, j;
        char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
        char *c;

        if (r == NULL)
            return -1;
        while (r[i])
            i++;
        c = malloc(sizeof(char) * i + 1);
        if (c == NULL)
            return (-1);
        i = 0;
        while (r[i])
        {
            c[i] = r[i];
            i++;
        }
        c[i] = '\0';
        i = 0;
        while (c[i])
        {
                j = 0;
                while (a[j])
                {
                        if (c[i] == a[j])
                        {
                                c[i] = b[j];
                                break;
                        }
                        j++;
                }
                i++;
        }
        write(1, c, i);
        free(c);
        return (i);
}
