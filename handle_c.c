int handle_c(va_list i)
{
	int m = 0, k;
	k = va_arg(i, int);
	m += write(1, &k, 1);
	return (m);
}
