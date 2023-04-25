#include "main.h"

/**
 * format_char - prints a char to stdout
 *
 * @str: string to be printed
 *
 * Return: length of char or error in case of any
 */
int format_char(const char *str)
{
unsigned int i = 0, ret = 0, n = 0;

if (!str)
str = "(null)";

n = strlen(str);

if (n <= 0)
n = 0;

if (n)
ret = write(1, &str[i], n);

return (ret);
}

/**
 * count_digits - counts the digits in a number
 *
 * @num: number to count digits for
 * @n: variable to store the count
 *
 * Return: always void
 */

void count_digits(int num, unsigned int *n)
{
while (num)
num /= 10, (*n)++;
}

/**
 * print_int - formats an integer to be printed
 *
 * @number: number passed to printf
 * @ret: count of printed chars
 *
 * Return: 0 (Success)
 */

void print_int(long int number, int *ret)
{
long int num = number;
unsigned int n = 0;
int temp, tmpN, isNeg = 0;
char *c, isZero;

if (!number)
{
isZero = '0', *ret += write(1, &isZero, 1);
return;
}
if (number < 0)
isNeg = 1;

count_digits(num, &n);
c = malloc(sizeof(char) * (n + (isNeg ? 1 : 0)));

if (!c)
return;

num = number;
tmpN = isNeg ? n + 1 : n;
while (num)
{
temp = num % 10;
temp = isNeg ? temp * -1 : temp;
if (!isNeg)
c[n - 1] = (char)temp + '0';
else
c[n] = temp + '0';

num /= 10;
n--;
}
if (isNeg)
c[0] = '-';

*ret += write(1, &c[0], tmpN);
free(c);
}

/**
 * handle_printing - prints a string array to stdout
 * @num: number to print
 * @ret: number of printed chars
 *
 * Return: always void
 */

void handle_printing(unsigned int num, int *ret)
{
unsigned int rem;
char c;

if (!num)
return;

rem = num % 2;

handle_printing(num / 2, ret);

c = rem + '0';
*ret += write(1, &c, 1);

}

/**
 * print_binary - prints the binary equivalent of an usnigned int
 *
 * @num: number to convert to binary
 * @ret: count for printed chars
 *
 * Return: Always void
 */

void print_binary(unsigned int num, int *ret)
{

if (num == 0)
*ret += write(1, "0", 1);

if (!num)
return;

else
handle_printing(num, ret);
}
