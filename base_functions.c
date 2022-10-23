#include "main.h"

/**
 * _putchar - prints a char to the console
 * @c: char to be printed
 *
 * Return: (1);
 */

int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _puts - prints string to the console
 * @s: pointer of string to be printed
 *
 * Return: length of @s;
 */

int _puts(char *s)
{
	int i;

	if (s == NULL)
		return (_puts("(null)"));

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);

	return (i);
}

/**
 * _strlen - calculate the length of string
 * @s: pointer of string to be calculate
 *
 * Return: length of @s;
 */

int _strlen(char *s)
{
	int i = 0;

	if (s)
		while (s[i] != '\0')
			i++;

	return (i);
}
