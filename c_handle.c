#include "main.h"
int handle_c(int c)
{
	int m = 0;
	m += write(1, &c, 1);
	return (m);
}
