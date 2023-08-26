#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handle_format(const char *format, va_list *args);
int handle_char(int c);
int handle_string(char *str);
int handle_integer(int num);

#endif
