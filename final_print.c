#include "main.h"

/**
 * final_print - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int final_print(const char *format, conver_t f_list[], va_list argument_list)
{
	int i,j, r_val, chars_printed;

	chars_printed = 0;
	for(i=0; format[i] != '\0'; i++)
	{
		if(format[i] == '%')
		{
			for(j = 0; f_list[j].symbol != NULL; j++)
			{
				if(format[i + 1] == f_list[j].symbol[0])
				{
					r_val = f_list[j].function(argument_list);
					if(r_val == -1)
						return(-1);
					chars_printed += r_val;
					break;
				}
			}
			if(f_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write(format[i]);
					_write(format[i + 1]);
					chars_printed = chars_printed + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_write(format[i]);
			chars_printed++;
		}
	}
	return(chars_printed);
}
