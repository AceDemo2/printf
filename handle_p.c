#include "main.h"
#include <stdint.h>
int handle_p(void *p)
{
	int m = 0;
	uintptr_t a = (uintptr_t)p;
	m += handle(a, 16, 2);
	return (m);
}
