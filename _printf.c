# include "main.h"
/**
 * _printf - a printf-like function
 * @format: The format string composed of zero or more directives
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{

	int i = 0, k = 0;
	va_list args;
/*
 * int buff_ind = 0;
 * char buffer[BUFFER_SIZE];
 */

	va_start(args, format);
	if (!format)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
/*
 * buffer[buff_ind++] = format[i];
 * if (buff_ind == BUFFER_SIZE)
 * {
 * print_buffer(buffer, &buff_ind);
 * }
 * print_buffer(buffer, &buff_ind);
 */
			write(1, &format[i], 1);
			k++;
		}
		else if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				return (-1);
			}
			k += printhandler(args, format, i);
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
		{'x', _print_hex1}, {'X', _print_hexUpper},
		{'S', _nonprinthandler}, {'p', _print_hex}
	};
	for (j = 0; j < sizeof(fmt) / sizeof(fmt[0]); j++)
	{
		if (fmt[j].c == format[i])
		{
			k += fmt[j].ptr(args);
			break;
		}
		else if (j == ((sizeof(fmt) / sizeof(fmt[0])) - 1))
		{
			write(1, &format[i - 1], 1);
			k++;
			write(1, &format[i], 1);
			k++;
			break;
		}
	}
	return (k);
}
/**
 * _print_hex1 - receives a decimal and prints a hexadecimal
 * @args: va_list argument input decimal
 * Return: numbner of characters printed
 */
int _print_hex1(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex[17] = {0};
	int i = 0, j = 0, rem, len = 0;
	char temp;

	if (num == 0)
	{
		_print('0');
		return (1);
	}
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
		{
			hex[i++] = rem + '0';
		}
		else
		{
			hex[i++] = rem - 10 + 'a';
		}
		num /= 16;
	}
	hex[i] = '\0';

	len = _strlen(hex);
	for (j = 0; j < len / 2; j++)
	{
		temp = hex[j];
		hex[j] = hex[len - j - 1];
		hex[len - j - 1] = temp;
	}
	return (_printstr(hex));
}
