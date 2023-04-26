# include "main.h"
/**
 * rot13 - function that prints string rev
 * @args: va_list type argument
 * @flags: Flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: number of characters printed
 */
int rot13(va_list args, int flags, int width, int precision, int size)
{
	int i = 0, j = 0;
	char *s = NULL;
	char v1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char v2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = "(null)";
		return (_printstr(s));
	}

	while (s[i] != '\0')
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			j = 0;
			while (v1[j] != '\0')
			{
				if (s[i] == v1[j])
				{
					_print(v2[j]);
					break;
				}
				j++;
			}
		}
		else
		{
			_print(s[i]);
		}
		i++;
	}
	return (_strlen(s));

}
