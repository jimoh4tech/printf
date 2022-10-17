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
