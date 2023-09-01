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



void print_binary(va_list list, Buffer *buffer)
{
	unsigned int number = va_arg(list, unsigned int);
	char bf[50];
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;
	char temp;
	unsigned int len = 0;

	if (number == 0)
	{
		buffer->buffer_space[buffer->position] = '0';
		buffer->position++;
		buffer->length++;
	}
	else
	{
		while (number > 0)
		{
			bf[i] = (number % 2) + '0'; 
			number /= 2;
			i++;
		}     

		len  += _strlen(bf);

		if (len > 1)
		{
			while (j < (len / 2))
			{
				temp = bf[j];
				bf[j] = bf[len - j - 1];
				bf[len - j - 1] = temp;
				j++;  
			}
		}


		while (k < len)
		{
			buffer->buffer_space[buffer->position] = bf[k];
			buffer->position++;
			buffer->length++;
			k++;
		}

	}            


}




char *non_printable_hex(unsigned int number)
{
	char *buffer = malloc(sizeof(char) * 50);
	unsigned int i = 0;
	int j = 0;
	char temp;
	unsigned int r;
	unsigned char c;
	int len;

	if (buffer == NULL)
	{
		return (NULL);
	}


	while (number > 0)
	{
		r = number % 16;
		if (r >= 10 && r <= 15)
		{
			c = (r - 10) + 65;
		}
		else
		{
			c = r  + 48;
		}

		buffer[i] = c;
		number /= 16;
		i++;

	}



	buffer[i] = 'x';
	buffer[i + 1] = '\\';
	buffer[i + 2] = '\0';

	len = _strlen(buffer);

	if (len == 3)
	{       temp = buffer[i - 1];
		buffer[i] = 'x';
		buffer[i + 1] = '\\';
		buffer[i + 2] = temp;
		buffer[i - 1] = 48;
		buffer[i + 3] = '\0';
	}

	j = 0;

		while (j < len / 2)
		{
			temp = buffer[j];
			buffer[j] = buffer[len - j -1];
			buffer[len -j -1] = temp;
			j++;

		}
                

	return (buffer);

}



void non_printable_char(va_list list, Buffer *buffer)
{
	char *string = va_arg(list, char *);
        char *hex_upper;
	char *original_hex;
	unsigned int character;

	if (string)
	{
		while(*string != '\0')
		{
			if ((*string > 0 && *string < 32) || *string >= 127)
			{
				character = (unsigned int)*string; 
	 			hex_upper = non_printable_hex(character);
				original_hex = hex_upper;

				if (hex_upper)
				{
					while (*hex_upper != '\0')
					{
						buffer->buffer_space[buffer->position] = *hex_upper;
						buffer->position++;
						buffer->length++;
        
						hex_upper++;
						
					}

					hex_upper = original_hex;

					free(hex_upper);
				}
			}
			else
			{
				buffer->buffer_space[buffer->position] = *string;
				buffer->position++;
				buffer->length++;
			}


			string++;
		}
	}  
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











