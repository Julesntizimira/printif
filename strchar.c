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
 * @flags: Flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: 1
 */
int _printmod(va_list args, int flags, int width, int precision, int size)
{
	(void)args;
	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	write(1, "%%", 1);
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

	while (s[j] != '\0')
	{
		write(1, &s[j], 1);
		j++;
	}
	return (j);
}
/**
 * charhandler - function that prints string
 * @args: va_list type argument
 * @flags: Flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: number 1
 */
int charhandler(va_list args, int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	write(1, &c, 1);

	return (1);
}
/**
 * strhandler - function that prints string
 * @args: va_list type argument
 * @flags: Flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: number of characters printed
 */
int strhandler(va_list args, int flags, int width, int precision, int size)
{
	int k = 0;
	char *s = NULL;

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	k += _printstr(s);
	return (k);
}
