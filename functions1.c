#include "main.h"

/**
 * print_Uos_hexa - prints the hex equivalent of
 * a decimal number recursively
 *
 * @num: number to convert
 * @Uos: indicates printing small or capital letters
 * @ret: number of printed chars
 *
 * Return: always void
 */

void print_Uos_hexa(unsigned int num, int Uos, int *ret)
{
int rem = 0;
char c;
char *Uhexa = "ABCDEF", *Lhexa = "abcdef";

if (!num)
return;

rem = num % 16;
switch (rem)
{
case 10:
c = Uos ? Uhexa[0] : Lhexa[0];
break;
case 11:
c =  Uos ? Uhexa[1] : Lhexa[1];
break;
case 12:
c =  Uos ? Uhexa[2] : Lhexa[2];
break;
case 13:
c =  Uos ? Uhexa[3] : Lhexa[3];
break;
case 14:
c =  Uos ? Uhexa[4] : Lhexa[4];
break;
case 15:
c =  Uos ? Uhexa[5] : Lhexa[5];
break;
default:
c = rem + '0';
break;
}
print_Uos_hexa(num / 16, Uos, ret);
*ret += write(1, &c, 1);
}

/**
 * print_hexa - prints the hex equivalent of a decimal number
 *
 * @num: number to convert
 * @Uos: indicates printing small or capital letters
 * @ret: number of printed chars
 *
 * Return: always void
 */

void print_hexa(unsigned int num, int Uos, int *ret)
{
if (num == 0)
*ret += write(1, "0", 1);

if (!num)
return;

print_Uos_hexa(num, Uos, ret);
}

/**
 * print_octal_rec - prints an octal number recursively
 *
 * @num: number to print
 * @ret: number of chars printed
p *
 * Return: Always void
 */

void print_octal_rec(unsigned int num, int *ret)
{
int rem;
char c;

if (!num)
return;

rem = num % 8;
c = rem + '0';

print_octal_rec(num / 8, ret);

*ret += write(1, &c, 1);
}

/**
 * print_octal - prints an octal number recursively
 *
 * @num: number to print
 * @ret: number of chars printed
p *
 * Return: Always void
 */

void print_octal(unsigned int num, int *ret)
{
if (num == 0)
*ret += write(1, "0", 1);

if (!num)
return;

print_octal_rec(num, ret);
}
