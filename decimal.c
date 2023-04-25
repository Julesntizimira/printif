# include "main.h"
/**
 * _print_int - a function that prints an integer
 * @n: input integer
 * Return: number of character printed
 */
int _print_int(int n)
{
	int z = 0;
	int temp, i;

	if (n == INT_MIN)
	{
		z += _print('-');
		z += _print_Uint(2147483648);
		z++;
	}
	else
	{
		if (n < 0)
		{
			z += _print('-');
			n *= -1;
		}
		temp = n;
		do {
			temp /= 10;
			z++;
		} while (temp != 0);
		i = n / 10;
		if (i > 0)
			_print_int(i);
		z += _print((n % 10) + '0');
	}
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
	int z = -1, temp = 0;

	temp = n;
	do {
		temp /= 10;
		z++;
	} while (temp != 0);
	i = n / 10;
	if (i > 0)
		_print_int(i);
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
	return (i - 1);
}
/**
 * _printUint - receives va_list argument and prints a positive integer
 * @args: va_list unsigned int argument
 * Return: number of character printed
 */
int _printUint(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char dec_str[11];
	char temp;
	int i = 0, digit, len;

	if (num == 0)
	{
		dec_str[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			digit = num % 10;
			dec_str[i++] = '0' + digit;
			num /= 10;
		}
	}
	dec_str[i] = '\0';
	len = i;
	i = 0;
	while (i < len / 2)
	{
		temp = dec_str[i];
		dec_str[i] = dec_str[len - i - 1];
		dec_str[len - i - 1] = temp;
		i++;
	}
	return (_printstr(dec_str));
}
