#include "main.h"
/**
 * handle_spec - handles the various types of format specs
 *
 * @format: string passed to printf
 * @i: index of current char in format
 * @ap: arguments list passed to printf
 * @ret: number of chars printed
 *
 * Return: 0 (Success), -1 (Error)
 */
int handle_spec(const char *format, unsigned int i, va_list ap, int *ret)
{
unsigned int c;
if (!format[i + 1])
return (-1);
switch (format[i + 1])
{
case 'd':
case 'i':
print_int(va_arg(ap, int), ret);
break;
case 'b':
print_binary(va_arg(ap, unsigned long int), ret);
break;
case 'x':
print_hexa(va_arg(ap, unsigned long int), 0, ret);
break;
case 'X':
print_hexa(va_arg(ap, unsigned long int), 1, ret);
break;
case 'o':
print_octal(va_arg(ap, unsigned long int), ret);
break;
case 'u':
print_Uint(va_arg(ap, unsigned long int), ret);
break;
case 's':
*ret += format_char(va_arg(ap, char *));
break;
case 'c':
c = va_arg(ap, int);
*ret += write(1, &c, 1);
break;
case '%':
*ret += write(1, &format[i + 1], 1);
break;
default:
*ret += write(1, &format[i], 2);
}
return (0);
}

