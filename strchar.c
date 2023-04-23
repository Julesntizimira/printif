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
/**
 * _printmod - prints only '%' char
 * @args: va_list variable type
 * Return: 1
 */
int _printmod(va_list args)
{
	(void)args;
	_print('%');
	return (1);
}
/**
 * _printstr - function that prints string
 * @s: string to be printed
 * Return: number of characters printed
 */
int _printstr(char *s)
{
	int j = 0;

	if (s == NULL)
		exit(1);
	while (s[j] != '\0')
	{
		_print(s[j]);
		j++;
	}
	return (j);
}
/**
 * charhandler - function that prints string
 * @args: va_list type argument
 * Return: number 1
 */
int charhandler(va_list args)
{
	int k = 0;
	char c;

	c = va_arg(args, int);
	k += _print(c);
	return (k);
}
/**
 * strhandler - function that prints string
 * @args: va_list type argument
 * Return: number of characters printed
 */
int strhandler(va_list args)
{
	int k = 0;
	char *s = NULL;

	s = va_arg(args, char *);
	k += _printstr(s);
	return (k);
}
