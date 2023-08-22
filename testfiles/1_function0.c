#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...);
int handle_format(const char *format, va_list *args);
int handle_char(int c);
int handle_string(char *str);
int handle_integer(int num);

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 * @...: Additional arguments
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = handle_format(format, &args);
	va_end(args);

	return (count);
}

/**
 * handle_format - Handles the format string and conversion specifiers
 * @format: Format string
 * @args: Additional arguments
 * Return: Number of characters printed
 */

int handle_format(const char *format, va_list *args)
{
	int count = 0;

	for (; *format; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
				count += handle_char(va_arg(*args, int));
			else if (*format == 's')
				count += handle_string(va_arg(*args, char *));
			else if (*format == 'd' || *format == 'i')
				count += handle_integer(va_arg(*args, int));
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
		}
	}

	return (count);
}

/**
 * handle_char - Handles the 'c' conversion specifier
 * @c: Character to be printed
 * Return: Number of characters printed
 */

int handle_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * handle_string - Handles the 's' conversion specifier
 * @s: String to be printed
 * Return: Number of characters printed
 */

int handle_string(char *s)
{
	int count = 0;

	for (; *s; s++)
	{
		write(1, s, 1);
		count++;
	}
	return (count);
}

/**
 * handle_integer - Handles the 'd' and 'i' conversion specifiers
 * @num: Integer to be printed
 * Return: Number of characters printed
 */

int handle_integer(int num)
{
	int i;

	int count = 0;

	char num_str[12];  /* Maximum length of an int as a string */

	sprintf(num_str, "%d", num);  /* Convert int to string */

	for (i = 0; num_str[i] != '\0'; i++)
	{
		write(1, &num_str[i], 1);
		count++;
	}
	return (count);
}
