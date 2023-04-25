#include "main.h"

/**
 * _printf - produces output according to a format to stdout
 *
 * @format: format string to follow while producing the output
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
unsigned int i = 0, r;
int ret = 0;
va_list ap;

if (!format)
return (-1);

va_start(ap, format);

while (format && format[i])
{

if (format[i] == '%')
{

r = handle_spec(format, i, ap, &ret);

if (r)
return (-1);

i++;
}

else
ret += write(1, &format[i], 1);

i++;
}

va_end(ap);
return (ret);
}
