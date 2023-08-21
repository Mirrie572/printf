#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024


/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1


/**
 * _printf - Custom implementation of printf function
 *
 * @format: The format string containing placeholders
 * @...: Additional arguments to be inserted into placeholders
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...);

#endif
