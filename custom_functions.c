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


int print_rev (char *s)  
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


/**
 * hex_digit - returns the hex value of any integer
 * @v: integer value
 *
 * Return: char in hex
 */

char hex_digit(int v)
{
if (v >= 0 && v < 10)
return '0' + v;
else
return 'a' + v - 10;  
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
for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
len += _putchar(hex_digit((p >> i) & 0xf));
}   
return(len);
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
for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
len++;
}
return(len);
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
return(_puts("(null)"));
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
