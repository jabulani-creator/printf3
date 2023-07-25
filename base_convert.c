#include "main.h"
#include <stdio.h>
int hex_check(int, char);

/**
 * display_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int display_binary(va_list list)
{
	unsigned int num;
	int j, length;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_len(num, 2);
	str = malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (-1);

	for (j = 0; num > 0; j++)
	{
		if (num % 2 == 0)
			str[j] = '0';
		else
			str[j] = '1';
		num = num / 2;
	}
	str[j] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (length);
}

/**
 * display_octal - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int display_octal(va_list list)
{
	unsigned int num;
	int length;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_len(num, 8);

	octal_rep = malloc(sizeof(char) * length + 1);
	if (octal_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		octal_rep[length] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[length] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (length);
}

/**
 * display_hex - Prints a representation of a decimal number
 *on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int display_hex(va_list list)
{
	unsigned int num;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}


/**
 * display_heX - Prints a representation of a decimal number
 * on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int display_heX(va_list list)
{
	unsigned int num;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
