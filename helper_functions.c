#include "main.h"

/**
 * int_helper - checks for special characters before
 * the format specifier and prints appropriate character
 * precisions for integer
 *
 * @n: number to be printed
 * @plus: boolean to check for plus
 * @width: width of the number
 * @zero: boolean to check for zero
 * @space: boolean to check for space
 *
 * Return: length of the number printed
 */
int int_helper(int n, int plus, int space, int zero, int width)
{
	int len = 0, size;

	size = num_len(n, 10);
	if (plus && n >= 0)
		len += _putchar('+');
	if (space && !plus && n >= 0)
		len += _putchar(' ');

	len += print_space(width, size, zero);
	len += print_int(n);

	return (len);
}


/**
 * base_helper - checks for special characters before
 * the format specifier and prints appropriate character
 * precisions for octal and hex
 *
 * @n: number to be printed
 * @s: pointer: pointer to character precision
 * @base: base of the number
 * @width: width of the number
 * @zero: boolean to check for zero
 * @hash: boolean to check for hash
 *
 * Return: length of the number printed
 */

int base_helper(unsigned int n, char *s, int base,
int width, int zero, int hash)
{
	int len = 0, size;

	size = num_len(n, base);
	if (hash && n > 0)
		len += _puts(s);

	len += print_space(width, size, zero);
	return (len);
}

/**
 * check_format - helper to check if a char is not among
 * the custom specifiers
 * @c: char to be checked
 *
 * Return: 1 if not, else 0
 */

int check_format(char c)
{
	if (!(c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'u'
	      || c == 'x' || c == 'S' || c == '%' || c == 'X' || c == 'b'
	      || c == 'o' || c == 'p' || c == 'r' || c == 'R'))
		return (1);

	return (0);
}

/**
 * format_helper - checks for special characters
 * amongst the specified ones and perform
 * appropriate evaluations
 *
 * @arg: va_list type
 * @c: char to be cheched
 * @width: width of the number
 * @zero: boolean to check for zero
 * @size: size of the variable
 * @plus: boolean to check for plus
 * @space: boolean to check for space
 * @hash: boolean to check for hash
 *
 * Return: length of the number printed
 */
int format_helper(va_list arg, char c, int width, int zero, int size, int plus, int space, int hash)
{
	int len = 0, integer = 0;
	unsigned int u_int = 0;
	char *str;
	void *addr;
	
	switch (c)
	{
	case 'c':
		len += print_space(width, 1, zero);
		len += _putchar(va_arg(arg, int));
		break;
	case 's':
		str = va_arg(arg, char *);
		size = _strlen(str);
		len += print_space(width, size, zero);
		len += _puts(str);
		break;
	case 'i':
	case 'd':
		integer = va_arg(arg, int);
		len += int_helper(integer, plus, space, zero, width);
		break;
	case 'S':
		print_special_string(va_arg(arg, char *));
		break;
	case 'b':
		len += print_binary(va_arg(arg, int));
		break;
	case 'u':
        	u_int = va_arg(arg, int);
		size = num_len(u_int, 10);
		len += print_space(width, size, zero);
		len += print_unsigned_int(u_int);
		break;
	case 'o':
		u_int = va_arg(arg, int);
		len += base_helper(u_int, "0", 8, width, zero, hash);
		len += print_octal(u_int);
		break;
	case 'p':
		addr = va_arg(arg, void *);
		size = addr_len(addr);
		len += print_space(width, size, zero);
		len += print_address(addr);
		break;
	case 'x':
		u_int = va_arg(arg, int);
		len += base_helper(u_int, "0x", 16, width, zero, hash);
		len += print_hexadecimal_x(u_int);
		break;
	case 'X':
		u_int = va_arg(arg, int);
		len += base_helper(u_int, "0X", 16, width, zero, hash);
		len += print_hexadecimal(u_int);
		break;
	case 'r':
		len += print_rev(va_arg(arg, char *));
		break;
	case 'R':
		len += print_rot13(va_arg(arg, char *));
		break;
	case '%':
		len += _putchar('%');
		break;
	default:
		len += _putchar('r');
		break;
	}
	return (len);
}
