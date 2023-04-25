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
 * @flags: Flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of printed characters
 */
int _binaryT(va_list args, int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[33];
	int i = 0, j, len;
	char temp;

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

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
 * _printoctal - receves a decimal and print it in octal
 * @args: va_list argument integer to be converted
 * @flags: Flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of printed characters
 */
int _printoctal(va_list args, int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(args, unsigned int);
	char oct_str[12];
	int i = 0, len, digit;
	char temp;

	(void)width;
	(void)precision;
	(void)size;

	if (num == 0 && !(flags & F_HASH))
	{
		_print('0');
		return (1);
	}
	while (num > 0)
	{
		digit = num % 8;
		oct_str[i++] = '0' + digit;
		num /= 8;
	}
	if (flags & F_HASH && oct_str[i - 1] != '0')
		oct_str[i++] = '0';
	oct_str[i] = '\0';
	len = i;
	i = 0;
	while (i < len / 2)
	{
		temp = oct_str[i];
		oct_str[i] = oct_str[len - i - 1];
		oct_str[len - i - 1] = temp;
		i++;
	}
	return (_printstr(oct_str));
}
