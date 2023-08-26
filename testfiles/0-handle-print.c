#include "main.h"

/**
 * handle_print - Handles the printing of arguments based on format.
 * @format: Formatted string in which to print the arguments.
 * @ind: Current index in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */

int handle_print(const char *format, int *ind,
		va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int i, printed = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char_handler}, {'s', print_string_handler},
		{'%', print_percent_handler}, {'i', print_int_handler},
		{'d', print_int_handler}, {'b', print_binary_handler},
		{'u', print_unsigned_handler}, {'o', print_octal_handler},
		{'x', print_hexadecimal_handler}, {'X', print_hexa_upper_handler},
		{'p', print_pointer_handler}, {'S', print_non_printable_handler},
		{'r', print_reverse_handler}, {'R', print_rot13string_handler},
		{'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (format[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}

	/* Handle unknown format specifier */
	if (fmt_types[i].fmt == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		printed_chars += write_char_handler('%', buffer, 0, 0, 0, 0);
		if (format[*ind - 1] == ' ')
			printed_chars += write_char_handler(' ', buffer, 0, 0, 0, 0);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		printed_chars += write_char_handler(format[*ind], buffer, 0, 0, 0, 0);
	}

	return (printed_chars);
}
