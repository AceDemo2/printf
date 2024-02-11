#include "main.h"
int handle_flags(const char *f)
{
	if (*f == '+')
		write(1, "+", 1);
	else if (*f == ' ')
		write(1, " ", 1);
	else if (*f == '#')
		write(1, "+", 1);
	return (1);
}
