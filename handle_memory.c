#include "main.h"


Buffer *init_buffer(size_t size)
{
    Buffer *buffer = (Buffer *)malloc(sizeof(Buffer));

    if (buffer == NULL)
    {
        return (NULL);
    }


    buffer->buffer_space = (char *)malloc(size);

    if (buffer->buffer_space == NULL)
    {
        return (NULL);
    }

    buffer->length = 0;
    buffer->position = 0;
    return buffer;
}


Width_Opt *init_width(void)
{
	Width_Opt *options = malloc(sizeof(Width_Opt));
	options->width = 0;
	options->zero_flag = 0;
	options->format_position  = 0;
	options->minus = 0;
	return options;
}

Flags *init_flags(void)
{
	Flags *flag = malloc(sizeof(Flags));
	flag->flg = NULL;
	flag->hex_upper = NULL;
	flag->hex_lower = NULL;
	flag->octal = NULL;

	return flag;
}


Precision *init_precision(void)
{
	Precision *precision = malloc(sizeof(Precision));
	precision->size = 0;
	precision->format_position = 0;

	return (precision);
}


void free_buffer(Buffer *buffer)
{
	free(buffer->buffer_space);
	free(buffer);

}

void free_options(Flags *flag, Width_Opt *options, Precision *precision)
{
	free(flag);
	free(options);
	free(precision);
}

void insert_into_buffer(Buffer *buffer, char c)
{
	buffer->buffer_space[buffer->position] = c;
	buffer->position++;
	buffer->length++;
}
