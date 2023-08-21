#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 * @...: Additional arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;  /* Initialize the count of printed characters */
	va_list args;
	char c, *s;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (; *format; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;  /* Increment count for each printed character */
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

				for (; *s; s++)
				{
					write(1, s, 1);
					count++;
				}
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
		}
	}

	va_end(args);

	return (count);
}
