#ifndef PRINT_F
#define PRINT_F

#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *symbol;
	int(*function)(va_list);
};
typedef struct convert conver_t;

/*functions*/
int final_print(const char *format, conver_t f_list[], va_list argument_list);
int _printf(const char *format, ...);
int _write(char);
int print_character(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
#endif
