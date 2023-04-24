# include "main.h"
/**
 * _binaryT - receves a va_list decimal arg and print it in binary
 * @args: decimal integer va_list argument to be converted
 * Return: number of printed characters
 */
int _binaryT(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0, i, k;
	int leading_zero = 1;

	for (i = 31; i >= 0; i--)
	{
		k = n >> i;
		if (k & 1 || !leading_zero)
		{
			write(STDOUT_FILENO, (k & 1) ? "1" : "0", 1);
			count++;
			leading_zero = 0;
		}
	}
	if (leading_zero)
	{
		write(STDOUT_FILENO, "0", 1);
		count++;
	}
	return (count - 1);
}
/**
 * _print_octal - receves a decimal and print it in octal
 * @n: integer to be converted
 * Return: number of printed characters
 */
int _print_octal(unsigned int n)
{
	int i = 0;
	static int z = -1;

	i =  n / 8;
	if (i > 0)
		_print_octal(i);
	z += _print((n % 8) + '0');
	return (z);
}
/**
 * _printoctal - receves a decimal and print it in octal
 * @args: va_list argument integer to be converted
 * Return: number of printed characters
 */
int _printoctal(va_list args)
{
	int z = 0;
	unsigned int n;

	n = va_arg(args, unsigned int);
	z += _print_octal(n);
	return (z);
}
