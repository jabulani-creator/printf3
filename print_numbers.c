#include "main.h"

/**
 * display_numbers - Main Entry.
 *
 * Description: prints a number send to this function
 *
 * @args: List of arguments
 *
 * Return: The number of arguments printed
 */

int display_numbers(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar(45);
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar(48 + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * display_unsgined_number - Entry Point.
 *
 * Description: Prints an unsigned number
 *
 * @n: unsigned integer to be printed
 *
 * Return: The amount of numbers printed
 */

int display_unsgined_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar(48 + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
