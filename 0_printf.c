#include "main.h"

void fprint_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Custom implementation of printf function
 * @format: The format string containing placeholders
 * @...: Additional arguments to be inserted into placeholders
 *
 * Return: Number of characters printed
 *         excluding the null byte used to end output to strings
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
				fprint_buffer(buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			fprint_buffer(buffer, &buffer_index);
			/* Handle conversion specifiers here */
		}
	}

	fprint_buffer(buffer, &buffer_index);

	va_end(args);

	return (printed_chars);
}

/**
 * fprint_buffer - Flushes the buffer and prints its contents to stdout
 * @buffer: Array of characters to be printed
 * @buffer_index: Pointer to the index of
 *                the last character in the buffer
 */
void fprint_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
		*buffer_index = 0;
	}
}
