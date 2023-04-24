# include "main.h"
/**
 * _strlen - funct
 * @s: string to compute the length
 * Return: int
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
/**
 * _binaryT - receves a va_list decimal arg and print it in binary
 * @args: decimal integer va_list argument to be converted
 * Return: number of printed characters
 */
int _binaryT(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[33];
	int i = 0, j, len;
	char temp;

	if (num == 0)
	{
		_print('0');
		return (1);
	}
	while (num > 0)
	{
		binary[i++] = num % 2 + '0';
		num /= 2;
	}
	binary[i] = '\0';

	len = _strlen(binary);
	for (j = 0; j < len / 2; j++)
	{
		temp = binary[j];
		binary[j] = binary[len - j - 1];
		binary[len - j - 1] = temp;
	}
	return (_printstr(binary));
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
