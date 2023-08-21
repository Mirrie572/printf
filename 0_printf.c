#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int format_index, printed_chars = 0, buffer_index = 0;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (format_index = 0; format && format[format_index] != '\0'; format_index++)
	{
		if (format[format_index] != '%')
		{
			buffer[buffer_index++] = format[format_index];
			if (buffer_index == BUFFER_SIZE)
				print_buffer(buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			/* Handle conversion specifiers here */
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the buffer if it's not empty
 * @buffer: Array of chars
 * @buffer_index: Index of the buffer
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
		*buffer_index = 0;
	}
}
