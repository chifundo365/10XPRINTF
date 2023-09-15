#include "main.h"

void (*custom_specifier_selecter(const char *c))(va_list list, Buffer *buffer)
{
	Custom_Specs specs[5] = 
	{
		{"S", non_printable_char},
		{"b", print_binary},
		{"r", insert_reversed_string},
		{"R", rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specs[i].specifier != NULL)
	{
		if ((*c) == (specs[i].specifier[0]))
		{
			return (specs[i].f);
		}

		i++;
	}


	return (NULL);

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
						insert_into_buffer(buffer, *hex_upper);
						hex_upper++;
						
					}

					hex_upper = original_hex;

					free(hex_upper);
				}
			}
			else
			{
				insert_into_buffer(buffer, *string);
			}

			string++;
		}
	}  
}


void insert_reversed_string(va_list list, Buffer *buffer)
{
	char *string = va_arg(list, char*);
	int len = (_strlen(string)) -1;
        
	if (string)
	{
		while (len > -1)
		{
			insert_into_buffer(buffer, string[len]);
			len--;
		}
	}	

}


void rot13(va_list list, Buffer *buffer)
{
	int offset;
	char *string = va_arg(list, char*);

	while (*string != '\0')
	{
		if (_isalpha(*string))
		{
			offset = (*string >= 'a') ? 'a' : 'A';
			insert_into_buffer(buffer, ((*string - offset + 13) % 26) + offset);
		}
		else
		{
			insert_into_buffer(buffer, *string);
		}

		string++;
	}

}
