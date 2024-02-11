#include "main.h"
int handle_flags(char *f)
{
	int m = 0;

	if (*f == '+')
		m += write(1, "+", 1);
	else if (*f == ' ')
		m += write(1, " ", 1);
	else if (*f == '#')
		m += write(1, "+", 1);
	return (m);
}
