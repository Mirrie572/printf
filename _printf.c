#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Arguments to the function
 * @...: aditional arguments
 * Return: A format string to output
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0' || *format == ' ')
				break;

			if (*format == 'c')
				count += handle_c(args);
			else if (*format == 's')
				count += handle_s(args);
			else if (*format == '%')
				count += print_char('%');
		}
		else
		{
			count += print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
