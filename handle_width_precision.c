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

void precision_options(const char *format, Precision *precision, va_list list)
{
	int format_position = 0;
	int precision_size = 0;
	int width = 0;
	int zero_flag = 0;
	char operations[7] = {'i', 'd', 'o', 'u', 'x', 'X', '\0'};
	int i = 0;

	if (*format == '.')
	{
		format++;
		format_position++;

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
				width *= 10  + (*format - '0');
				format++;
				format_position++;
			}
		}

		if (*format == '*')
		{
			width = va_arg(list, int);
		}

		if (*format != 's')
		{

			while (operations[i] != '\0')
			{
				if (*format == operations[i])
				{
					precision->width_options.width = width;
					format++;
					format_position++;
					break;
				}
				i++;
			}

		}
		else
		{
			precision_size = width;
			format++;
			format_position++;
		}


		precision->size = precision_size;
		precision->width_options.zero_flag = zero_flag;
		precision->format_position = format_position;

				
	}





}
