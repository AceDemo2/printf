#include "main.h"
int handle_s(char *j)
{
	int m = 0;
	j = (j == NULL) ? "(null)" : j;
	m += write(1, j, strlen(j));
	return (m);
}
