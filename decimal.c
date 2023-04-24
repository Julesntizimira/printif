# include "main.h"
/**
 * _print_int - a function that prints an integer
 * @n: input integer
 * Return: number of character printed
 */
int _print_int(int n)
{
	int i = 0;
	static int z = -1;

	if (n < 0)
	{
		z += _print('-');
		n *= -1;
	}
	i =  n / 10;
	if (i > 0)
		_print_int(i);
	z += _print((n % 10) + '0');
	return (z);
}
/**
 * _print_Uint - a function that prints a positive integer
 * @n: input unsigned integer
 * Return: number of character printed
 */
int _print_Uint(unsigned int n)
{
	unsigned int i = 0;
	static int z = -1;

	i =  n / 10;
	if (i > 0)
		_print_Uint(i);
	z += _print((n % 10) + '0');
	return (z);
}
/**
 * _printint - a function that receives va_list argument and prints an integer
 * @args: va_list int argument
 * Return: number of character printed
 */
int _printint(va_list args)
{
	int i = 0;
	int n = va_arg(args, int);

	i = _print_int(n);
	return (i + 1);
}
/**
 * _printUint - receives va_list argument and prints a positive integer
 * @args: va_list unsigned int argument
 * Return: number of character printed
 */
int _printUint(va_list args)
{
	int i = 0;
	unsigned int n = va_arg(args, unsigned int);

	i += _print_Uint(n);
	return (i + 1);
}

