#include <unistd.h>

/**
 * _putchar - Prints an integer character by character
 * @num: The integer to be printed
 * @count: The current count of characters printed
 * Return: The updated count of characters printed
 */
int _putchar(int num, int count)
{
	int absolute_value = num;

	if (num < 0)
	{
		absolute_value = -num;
		write(STDOUT_FILENO, "-", 1);
		count++;
	}

	if (absolute_value / 10)
	{
		count = _putchar(absolute_value / 10, count);
	}

	char digit_char = (absolute_value % 10) + '0';

	write(STDOUT_FILENO, &digit_char, 1);

	count++;

	return (count);
}
