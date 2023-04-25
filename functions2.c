#include "main.h"

/**
 * print_Uint_rec - prints an unsigned number recursively
 *
 * @num: number to print
 * @ret: number of chars printed
 *
 * Return: always void
 */

void print_Uint_rec(unsigned int num, int *ret)
{
char c;

if (!num)
return;

print_Uint_rec(num / 10, ret);

c = (num % 10) + '0';
*ret += write(1, &c, 1);
}

/**
 * print_Uint - prints an unsigned number recursively
 *
 * @num: number to print
 * @ret: number of chars printed
 *
 * Return: always void
 */

void print_Uint(unsigned int num, int *ret)
{
if (num == 0)
*ret += write(1, "0", 1);

if (!num)
return;

print_Uint_rec(num, ret);
}
