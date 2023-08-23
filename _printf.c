#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int chars_printed;
	conver_t f_list[] = 
	{
		{"c", print_character},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_number},
		{NULL,NULL}

	};
	va_list argument_list;

	if(format == NULL)
		return(-1);

	va_start(argument_list, format);
	chars_printed = final_print(format, f_list, argument_list);
	va_end(argument_list);
	return(chars_printed);
}
