#include "main.h"
int handle_p(void *p)
{
	int m = 0;
	unsigned int a = (unsigned int)p;

	m += handle(a, 16, 2);
	return (m);
}
