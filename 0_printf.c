#include "main.h"

/**
 * handle_conv - Handles conversion specifiers and prints
 * @spec: Conversion specifier ('c', 's', '%')
 * @args: Variable argument list
 * @buff: Output buffer
 * @buff_i: Buffer index
 * Return: Number of printed characters
 */

int handle_conv(char spec, va_list *args, char buff[], int *buff_i);

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments
 * Return: Number of printed characters (excluding null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int fmt_i, chars_printed = 0, buff_i = 0;
	char buff[BUFFER_SIZE];

	if (!format)
		return (-1);

	va_start(args, format);

	for (fmt_i = 0; format && format[fmt_i] != '\0'; fmt_i++)
	{
		if (format[fmt_i] != '%')
		{
			buff[buff_i++] = format[fmt_i];
			if (buff_i == BUFFER_SIZE)
				fprint_buffer(buff, &buff_i);
			chars_printed++;
		}
		else
		{
			fprint_buffer(buff, &buff_i);
			fmt_i++;
			chars_printed += handle_conv(format[fmt_i], &args, buff, &buff_i);
		}
	}

	fprint_buffer(buff, &buff_i);

	va_end(args);

	return (chars_printed);
}

int handle_conv(char spec, va_list *args, char buff[], int *buff_i)
{
	int chars_printed = 0;

	if (spec == 'c')
	{
		char c = va_arg(*args, int);

		buff[(*buff_i)++] = c;

		chars_printed++;
	}
	else if (spec == 's')
	{
		char *s = va_arg(*args, char *);

		int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			buff[(*buff_i)++] = s[i];
			if (*buff_i == BUFFER_SIZE)
				fprint_buffer(buff, buff_i);
			chars_printed++;
		}
	}
	else if (spec == '%')
	{
		buff[(*buff_i)++] = '%';
		chars_printed++;
	}

	return (chars_printed);
}
