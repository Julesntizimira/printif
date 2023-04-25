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
	int num = va_arg(args, int);

	(void)format;
	(void)i;
	if (num >= 0)
		return (_print('+'));
	else
		return (-1);
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

	(void)args;
	switch (format[i + 1])
	{
		case 'o':
			_print('0');
			k++;
			break;
		case 'x':
			k += _printstr("0x");
			break;
		case 'X':
			k += _printstr("0X");
			break;
		default:
			k += -1;
			break;
	}
	return (k);
}
