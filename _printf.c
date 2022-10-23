#include "main.h"

/**
 * _printf - custom version of standard printf
 * @format: pointer to the string
 *
 * Return: length of the formatted string
 */

int _printf(const char *format, ...)
{
	int i = 0, len = 0, size = 0, justify = 0;
	va_list arg;
	int plus = 0, space = 0, hash = 0, width = 0, zero = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			while (check_format(format[i]))
			{
				if (format[i] == '+')
					plus = 1;
				else if (format[i] == ' ')
					space = 1;
				else if (format[i] == '#')
					hash = 1;
				else if (format[i] == '0' && !width)
					zero = 1;
				else if (format[i] == '-')
					justify = 1;
				else if (format[i] >= '0' && format[i] <= '9')
				{
					if (format[i + 1] >= '0' && format[i + 1] <= '9')
						width = ((format[i] % 48) * 10) + (format[i + 1] % 48);
					else if (!width)
						width = format[i] % 48;
				}
				i++;
			}
			if (justify)
				width = 0;
			len += format_helper(arg, format[i], width, zero,
					     size, plus, space, hash);
			/* Reset all booleans */
			plus = space = hash = width = zero = justify = 0;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
