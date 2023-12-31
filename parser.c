#include "main.h"

/**
 * parser - Main Entry.
 *
 * Description: Receives the main string and all the necessary parameters to
 *		print a formated string.
 *
 * @format: A string containing all the desired characters.
 *
 * @f_list: A list of all the posible functions.
 *
 * @arg_list: A list containing all the argumentents passed to the program.
 *
 * Return: A total count of the characters printed.
 */

int parser(const char *format, conv f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].op != NULL; j++)
			{
				if (format[i + 1] == f_list[j].op[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].op == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	i++;
	}
	return (printed_chars);
}
