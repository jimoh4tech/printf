#include "main.h"

/**
 * print_int - prints integer number
 * @n: number to be printed
 *
 * Return: length of the number printed
 */

int print_int(int n)
{
	int i = 0;
	char *s;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
		i++;
	}
	s = decimal_to_any(n,  10);
	i += _puts(s);
	return (i);
}

/**
 * print_unsigned_int - prints unsigned integer number
 * @n: number to be printed
 *
 * Return: length of the number printed
 */

int print_unsigned_int(unsigned int n)
{
	int i;
	char *s;

	s = decimal_to_any(n,  10);
	i = _puts(s);
	return (i);
}


/**
 * print_octal - prints octal number
 * @n: number to be printed
 *
 * Return: length of the number printed
 */

int print_octal(unsigned int n)
{
	char *s;

	s = decimal_to_any(n, 8);
	return (_puts(s));
}


/**
 * print_hexadecimal - prints hex number uppercase
 * @n: number to be printed
 *
 * Return: length of the number printed
 */

int print_hexadecimal(unsigned int n)
{
	char *s;

	s = decimal_to_any(n, 16);
	return (_puts(s));
}


/**
 * print_hexadecimal_x - prints hex number lowercase
 * @n: number to be printed
 *
 * Return: length of the number printed
 */

int print_hexadecimal_x(unsigned int n)
{
	char *s;
	int i = 0;

	s = decimal_to_any(n, 16);
	while (*s != '\0')
	{
		if (*s >= 65 && *s <= 97)
			_putchar(*s++ + 32);
		else
			_putchar(*s++);
		i++;
	}
	return (i);
}
