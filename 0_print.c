#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_idx = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_idx++] = format[i];
			if (buff_idx == BUFFER_SIZE)
			{
				write(1, buffer, buff_idx);
				buff_idx = 0;
			}
			printed_chars++;
		}
		else
		{
			if (buff_idx > 0)
			{
				write(1, buffer, buff_idx);
				buff_idx = 0;
			}
			i++;

			if (format[i] == 'c')
				printed_chars += handle_char(va_arg(args, int), buffer, &buff_idx);
			else if (format[i] == 's')
				printed_chars += handle_string(va_arg(args, char *), buffer, &buff_idx);
			else if (format[i] == '%')
				printed_chars += handle_percent(buffer, &buff_idx);
		}
	}

	if (buff_idx > 0)
		write(1, buffer, buff_idx);

	va_end(args);

	return (printed_chars);
}

/* Helper functions for each specifier */

int handle_char(char c, char buffer[], int *buff_idx)
{
	buffer[(*buff_idx)++] = c;
	if (*buff_idx == BUFFER_SIZE)
	{
		write(1, buffer, BUFFER_SIZE);
		*buff_idx = 0;
	}
	return 1;
}

int handle_string(char *str, char buffer[], int *buff_idx)
{
	int len = strlen(str);
	if (*buff_idx + len >= BUFFER_SIZE)
	{
		write(1, buffer, *buff_idx);
		*buff_idx = 0;
	}
	strcpy(buffer + *buff_idx, str);
	*buff_idx += len;
	return len;
}

int handle_percent(char buffer[], int *buff_idx)
{
	buffer[(*buff_idx)++] = '%';
	if (*buff_idx == BUFFER_SIZE)
	{
		write(1, buffer, BUFFER_SIZE);
		*buff_idx = 0;
	}
	return 1;
}
