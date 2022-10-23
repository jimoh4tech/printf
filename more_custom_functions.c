#include "main.h"

/**
 * print_binary - prints binary number
 * @n: number to be printed
 *
 * Return: length of the number printed
 */

int print_binary(unsigned int n)
{
	char *s;

	s = decimal_to_any(n, 2);
	return (_puts(s));
}

/**
 * hex_digit - returns the hex value of any integer
 * @v: integer value
 *
 * Return: char in hex
 */

char hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

/**
 * print_address - prints address of pointers
 * @a: pointer to be printed
 *
 * Return: The length of the pointer
 */

int print_address(void *a)
{
	int i, len = 0;
	uintptr_t p = (uintptr_t)a;

	len = _puts("0x");
	for (i = (sizeof(p) << 3) - 4; i >= 0; i -= 4)
	{
		len += _putchar(hex_digit((p >> i) & 0xf));
	}
	return (len);
}

/**
 * addr_len - calculates the length of pointers
 * @a: pointer to be calculates
 *
 * Return: length of the pointer
 */

int addr_len(void *a)
{
	int i, len = 0;
	uintptr_t p = (uintptr_t)a;

	len += 2;
	for (i = (sizeof(p) << 3) - 4; i >= 0; i -= 4)
		len++;

	return (len);
}


/**
 * print_special_string - prints custom string according to the
 * the tasks specification
 * @s: pointer to the string
 *
 * Return: length of the string
 */

int print_special_string(char *s)
{
	int i = 0, len = 0;
	char *keep;

	if (s == NULL)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			len += _puts("\\x");
			keep = decimal_to_any(s[i], 16);
			if (!keep[1])
				len += _putchar('0');
			len += _puts(keep);
		}
		else
			len += _putchar(s[i]);
	}
	return (len);
}
