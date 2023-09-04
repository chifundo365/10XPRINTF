#include "main.h"

void width_options(const char *format, va_list list, Width_Opt *options)
{
	int width = 0;
	int zero_flag = 0;
	int format_position = 0;

	if (*format == '0')
	{
		zero_flag = 1;
		format++;
		format_position++;
	}


	if (*format >= '0' && *format <= '9')
	{

		width = *format - '0';
		format++;
		format_position++;

		while (*format >= '0' && *format <= '9')
		{
			width = width * 10 + (*format - '0');
			format++;
			format_position++;
		}
	}




	if (*format  == '*')
	{
		width = va_arg(list, int);
		format_position++;
	}

	options->width  = width;
	options->zero_flag = zero_flag;
	options->format_position = format_position;

}
