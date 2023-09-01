#include "main.h"

int start_printf(va_list list, const char *format, Buffer *buffer)
{
	void (*fr)(va_list, Buffer*);
	void (*flags)(Flags*);
	void (*length_flag)(Flags*);
	void (*numbers)(va_list, Flags*, Buffer*);

	Flags *flag  = malloc(sizeof(Flags));
	flag->flg = NULL;
	flag->hex_upper = NULL;
	flag->hex_lower = NULL;
	flag->octal = NULL;

	

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
			

			numbers = select_number(format);

			if (numbers != NULL)
			{
				numbers(list, flag, buffer);
			}

			fr = select_specifier(format);

			if (fr != NULL)
			{
				fr(list, buffer);
			}
		}
		else
		{
			print_normal_character(format, buffer);
		}

		format++;
	}

	buffer->buffer_space[buffer->position] = '\0'; 

        

	free(flag);
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

	free_memory(buffer);
	va_end(list);

	return (len);  

}
