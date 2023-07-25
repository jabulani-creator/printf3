#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int print_chars;
	conver_t f_list[] = {
		{"c", display_char},
		{"s", display_string},
		{"%", display_percent},
		{"d", display_integer},
		{"i", display_integer},
		{"b", display_binary},
		{"r", display_reversed},
		//{"R", rot13},
		{"u", display_integer},
		{"o", display_octal},
		{"x", display_hex},
		{"X", display_heX},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling parser function*/
	print_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (print_chars);
}
