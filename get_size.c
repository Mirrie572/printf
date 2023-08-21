#include "main.h"

/**
 * get_size - Determine the size modifier for argument casting
 * @format: The format string containing placeholders
 * @format_index: Pointer to the current index in the format string
 *
 * This function checks the format string for size modifiers.
 * for argument casting. If no size modifier is found, it returns 0.
 *
 * Return: The size value corresponding to the size modifier (0, S_LONG, or S_SHORT)
 */
int get_size(const char *format, int *format_index)
{
	int size_index = *format_index + 1;
	int size = 0;

	/* Check for size modifiers 'l' and 'h' */
	if (format[size_index] == 'l')
		size = S_LONG;
	else if (format[size_index] == 'h')
		size = S_SHORT;

	/* Update the index to skip the processed characters */
	if (size != 0)
		*format_index = size_index;
	else
		*format_index = size_index - 1;

	return (size);
}
