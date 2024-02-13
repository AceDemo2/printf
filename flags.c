#include "main.h"
void handle_flags(const char *f)
{
	int p = 0, s = 0, h = 0;

	(*f == '+') ? p = 1 : (*f == ' ') ? s = 1 : (*f == '#') ? h = 1 : p = 0;
}
