#ifndef MAIN
#define MAIN
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int handle_id(va_list i, int lo, int hs, int w);
int handle_c(int c, int w);
int handle_s(char *j, int w);
int custom_specifier(char *c, int w);
int handle(unsigned long b, int c, int a, int lo, int h, int w);
void dbuff(int a, char *b);
int handle_p(void * p, int w);
int handle_r(char *r, int w);
int handle_R(char *r, int w);
int padding(int w, int l);

int handle_flags(const char *f);

#endif
