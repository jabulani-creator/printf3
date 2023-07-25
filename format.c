#include "main.h"
/**
 * display_char - This Prints character
 * @lists: This is a list of arguments
 * Return: It Will return the amount of characters printed.
 */
int display_char(va_list lists)
{
	_putchar(va_arg(lists, int));
	return (1);
}

/**
 * display_string - This Prints a string
 * @lists: a list of arguments
 * Return: This Will return the amount of characters printed.
 */
int display_string(va_list lists)
{
	int j;
	char *str;

	str = va_arg(lists, char *);
	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++)
		_putchar(str[j]);
	return (j);
}

/**
 * display_percent - This Prints a percent symbol
 * @lists: a list of arguments
 * Return: This Will return the amount of characters printed.
 */
int display_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * display_integer - This will Print an integer
 * @lists: list of arguments
 * Return: Will return the amount of characters printed.
 */
int display_integer(va_list lists)
{
	int length;

	length = display_number(lists);
	return (length);
}

/**
 * unsigned_integer - It Prints Unsigned integers
 * @lists: a List of all of the argumets
 * Return: a count of the numbers
 */
int unsigned_integer(va_list lists)
{
	unsigned int number;

	number = va_arg(lists, unsigned int);

	if (number == 0)
		return (display_unsgined_number(number));

	if (number < 1)
		return (-1);
	return (display_unsgined_number(number));
}
