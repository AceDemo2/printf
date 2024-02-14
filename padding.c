#include "main.h"
int padding(int w, int l)
{
	int p, m = 0;

        p = w - l;
        while (p > 0)
        {
        	m += write(1, ' ', 1);
              	p--;
	}
	return (m);
}
