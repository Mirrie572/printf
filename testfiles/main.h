#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024



/**
 * _printf - Custom implementation of printf function
 *
 * @format: The format string containing placeholders
 * @...: Additional arguments to be inserted into placeholders
 *
 * Return: Number of characters printed
 */

/* prototypes */

int _printf(const char *format, ...);
void fprint_buffer(char buffer[], int *buffer_index);
int handle_format(const char *format, va_list *args);
int handle_char(int c);
int handle_string(char *s);
int handle_integer(int num);
int handle_binary(unsigned int n);
int _putchar(int num, int count);
int print_string(char *str);
int handle_s(va_list args);
int print_char(char c);
int handle_c(va_list args);

#endif
