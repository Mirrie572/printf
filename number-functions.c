/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

/**
 * print_hexa_handler - Handles printing a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @flag_ch: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of characters printed
 */
int print_hexa_handler(va_list args, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
