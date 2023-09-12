#include "main.h"

int _strlen(char *c)
{
	int len = 0;

	while (*c != '\0')
	{
		len++;
		c++;
	}

	return len;
}

void (*select_specifier(const char *c))(va_list, Width_Opt*, Precision*, Buffer*)
{
	Specifiers specs[10] = 
	{
		{"c", print_char},
		{"s", print_string},
		
		{NULL, NULL}
	};

	int i = 0;
	int j = 0;

	while (specs[i].specifier != NULL) 
	{
		if (_strlen(specs[i].specifier) > 1)
		{
			while (specs[i].specifier[j])
			{
				if (specs[i].specifier[j] == *c)
				{
					return (specs[i].f);
				}

				j++;
			}
		}
		else if (specs[i].specifier[0]  == *c) {
			return specs[i].f;
		}
		i++;
	}

	return NULL;
}

void print_string(va_list list, Width_Opt *width, Precision *precision, Buffer *buffer)
{
	char *s;
	int len;
	int i = 0;

	s = va_arg(list, char*);
	len = _strlen(s);

	if (width->width)
	{
		if (width->zero_flag)
		{
			while (len < width->width)
			{
				insert_into_buffer(buffer, 48);
				len++;
			}

			while (s[i] != '\0')
			{
				insert_into_buffer(buffer, s[i]);
				i++;
			}
		}
		else
		{
			while (len < width->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			while (s[i] != '\0')
			{
				insert_into_buffer(buffer, s[i]);
				i++;
			}
		}
	}

	len = _strlen(s);
    i = 0;
	if (precision->size)
	{
		while ((precision->size > 0) && (s[i] != '\0'))
		{
			insert_into_buffer(buffer, s[i]);
			precision->size--;
			i++;
		}
	}
	else if ((!width->width) && (!precision->size))
	{
		while(s[i] != '\0')
		{
			insert_into_buffer(buffer, s[i]);
			i++;
		}
	}

}

void print_char(va_list list, Width_Opt *width, Precision *precision, Buffer *buffer)
{
	int c;
	c = va_arg(list, int);

	if (precision->size)
	{
		precision->size = 0;
	}

	if (width->width)
	{
		while ((width->width - 1) > 0)
		{
			insert_into_buffer(buffer, ' ');
			width->width--;
		}

		insert_into_buffer(buffer, c);
	}
	else
	{
		insert_into_buffer(buffer, c) ;
	}

}

void print_normal_character(const char *c, Buffer *buffer)
{
	insert_into_buffer(buffer, *c);
}


