#include "main.h"
#include <stdio.h>

/**
 * rev_string - To reverses a string in place
 *
 * @s: a string to reverse
 * Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int length;
	int head;
	char temp;
	char *dest;

	for (length = 0; s[length] != '\0'; length++)
	{}

	dest = malloc(sizeof(char) * length + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, length);
	for (head = 0; head < length; head++, length--)
	{
		temp = dest[length - 1];
		dest[length - 1] = dest[head];
		dest[head] = temp;
	}
	return (dest);
}

/**
 * write_base - Thissends characters to be written on standard output
 * @str: a String to parse
 */
void write_base(char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
		_write_char(str[j]);
}

/**
 * base_len - To Calculates the length for an octal number
 * @num: The number for which the length is being calculated
 * @base: a Base to be calculated by
 * Return: this An integer representing the length of a number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int j;

	for (j = 0; num > 0; j++)
	{
		num = num / base;
	}
	return (j);
}

/**
 * _memcpy - a copy memory area
 * @dest: the Destination for copying
 * @src: the Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to char dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}
