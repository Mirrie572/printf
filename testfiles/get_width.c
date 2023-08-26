#include "main.h"

/**
 * extract_width - Extracts width value from the format string.
 * @format: Formatted string in which to print the arguments.
 * @index: Current index in the format string.
 * Return: Width value.
 */

int extract_width(const char *format, int *index)
{
	int current_index = *index + 1;
	int width = 0;

	for (; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (width);
}

/**
 * get_width - Calculates the width for printing.
 * @format: Formatted string in which to print the arguments.
 * @index: Current index in the format string.
 * @list: List of arguments.
 * Return: Width value.
 */

int get_width(const char *format, int *index, va_list list)
{
	return (extract_width(format, index));
}
