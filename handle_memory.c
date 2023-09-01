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


void free_memory(Buffer *buffer)
{
    free(buffer->buffer_space);
    free(buffer);
}
