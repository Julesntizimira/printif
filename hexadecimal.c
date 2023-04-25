# include "main.h"
/**
 * hexUpper - receives a decimal and prints an UPPERCASEhexadecimal
 * @num: input decimal
 * Return: numbner of characters printed
 */
int hexUpper(unsigned int num)
{
	char hex_str[9];
	char temp;
	int i = 0, digit, len;

	if (num == 0)
	{
		_print('0');
		return (1);
	}
	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
		{
			hex_str[i++] = '0' + digit;
		}
		else
		{
			hex_str[i++] = 'A' + digit - 10;
		}
		num /= 16;
	}
	hex_str[i] = '\0';
	len = i;
	i = 0;
	while (i < len / 2)
	{
		temp = hex_str[i];
		hex_str[i] = hex_str[len - i - 1];
		hex_str[len - i - 1] = temp;
		i++;
	}
	return (_printstr(hex_str));
}
/**
 * _printptr - receives a decimal and prints a hexadecimal
 * @args: va_list argument input decimal
 * Return: numbner of characters printed
 */
int _printptr(va_list args)
{
	void *ptr = NULL;

	ptr = va_arg(args, void *);

	if (ptr == NULL)
		return (0);
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
	char hex_str[9];
	char temp;
	int i = 0, digit, len;

	if (num == 0)
	{
		_print('0');
		return (1);
	}
	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
		{
			hex_str[i++] = '0' + digit;
		}
		else
		{
			hex_str[i++] = 'A' + digit - 10;
		}
		num /= 16;
	}
	hex_str[i] = '\0';
	len = i;
	i = 0;
	while (i < len / 2)
	{
		temp = hex_str[i];
		hex_str[i] = hex_str[len - i - 1];
		hex_str[len - i - 1] = temp;
		i++;
	}
	return (_printstr(hex_str));
}
/**
 * _nonprinthandler - receives a nonprintable characterandprintsUPPERCASE hex
 * @args: va_list argument input
 * Return: numbner of characters printed
 */
int _nonprinthandler(va_list args)
{
	int i = 0, j = 0, len = 0;
	char *s = NULL;

	s = va_arg(args, char *);

	if (s == NULL)
		return (_printstr("(null)"));

	len = _strlen(s);
	for (j = 0; j < len; j++)
	{
		if (s[j] < 32 || s[j] >= 127)
		{
			_print('\\');
			_print('x');
			if (s[j] < 16)
			{
				_print('0');
			}
			hexUpper(s[j]);
			i += 4;
		}
		else
			i += _print(s[j]);
	}
	return (i);
}
