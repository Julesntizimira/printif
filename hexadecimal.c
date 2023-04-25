# include "main.h"
/**
 * hexUpper - receives a decimal and prints an UPPERCASEhexadecimal
 * @num: input decimal
 * Return: numbner of characters printed
 */
int hexUpper(int num)
{
	int z = 0;

	char hex_digits[] = "0123456789abcdef";
	char hex_string[9] = {'\0'};
	int i = 7;

	while (num != 0)
	{
		hex_string[i--] = hex_digits[num % 16];
		num /= 16;
	}
	for (i = 0; i < 8; i++)
	{
		if (hex_string[i] != '\0')
		{
			if (hex_string[i]  >= '0' && hex_string[i]  <= '9')
				z += _print(hex_string[i]);
			else
				z += _print((hex_string[i]) - 32);
		}
	}
	return (z);
}
/**
 * _print_hex - receives a decimal and prints a hexadecimal
 * @args: va_list argument input decimal
 * Return: numbner of characters printed
 */
int _print_hex(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int num = (unsigned long int)ptr;
	char hex_digits[] = "0123456789abcdef";
	char hex_string[17] = {'\0'};
	int i = 0, z = 0, j;

	if (num == 0)
	{
		hex_string[i++] = '0';
	}
	else
	{
		while (num != 0)
		{
			hex_string[i++] = hex_digits[num % 16];
			num /= 16;
		}
	}
	z += _printstr("0x");

	for (j = i - 1; j >= 0; j--)
	{
		z += _print(hex_string[j]);
	}
	return (z);
}
/**
 * _print_hexUpper - receives a decimal and prints UPPERCASE hexadecimal
 * @args: va_list argument input decimal
 * Return: numbner of characters printed
 */
int _print_hexUpper(va_list args)
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
			hex[i++] = rem - 10 + 'A';
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
/**
 * _nonprintchars - receives a nonprintable character and prints UPPERCASE hex
 * @s: input
 * Return: numbner of characters printed
 */
int _nonprintchars(char *s)
{
	int j = 0, i = 0;

	if (s == NULL)
		exit(1);
	while (s[j] != '\0')
	{
		if (s[j] < 32 || s[j] >= 127)
		{
			i += _print('\\');
			i += _print('x');
			if (s[j] < 16)
				i += _print('0');
			i += hexUpper(s[j]);
			j++;
		}
		i += _print(s[j]);
		j++;
	}
	return (i);
}
/**
 * _nonprinthandler - receives a nonprintable characterandprintsUPPERCASE hex
 * @args: va_list argument input
 * Return: numbner of characters printed
 */
int _nonprinthandler(va_list args)
{
	int k = 0;
	char *s = NULL;

	s = va_arg(args, char *);
	k += _nonprintchars(s);
	return (k);
}
