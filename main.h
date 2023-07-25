#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
** @op: The operator
* 
* @f: The function associated
*/
struct convert
{
	char *op;
	int (*f)(va_list);
};
typedef struct convert conv;


int parser(const char *format, conv f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _putchar(char);
int display_char(va_list);
int display_string(va_list);
int display_percent(va_list);
int display_integer(va_list);
int display_number(va_list);
int display_binary(va_list);
int display_rev(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int display_octal(va_list list);
int display_hex(va_list list);
int display_heX(va_list list);

unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int display_unsgined_number(unsigned int);


#endif
