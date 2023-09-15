#include "main.h"

int start_printf(va_list list, const char *format, Buffer *buffer)
{
	void (*string_specifiers)(va_list, Width_Opt*, Precision*, Buffer*);
	void (*custom_specifier)(va_list, Buffer*);
	void (*flags)(Flags*);
	void (*length_flag)(Flags*);
	void (*numbers)(va_list, Flags*, Width_Opt*, Buffer*);

	Flags *flag  = init_flags();

	Width_Opt *w_options = init_width();
	Precision *precision = init_precision();

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			flags = select_flag(format);

			if (flags != NULL)
			{
				flags(flag);
				format++;
			}

			length_flag = select_flag(format);

			if (length_flag != NULL)
			{
				length_flag(flag);
				format++;
			}


			width_options(format, list, w_options); 
			format  = format + (w_options->format_position);

			length_flag = select_flag(format);

			if (length_flag)
			{
				length_flag(flag);
				format++;
			}

			precision_options(format, precision, w_options, list);
			format += precision->format_position;

			numbers = select_number(format);

			if (numbers != NULL)
			{
				numbers(list, flag, w_options, buffer);
			}

			string_specifiers = select_specifier(format);

			if (string_specifiers != NULL)
			{
				string_specifiers(list, w_options, precision, buffer);
			}

			custom_specifier = custom_specifier_selecter(format);

			if ( custom_specifier)
			{
				custom_specifier(list, buffer);
			}


			if ((!string_specifiers) && (!custom_specifier) && (!flags)     && (!length_flag) && (!numbers))
			{
				print_normal_character(format, buffer);                                     }
		}
		else
		{
			print_normal_character(format, buffer);
		}

		format++;
	}

	buffer->buffer_space[buffer->position] = '\0'; 

        

	free_options(flag, w_options, precision);
	return (buffer->length);

}


int _printf(const char *format, ...)
{
	int len = 0;
	va_list list;
	Buffer  *buffer;

	va_start(list, format);
	buffer = init_buffer(1024);

	if (buffer == NULL)
	{
		return (-1);
	}

	if (format == NULL)
	{
		return (-1);
	}

	len += start_printf(list, format, buffer);
	_putchar(buffer);

	free_buffer(buffer);
	va_end(list);

	return (len);  

}
