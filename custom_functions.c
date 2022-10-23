#include "main.h"

/**
 * decimal_to_any - converts from int to any base
 * @n: integer to be converted
 * @base: base to convert to
 *
 * Return: pointer to converted base;
 */

char *decimal_to_any(unsigned int n, int base)
{
	char *s;

	s = malloc(100);
	if (s == NULL)
		free(s);

	*s = '\0';
	do {
		s--;
		*s = "0123456789ABCDEF"[n % base];
		n /= base;
	} while (n);

	return (s);
}

/**
 * print_space - prints space or zeros
 * @width: specified width
 * @size: size of the variable
 * @zero: boolean to check what to print
 *
 * Return: length of spaces or zeros printed
 */

int print_space(int width, int size, int zero)
{
	int i = 0;

	if (width && width >= size)
		size = width - size;
	else
		size = 0;

	while (size)
	{
		if (zero)
			i += _putchar('0');
		else
			i += _putchar(' ');

		--size;
	}
	return (i);
}

/**
 * num_len - calculates the length of numbers
 * @n: the number
 * @base: base of the number
 *
 * Return: length of the number
 */

int num_len(int n, int base)
{
	int i = 0;
	char *s;

	if (n < 0)
	{
		n *= -1;
		i++;
	}
	s = decimal_to_any(n,  base);
	i += _strlen(s);
	return (i);
}


/**
 * print_rev - printes reverse string
 * @s: pointer to the string
 *
 * Return: Length of the string
 */


int print_rev(char *s)
{
	int i, len;

	len = i = _strlen(s);
	while (i > 0)
	{
		i--;
		_putchar(s[i]);
	}
	return (len);
}


/**
 * print_rot13 - prints the rot13 of a string
 * @str: pointer to the string
 *
 * Return: length of the str
 */

int print_rot13(char *str)
{
	int i;
	char *s;

	s = malloc(sizeof(char) * (_strlen(str) + 1));
	if (!s)
		free(s);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] < 'n')
		    || (str[i] >= 'A' && str[i] < 'N'))
		{
			s[i] = str[i] + 13;
		}
		else if ((str[i] >= 'n' && str[i] <= 'z')
			 || (str[i] >= 'N' && str[i] <= 'Z'))
		{
			s[i] = str[i] - 13;
		}
	}
	s[i] = '\0';
	i = _puts(s);
	return (i);
}
