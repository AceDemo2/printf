#include "main.h"
#include <stdint.h>
int handle_p(void *p, int w)
{
	int m = 0;

	if (p == NULL)
		m += write(1, "(nil)", 5);
	else
		m += handle((unsigned long)p, 16, 2, 0, 0, w);
	return (m);
}
