#include "main.h"
int handle_c(int c, int w)
{
	int m = 0;

	if (w)
		padding(w, 1);
	m += write(1, &c, 1);
	return (m);
}
