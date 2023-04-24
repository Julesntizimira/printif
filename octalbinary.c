# include "main.h"

/**
 * _printbinary - receves a decimal and print it in binary
 * @n: integer to be converted
 * Return: number of printed characters
 */
int _printbinary(int n)
{
	int z = 0;

	if (n >= 2)
		z += _printbinary(n / 2);
	z += _print((n % 2) + '0');

	return (z);
}
/**
 * _binaryT - receves a va_list decimal arg and print it in binary
 * @args: decimal integer va_list argument to be converted
 * Return: number of printed characters
 */
int _binaryT(va_list args)
{
	int z = 0;
	unsigned int n;

	n = va_arg(args, unsigned int);
	z += _printbinary(n);
	return (z - 1);
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
