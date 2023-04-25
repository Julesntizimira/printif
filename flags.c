# include "main.h"

/**
 * printplus - handle printing
 * @args: va_list input
 * @format: format string
 * @i: index input
 * Return: number of character printed
 */
int printplus(va_list args, const char *format, int i)
{
	int num;
	char prefix = '\0';

	switch (format[i + 1])
	{
		case 'd':
		case 'i':
			num = va_arg(args, int);
			prefix = (num >= 0) ? '+' : '\0';
			break;
		default:
			return (-1);
	}
	if (prefix != '\0')
	{
		return (_print(prefix));
	}
	return (0);

}
/**
 * printspace - handle printing
 * @args: va_list input
 * @format: format string
 * @i: index input
 * Return: number of character printed
 */
int printspace(va_list args, const char *format, int i)
{
	int num = va_arg(args, int);

	(void)format;
	(void)i;

	if (num >= 0)
		return (_print(' '));
	else
		return (-1);
}
/**
 * printhash - handle printing
 * @args: va_list input
 * @format: format string
 * @i: index input
 * Return: number of character printed
 */
int printhash(va_list args, const char *format, int i)
{
	int k = 0;
	char *prefix = "";

	(void)args;
	switch (format[i + 1])
	{
		case 'o':
			prefix = "0";
			break;
		case 'x':
			prefix = "0x";
			break;
		case 'X':
			prefix = "0X";
			break;
		default:
			return (-1);
	}
	k += _printstr(prefix);
	return (k);
}
