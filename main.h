#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int _putchar(char c);
int _puts(char *s);
int _strlen(char *s);
char *decimal_to_any(unsigned int n, int base);
int print_int(int n);
int print_space(int width, int size, int zero);
int num_len(int n, int base);
int print_rev(char *s);
int print_octal(unsigned int n);
int print_binary(unsigned int n);
int print_rot13(char *str);
char hex_digit(int v);
int print_address(void *a);
int addr_len(void *a);
int print_special_string(char *s);
int print_hexadecimal(unsigned int n);
int print_hexadecimal_x(unsigned int n);
int print_unsigned_int(unsigned int n);
int base_helper(unsigned int n, char *s, int base,
int width, int zero, int hash);
int int_helper(int n, int plus, int space, int zero, int width);
int check_format(char c);
int format_helper(va_list arg, char c, int width,
int zero, int size, int plus, int space, int hash);
int _printf(const char *format, ...);

#endif /* PRINT_F */
