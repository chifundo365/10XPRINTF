#include "main.h"

void (*select_number(const char *c))(va_list, Flags*, Width_Opt*, Buffer*)
{
	Number_OP op[6] = 
	{

		{"id", insert_int},
		{"u", insert_unsigned_int},
		{"x", insert_hex_lower},
		{"X", insert_hex_upper},
		{"o", insert_octal},
		{NULL, NULL}

	};


	int i = 0;
	int len  = 0;


	while ((op[i].specifier) != NULL)
	{
		len  = _strlen(op[i].specifier);
		if (len > 1)
		{
			len -= 1;
			while (len >= 0)
			{
				if (op[i].specifier[len] == *c)
				{
					return (op[i].f);
				}

				len--;
			}
		}
		else
		{
			if ((op[i].specifier[0]) == *c)
			{
				return op[i].f;
			}

		}


		i++;

	}


	return (NULL);

}


void insert_int(va_list list,  Flags *flag, Width_Opt *width_options, Buffer *buffer)
{
	long int long_power = 1;
	short int short_power = 1;
	int normal_power = 1;
	int digit;
	int normal_number;
	int original_normal_number;
	long int long_number;
	long int original_long_number;
	short int short_number;
	short int original_short_number;
	char numbers_buffer[50];
	int nb_length;
	int nb = 0;
	char c;


	if ((flag->length_modifier.l) == 1)
	{
		flag->length_modifier.l = 0;
		long_number = va_arg(list, long int);
		original_long_number = long_number;

		
		if (long_number < 0)
		{
			numbers_buffer[nb] = '-';
			nb++;
			long_number *= -1;
			original_long_number = long_number;
		}
		else
		{
			if (flag->flg != NULL)
			{
				numbers_buffer[nb] = flag->flg[0];
				nb++;
				flag->flg = NULL;
			}

			if (((flag->space) == 1) && width_options->width == 0)
			{
				numbers_buffer[nb] = ' ';
				nb++;
				flag->space = 0;
			}
		}

		while (long_number >= 10)
		{
			long_power *= 10;
			long_number /= 10;	    
		}

		long_number = original_long_number;


		while (long_power >= 1)
		{
			digit = long_number / long_power;
			c = digit + '0';
			numbers_buffer[nb] = c;
			nb++;
			long_number %= long_power;
			long_power /= 10;
		}

		numbers_buffer[nb] = '\0';
		
		nb_length = _strlen(numbers_buffer);

		if (width_options->zero_flag == 0)
		{

			while(nb_length < width_options->width)
			{	
				insert_into_buffer(buffer, ' ');
				nb_length++;

			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}
		else
		{
			while(nb_length < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				nb_length++;
			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}

		nb  = 0;


		while (numbers_buffer[nb] != '\0')
		{
			insert_into_buffer(buffer, numbers_buffer[nb]);
			nb++; 
		}
		


	}
	else if ((flag->length_modifier.h) == 1)
	{

		flag->length_modifier.l = 0;
		short_number = (short)va_arg(list, int);
		original_short_number = short_number;

		
		if (short_number < 0)
		{
			numbers_buffer[nb] = '-';
			nb++;
			short_number *= -1;
			original_short_number = short_number;
		}
		else
		{
			if (flag->flg != NULL)
			{
				numbers_buffer[nb] = flag->flg[0];
				nb++;
				flag->flg = NULL;
			}

			if (((flag->space) == 1) && width_options->width == 0)
			{
				numbers_buffer[nb] = ' ';
				nb++;
				flag->space = 0;
			}
		}

		while (short_number >= 10)
		{
			short_power *= 10;
			short_number /= 10;	    
		}

		short_number = original_short_number;


		while (short_power >= 1)
		{
			digit = short_number / short_power;
			c = digit + '0';
			numbers_buffer[nb] = c;
			nb++;
			short_number %= short_power;
			short_power /= 10;
		}

		numbers_buffer[nb] = '\0';
		
		nb_length = _strlen(numbers_buffer);

		if (width_options->zero_flag == 0)
		{

			while(nb_length < width_options->width)
			{	
				insert_into_buffer(buffer, ' ');
				nb_length++;

			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}
		else
		{
			while(nb_length < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				nb_length++;
			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}

		nb  = 0;


		while (numbers_buffer[nb] != '\0')
		{
			insert_into_buffer(buffer, numbers_buffer[nb]);
			nb++; 
		}

	}
	else
	{
		normal_number = va_arg(list, int);
		original_normal_number = normal_number;

		
		if (normal_number < 0)
		{
			numbers_buffer[nb] = '-';
			nb++;
			normal_number *= -1;
			original_normal_number = normal_number;
		}
		else
		{
			if (flag->flg != NULL)
			{
				numbers_buffer[nb] = flag->flg[0];
				nb++;
				flag->flg = NULL;
			}

			if (((flag->space) == 1) && width_options->width == 0)
			{
				numbers_buffer[nb] = ' ';
				nb++;
				flag->space = 0;
			}
		}

		while (normal_number >= 10)
		{
			normal_power *= 10;
			normal_number /= 10;	    
		}

		normal_number = original_normal_number;


		while (normal_power >= 1)
		{
			digit = normal_number / normal_power;
			c = digit + '0';
			numbers_buffer[nb] = c;
			nb++;
			normal_number %= normal_power;
			normal_power /= 10;
		}

		numbers_buffer[nb] = '\0';
		
		nb_length = _strlen(numbers_buffer);

		if (width_options->zero_flag == 0)
		{

			while(nb_length < width_options->width)
			{	
				insert_into_buffer(buffer, ' ');
				nb_length++;

			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}
		else
		{
			while(nb_length < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				nb_length++;
			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}

		nb  = 0;


		while (numbers_buffer[nb] != '\0')
		{
			insert_into_buffer(buffer, numbers_buffer[nb]);
			nb++; 
		}

	}

}


void insert_unsigned_int(va_list list, Flags *flag, Width_Opt *width_options, Buffer *buffer)
{
	unsigned long int long_power = 1;
	unsigned short int short_power = 1;
	unsigned int normal_power = 1;
	unsigned int digit;
	unsigned int normal_number;
	unsigned int original_normal_number;
	unsigned long int long_number;
	unsigned long int original_long_number;
	unsigned short int short_number;
	unsigned short int original_short_number;
	char numbers_buffer[50];
	int nb_length;
	int nb = 0;
	char c;


	if ((flag->length_modifier.l) == 1)
	{
		flag->length_modifier.l = 0;
		long_number = va_arg(list, long int);
		original_long_number = long_number;

		

			if (flag->flg != NULL)
			{
				numbers_buffer[nb] = flag->flg[0];
				nb++;
				flag->flg = NULL;
			}

			if (((flag->space) == 1) && width_options->width == 0)
			{
				numbers_buffer[nb] = ' ';
				nb++;
				flag->space = 0;
			}

		while (long_number >= 10)
		{
			long_power *= 10;
			long_number /= 10;	    
		}

		long_number = original_long_number;


		while (long_power >= 1)
		{
			digit = long_number / long_power;
			c = digit + '0';
			numbers_buffer[nb] = c;
			nb++;
			long_number %= long_power;
			long_power /= 10;
		}

		numbers_buffer[nb] = '\0';
		
		nb_length = _strlen(numbers_buffer);

		if (width_options->zero_flag == 0)
		{

			while(nb_length < width_options->width)
			{	
				insert_into_buffer(buffer, ' ');
				nb_length++;

			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}
		else
		{
			while(nb_length < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				nb_length++;
			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}

		nb  = 0;


		while (numbers_buffer[nb] != '\0')
		{
			insert_into_buffer(buffer, numbers_buffer[nb]);
			nb++; 
		}
		


	}
	else if ((flag->length_modifier.h) == 1)
	{

		flag->length_modifier.l = 0;
		short_number = (short)va_arg(list, int);
		original_short_number = short_number;

		if (flag->flg != NULL)
			{
				numbers_buffer[nb] = flag->flg[0];
				nb++;
				flag->flg = NULL;
			}

			if (((flag->space) == 1) && width_options->width == 0)
			{
				numbers_buffer[nb] = ' ';
				nb++;
				flag->space = 0;
			}

		while (short_number >= 10)
		{
			short_power *= 10;
			short_number /= 10;	    
		}

		short_number = original_short_number;


		while (short_power >= 1)
		{
			digit = short_number / short_power;
			c = digit + '0';
			numbers_buffer[nb] = c;
			nb++;
			short_number %= short_power;
			short_power /= 10;
		}

		numbers_buffer[nb] = '\0';
		
		nb_length = _strlen(numbers_buffer);

		if (width_options->zero_flag == 0)
		{

			while(nb_length < width_options->width)
			{	
				insert_into_buffer(buffer, ' ');
				nb_length++;

			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}
		else
		{
			while(nb_length < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				nb_length++;
			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}

		nb  = 0;


		while (numbers_buffer[nb] != '\0')
		{
			insert_into_buffer(buffer, numbers_buffer[nb]);
			nb++; 
		}

	}
	else
	{
		normal_number = va_arg(list, int);
		original_normal_number = normal_number;

		
		
			if (flag->flg != NULL)
			{
				numbers_buffer[nb] = flag->flg[0];
				nb++;
				flag->flg = NULL;
			}

			if (((flag->space) == 1) && width_options->width == 0)
			{
				numbers_buffer[nb] = ' ';
				nb++;
				flag->space = 0;
			}

		while (normal_number >= 10)
		{
			normal_power *= 10;
			normal_number /= 10;	    
		}

		normal_number = original_normal_number;


		while (normal_power >= 1)
		{
			digit = normal_number / normal_power;
			c = digit + '0';
			numbers_buffer[nb] = c;
			nb++;
			normal_number %= normal_power;
			normal_power /= 10;
		}

		numbers_buffer[nb] = '\0';
		
		nb_length = _strlen(numbers_buffer);

		if (width_options->zero_flag == 0)
		{

			while(nb_length < width_options->width)
			{	
				insert_into_buffer(buffer, ' ');
				nb_length++;

			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}
		else
		{
			while(nb_length < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				nb_length++;
			}

			width_options->width = 0;
			width_options->zero_flag = 0;
		}

		nb  = 0;


		while (numbers_buffer[nb] != '\0')
		{
			insert_into_buffer(buffer, numbers_buffer[nb]);
			nb++; 
		}

	}

}



void insert_hex_upper(va_list list, Flags *flag, Width_Opt *width_options, Buffer *buffer)
{
	unsigned long int long_number;
	unsigned short int short_number;
	unsigned int normal_number;
	unsigned char hex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	unsigned int  hex_value[6] = {10, 11, 12, 13, 14, 15};
	unsigned char c = 'o';
	unsigned int digit;
	char temp;
	char bf[50];
	int i, k, j;
    int len = 0;	
	int z = 1;
	i = 0;
	k = 0;
	j = 0;

	if (flag->length_modifier.l)
	{
		flag->length_modifier.l = 0;
		long_number = va_arg(list, unsigned long int);

		while (long_number > 0)
		{
			digit = long_number % 16;

			if (digit >= 10 && digit <= 15)
			{
				while (i < 6)
				{
					if (digit == hex_value[i])
					{
						c = hex[i];
						break;
					}

					i++;
				}

			}
			else
			{
				c = digit + '0';

			}

			bf[k] = c;
			k++;

			long_number /= 16;
		}

		if (flag->hex_upper != NULL)
		{
			while (z >= 0)
			{
				bf[k] = flag->hex_upper[z];
				z--;
				k++;
			}

		}



		bf[k] = '\0';

		len = _strlen(bf);


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

		j = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[j] != '\0')
		{
			insert_into_buffer(buffer, bf[j]);
			j++;
		}

	}
	else if (flag->length_modifier.h)
	{

		flag->length_modifier.h = 0;
		short_number = (unsigned short int)va_arg(list, unsigned int);

		while (short_number > 0)
		{
			digit = short_number % 16;

			if (digit >= 10 && digit <= 15)
			{
				while (i < 6)
				{
					if (digit == hex_value[i])
					{
						c = hex[i];
						break;
					}

					i++;
				}

			}
			else
			{
				c = digit + '0';

			}

			bf[k] = c;
			k++;

			short_number /= 16;
		}

		if (flag->hex_upper != NULL)
		{
			while (z >= 0)
			{
				bf[k] = flag->hex_upper[z];
				z--;
				k++;
			}

		}



		bf[k] = '\0';

		len = _strlen(bf);

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

		j = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[j] != '\0')
		{
			insert_into_buffer(buffer, bf[j]);
			j++;
		}
	
	}
	else
	{
		normal_number = va_arg(list, unsigned int);

		while (normal_number > 0)
		{
			digit = normal_number % 16;

			if (digit >= 10 && digit <= 15)
			{
				while (i < 6)
				{
					if (digit == hex_value[i])
					{
						c = hex[i];
						break;
					}

					i++;
				}

			}
			else
			{
				c = digit + '0';

			}

			bf[k] = c;
			k++;

			normal_number /= 16;
		}

		if (flag->hex_upper != NULL)
		{
			while (z >= 0)
			{
				bf[k] = flag->hex_upper[z];
				z--;
				k++;
			}

		}


		bf[k] = '\0';

		len = _strlen(bf);

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

		j = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[j] != '\0')
		{
			insert_into_buffer(buffer, bf[j]);
			j++;
		}
	
	}

}



void insert_hex_lower(va_list list, Flags *flag, Width_Opt *width_options, Buffer *buffer)
{
	unsigned long int long_number;
	unsigned short int short_number;
	unsigned int normal_number;
	unsigned char hex[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int  hex_value[6] = {10, 11, 12, 13, 14, 15};
	unsigned char c = 'o';
	unsigned int digit;
	char temp;
	char bf[50];
	int i, k, j;
    int len = 0;	
	int z = 1;
	i = 0;
	k = 0;
	j = 0;

	if (flag->length_modifier.l)
	{
		flag->length_modifier.l = 0;
		long_number = va_arg(list, unsigned long int);

		while (long_number > 0)
		{
			digit = long_number % 16;

			if (digit >= 10 && digit <= 15)
			{
				while (i < 6)
				{
					if (digit == hex_value[i])
					{
						c = hex[i];
						break;
					}

					i++;
				}

			}
			else
			{
				c = digit + '0';

			}

			bf[k] = c;
			k++;

			long_number /= 16;
		}

		if (flag->hex_upper != NULL)
		{
			while (z >= 0)
			{
				bf[k] = flag->hex_upper[z];
				z--;
				k++;
			}

		}



		bf[k] = '\0';

		len = _strlen(bf);


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

		j = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[j] != '\0')
		{
			insert_into_buffer(buffer, bf[j]);
			j++;
		}

	}
	else if (flag->length_modifier.h)
	{

		flag->length_modifier.h = 0;
		short_number = (unsigned short int)va_arg(list, unsigned int);

		while (short_number > 0)
		{
			digit = short_number % 16;

			if (digit >= 10 && digit <= 15)
			{
				while (i < 6)
				{
					if (digit == hex_value[i])
					{
						c = hex[i];
						break;
					}

					i++;
				}

			}
			else
			{
				c = digit + '0';

			}

			bf[k] = c;
			k++;

			short_number /= 16;
		}

		if (flag->hex_upper != NULL)
		{
			while (z >= 0)
			{
				bf[k] = flag->hex_upper[z];
				z--;
				k++;
			}

		}



		bf[k] = '\0';

		len = _strlen(bf);

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

		j = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[j] != '\0')
		{
			insert_into_buffer(buffer, bf[j]);
			j++;
		}
	
	}
	else
	{
		normal_number = va_arg(list, unsigned int);

		while (normal_number > 0)
		{
			digit = normal_number % 16;

			if (digit >= 10 && digit <= 15)
			{
				while (i < 6)
				{
					if (digit == hex_value[i])
					{
						c = hex[i];
						break;
					}

					i++;
				}

			}
			else
			{
				c = digit + '0';

			}

			bf[k] = c;
			k++;

			normal_number /= 16;
		}

		if (flag->hex_upper != NULL)
		{
			while (z >= 0)
			{
				bf[k] = flag->hex_upper[z];
				z--;
				k++;
			}

		}


		bf[k] = '\0';

		len = _strlen(bf);

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

		j = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[j] != '\0')
		{
			insert_into_buffer(buffer, bf[j]);
			j++;
		}
	
	}
}



void insert_octal(va_list list, Flags  *flag, Width_Opt *width_options, Buffer *buffer)
{
	unsigned int  normal_number;
	unsigned long int long_number;
	unsigned short int short_number;
    int i = 0;
	int len = 0;
	char bf[50]; 
	char temp;

	if (flag->length_modifier.l)
	{
		flag->length_modifier.l = 0;
		long_number = va_arg(list, unsigned long int);

		while (long_number > 0)
		{
			bf[i] = (long_number % 8) + '0';
			long_number /= 8;
			i++;
		}

		if (flag->octal != NULL)
		{
			bf[i] = 48;
			flag->octal = NULL;
			i++;

		}

		bf[i] = '\0';

		i = 0;

		len  = _strlen(bf);

		if (len > 1)
		{
			while (i < (len / 2))
			{
				temp = bf[i];
				bf[i] = bf[len - 1 - i];
				bf[len -1 -i] = temp;
				i++;
			}		
		}


		i = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[i] != '\0')
		{
			insert_into_buffer(buffer, bf[i]);
			i++;
		}


	}
	else if (flag->length_modifier.h)
	{
		short_number = (unsigned short int)va_arg(list, int);
		flag->length_modifier.h = 0;

		while (short_number > 0)
		{
			bf[i] = (short_number % 8) + '0';
			short_number /= 8;
			i++;
		}

		if (flag->octal != NULL)
		{
			bf[i] = 48;
			flag->octal = NULL;
			i++;

		}
	
		bf[i] = '\0';

		i = 0;

		len  = _strlen(bf);

		if (len > 1)
		{
			while (i < (len / 2))
			{
				temp = bf[i];
				bf[i] = bf[len - 1 - i];
				bf[len -1 -i] = temp;
				i++;
			}		
		}

		i = 0;

		if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[i] != '\0')
		{
			insert_into_buffer(buffer, bf[i]);
			i++;
		}

	}
	else
	{	
		normal_number = va_arg(list, unsigned int);

		while (normal_number > 0)
	{
		bf[i] = (normal_number % 8) + '0';
		normal_number /= 8;
		i++;
	}

	if (flag->octal != NULL)
	{
		bf[i] = '0';
		flag->octal = NULL;
		i++;

	}

	bf[i] = '\0';
	i = 0;

	len  = _strlen(bf);

	if (len > 1)
	{
		while (i < (len / 2))
		{
			temp = bf[i];
			bf[i] = bf[len - 1 - i];
			bf[len -1 -i] = temp;
			i++;
		}		
	}

	i = 0;

	if ((width_options->zero_flag == 0) && (width_options->width != 0))
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, ' ');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}
		else
		{
			while (len < width_options->width)
			{
				insert_into_buffer(buffer, '0');
				len++;
			}

			width_options->zero_flag = 0;
			width_options->width = 0;
		}

		while (bf[i] != '\0')
		{
			insert_into_buffer(buffer, bf[i]);
			i++;
		}
	
	}


}

















