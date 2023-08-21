#include "main.h"

/**
 * get_flags - Extracts active flags from the format string
 * @format: The format string containing the format specifier
 * @format_index: The index position
 * Return: A bitmask representing active flags
 *
 * This function scans the format string starting from the specified index
 * to find any active flags in the format specifier. The active flags are
 * represented as a bitmask.
 */
int get_flags(const char *format, int *format_index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int j, flag_index;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (flag_index = *format_index + 1; format[flag_index] != '\0'; flag_index++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
		{
			if (format[flag_index] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}
		}

		if (FLAGS_CHARS[j] == 0)
			break;
	}

	*format_index = flag_index - 1;

	return (flags);
}
