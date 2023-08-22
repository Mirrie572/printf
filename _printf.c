#include "main.h"

/**
 * _printf - loops through format string, handles special chars
 * @format: string that contains format specifiers
 * Return: total count of characters printed
 */
int _printf(const char *format, ...)
{
	int sumup = 0;
	char specifier;

	va_list args;
	int index = 0;

	va_start(args, format);

	if (format[0] == '\0')
		return (-1);

	while (format[index])
	{
		if (format[index] == '%')
		{
			specifier = format[index + 1];
			sumup += (*pick_handler(specifier))(args);
			index += 2;
		}
		else
		{
			_putchar(format[index]);
			sumup++;
			index++;
		}
	}

	va_end(args);

	return (sumup);
}
