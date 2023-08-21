#include "main.h"

/**
 * _printf - Custom printf implementation
 * @format: Format string with placeholders
 * @...: Additional arguments for placeholders
 * Return: Number of printed characters excluding null byte
 */
int _printf(const char *format, ...);

/**
 * hconv - Handle conversion specifiers
 * @spec: Conversion specifier (e.g., 'c', 's', '%')
 * @args: va_list containing arguments
 * @buff: Output buffer for printed characters
 * @idx: Pointer to index of last character in buffer
 * Return: Number of printed characters for specifier
 */
int hconv(char spec, va_list *args, char buff[], int *idx);

int _printf(const char *format, ...)
{
	va_list args;
	int format_idx, chars_printed = 0, buff_idx = 0;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (format_idx = 0; format && format[format_idx] != '\0'; format_idx++)
	{
		if (format[format_idx] != '%')
		{
			buffer[buff_idx++] = format[format_idx];
			if (buff_idx == BUFFER_SIZE)
				fprint_buffer(buffer, &buff_idx);
			chars_printed++;
		}
		else
		{
			fprint_buffer(buffer, &buff_idx);
			format_idx++;
			chars_printed += hconv(format[format_idx], &args, buffer, &buff_idx);
		}
	}

	fprint_buffer(buffer, &buff_idx);

	va_end(args);

	return (chars_printed);
}

int hconv(char spec, va_list *args, char buff[], int *idx)
{
	int c_printed = 0;

	if (spec == 'c')
	{
		char c = va_arg(*args, int);

		buff[(*idx)++] = c;

		c_printed++;
	}
	else if (spec == 's')
	{
		char *s = va_arg(*args, char *);
		int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			buff[(*idx)++] = s[i];
			if (*idx == BUFFER_SIZE)
				fprint_buffer(buff, idx);
			c_printed++;
		}
	}
	else if (spec == '%')
	{
		buff[(*idx)++] = '%';
		c_printed++;
	}

	return (c_printed);
}
