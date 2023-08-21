#include "main.h"

/**
 * get_width - Calculate the width for printing
 * @format: The format string containing placeholders
 * @format_index: Pointer to the current index in the format string
 * @list: List of arguments passed to _printf
 *
 * This function extracts the width value from the format string.
 * If no width is specified, the function returns 0.
 *
 * Return: The extracted width value
 */
int get_width(const char *format, int *format_index, va_list list)
{
	int width_index = *format_index + 1;
	int width = 0;

	/* Extract the width value from the format string */
	for (width_index; format[width_index] != '\0'; width_index++)
	{
		if (is_digit(format[width_index]))
		{
			width *= 10;
			width += format[width_index] - '0';
		}
		else if (format[width_index] == '*')
		{
			width_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	/* Update the index to skip the processed characters */
	*format_index = width_index - 1;

	return (width);
}
