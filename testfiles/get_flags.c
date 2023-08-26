#include "main.h"

/**
 * get_flags - Extracts active formatting flags from the format string.
 * @format: The format string containing the formatting directives.
 * @startIndex: The current index in the format string.
 * Return: The calculated flags based on formatting directives.
 */
int get_flags(const char *format, int *startIndex)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int j, currentIndex;
	int flags = 0;
	const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (currentIndex = *startIndex + 1; format[currentIndex]
			!= '\0'; currentIndex++)
	{
		for (j = 0; FLAG_CHARACTERS[j] != '\0'; j++)
		{
			if (format[currentIndex] == FLAG_CHARACTERS[j])
			{
				flags |= FLAG_VALUES[j];
				break;
			}
		}

		if (FLAG_CHARACTERS[j] == 0)
			break;
	}

	*startIndex = currentIndex - 1;

	return (flags);
}
