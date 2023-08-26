#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of printed characters
 */

int _printf(const char *format, ...)
{
	int idx, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_idx = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (idx = 0; format && format[idx] != '\0'; idx++)
	{
		if (format[idx] != '%')
		{
			buffer[buff_idx++] = format[idx];
			if (buff_idx == BUFF_SIZE)
				print_buffer(buffer, &buff_idx);
			/* write(1, &format[idx], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_idx);
			flags = get_flags(format, &idx);
			width = get_width(format, &idx, args);
			precision = get_precision(format, &idx, args);
			size = get_size(format, &idx);
			++idx;
			printed = handle_print(format, &idx, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_idx);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Buffer array
 * @buff_idx: Index at which to add next char, represents the length
 */

void print_buffer(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);

	*buff_idx = 0;
}
