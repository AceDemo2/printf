#include "main.h"
int handle_s(char *j, int w)
{
	int m = 0;
	
	if (w)
       		m += padding(w, strlen(j));
	j = (j == NULL) ? "(null)" : j;
	m += write(1, j, strlen(j));
	return (m);
}
