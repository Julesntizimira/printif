# include "main.h"
/**
 * print_buffer - printbuffer function
 * @buffer: input buffer array
 * @buff_ind: buffer index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
