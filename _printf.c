#include "main.h"

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
	char c, *s;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			count++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);

				while (*s)
				{
					write(1, s++, 1);
					count++;
				}
			}
			else if (*format == '%')
			{
				write(1, format++, 1);
				count++;
			}
		}
	}

	va_end(args);

	return (count);
}
