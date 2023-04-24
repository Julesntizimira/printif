# include "main.h"
/**
 * _printf - a printf-like function
 * @format: The format string composed of zero or more directives
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{

	int i = 0, k = 0,  buff_ind = 0;
	va_list args;
	char buffer[1024];

	va_start(args, format);
	if (!format)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == 1024)
			{
				print_buffer(buffer, &buff_ind);
			}
			k++;
			print_buffer(buffer, &buff_ind);
		}
		if (format[i] == '%')
		{
			i++;
			k += printhandler(args, format, i);
			print_buffer(buffer, &buff_ind);
		}
		i++;
	}
	va_end(args);
	return (k);
}
/**
 * printhandler - handle printing
 * @args: va_list input
 * @format: format string
 * @i: index input
 * Return: number of character printed
 */
int printhandler(va_list args, const char *format, int i)
{
	unsigned long int j;
	int k = 0;
	_fmt fmt[] = {
		{'c', charhandler}, {'s', strhandler},
		{'d', _printint}, {'i', _printint},
		{'%', _printmod}, {'b', _binaryT},
		{'u', _printUint}, {'o', _printoctal},
		{'x', _print_hex}, {'X', _print_hexUpper},
		{'S', _nonprinthandler}, {'p', _print_hex}
	};

	for (j = 0; j < sizeof(fmt) / sizeof(fmt[0]); j++)
	{
		if (fmt[j].c == format[i])
		{
			k += fmt[j].ptr(args);
			break;
		}
	}
	return (k);
}
