#include "main.h"

/**
 * handle_binary - Handles the binary conversion specifier (%b)
 * @n: The unsigned int to be converted and printed as binary
 * Return: The number of characters printed
 */
int handle_binary(unsigned int n)
{
	int count = 0;
	int binary[32];  /* To store the binary representation */
	int i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	for (i = 0; n > 0; i++)
	{
		binary[i] = n % 2;
		n /= 2;
	}

	for (i--; i >= 0; i--)
	{
		write(1, &binary[i], 1);
		count++;
	}

	return (count);
}
