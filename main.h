#ifndef MAIN
#define MAIN
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int handle_id(long j);
int handle_c(int c);
int handle_s(char *j);
int custom_specifier(char *c);
int handle(unsigned long b, int c, int a);
void dbuff(int a, char *b);
int handle_p(void * p);
int handle_r(char *r);
#endif
