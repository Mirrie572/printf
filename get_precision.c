#include "main.h"

/**
 * get_precision - Calculate the precision for printing
 * @format: The format string containing placeholders
 * @format_index: Pointer to the current index in the format string
 * @list: List of arguments passed to _printf
 *
 * This function extracts the precision value.
 * If no precision is specified, the function returns -1.
 *
 * Return: The extracted precision value
 */
int get_precision(const char *format, int *format_index, va_list list)
{
	int precision_index = *format_index + 1;
	int precision = -1;

	/* Check if the precision specifier '.' is present */
	if (format[precision_index] != '.')
		return (precision);

	precision = 0;

	/* Extract the precision value from the format string */
	for (precision_index += 1; format[precision_index] != '\0'; precision_index++)
	{
		if (is_digit(format[precision_index]))
		{
			precision *= 10;
			precision += format[precision_index] - '0';
		}
		else if (format[precision_index] == '*')
		{
			precision_index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	/* Update the index to skip the processed characters */
	*format_index = precision_index - 1;

	return (precision);
}
