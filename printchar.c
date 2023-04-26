# include "main.h"

/**
 * _print - functino that prints charcter
 * @c: character to be printed
 * Return: 1
 */

int _print(int c)
{
	write(1, &c, 1);
	return (1);
}
