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

void (*select_specifier(const char *c))(va_list list, Buffer *buffer)
{
	Specifiers specs[10] = 
	{
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"S", non_printable_char},
		{"p", memory_address_hex},
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

void print_string(va_list list, Buffer *buffer)
{
	char *s;

	s = va_arg(list, char*);

	while (*s != '\0')
	{
		buffer->buffer_space[buffer->position] = *s; 
		buffer->position++;
		buffer->length++;
		s++;
	}

}

void print_char(va_list list, Buffer *buffer)
{
	int c;
	c = va_arg(list, int);
	if (c)

		buffer->buffer_space[buffer->position]= c;
	buffer->position++;
	buffer->length++;
}

void print_normal_character(const char *c, Buffer *buffer)
{
	buffer->buffer_space[buffer->position] = *c;
	buffer->position++;
	buffer->length++;

}


void memory_address_hex(va_list list, Buffer *buffer)
{

	void *ptr = va_arg(list, void *);
	uintptr_t  address = (uintptr_t)ptr;
	char buf[50];
	int c;
	unsigned int r;
        int i = 0;
	int len;
	char temp;

	while (address > 0)
	{
		r = address  % 16;

		if (r >= 10 && r <= 15)
		{
	        	c = r - 10 + 'a';	
		}
		else
		{
			c = r + '0';
		}

		buf[i] = c;
		address /= 16;
		i++;
	}

	buf[i] = 'x';
	buf[i + 1] = 48;
	buf[i + 2] = '\0';

	i = 0;
	len = _strlen(buf);

	while (i < len / 2)
	{
 		temp = buf[i];
		buf[i] = buf[len - i - 1];
		buf[len - i - 1] = temp;
		i++;
	}

	i = 0;

	while (i < len)
	{
		buffer->buffer_space[buffer->position] = buf[i];
		buffer->position++;
		buffer->length++;
		i++;
	}

}











