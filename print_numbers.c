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
