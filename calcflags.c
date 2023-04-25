#include "main.h"

/**
 * calc_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: pointer to the index of current character in the format string
 * Return: Flags
 */
int calc_flags(const char *format, int *i)
{
	int flags = 0;
	char c;


	while ((c = format[++(*i)]) != '\0')
	{
		switch (c)
		{
			case '-':
				flags |= F_MINUS;
				break;
			case '+':
				flags |= F_PLUS;
				break;
			case '0':
				flags |= F_ZERO;
				break;
			case '#':
				flags |= F_HASH;
				break;
			case ' ':
				flags |= F_SPACE;
				break;
			default:
				(*i)--;
				return (flags);
		}
	}
	(*i)--;
	return (flags);
}
