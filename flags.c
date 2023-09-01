#include "main.h"

void (*select_flag(const char *c)) (Flags *flags)
{

	int i = 0;

	Flag_Op flag[6] = 
	{
		{"+", plus_flag},
		{"#", hash_flag},
		{" ", space_flag},
		{"h", h_length_modifier},
		{"l", l_length_modifier},
		{NULL, NULL}

	};


	while (flag[i].flag != NULL)
	{
		if (flag[i].flag[0] == *c)
		{
			return (flag[i].f);
		}

		i++;
	}


	return NULL;


}



void plus_flag(Flags *flag)
{
	flag->flg = "+";	

}

void hash_flag(Flags *flag)
{
	flag->hex_lower = "0x";
	flag->hex_upper = "0X";
	flag->octal = "0";
}

void space_flag(Flags *flag)
{
	flag->space = 1;
}


void h_length_modifier(Flags *flag)
{
	flag->length_modifier.h = 1;
}

void l_length_modifier(Flags *flag)
{
	flag->length_modifier.l = 1;
}
