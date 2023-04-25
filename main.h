#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *, ...);
int format_char(const char *str);
int handle_spec(const char *, unsigned int, va_list, int *);
void print_int(long int, int *);
void count_digits(int, unsigned int *);
void print_binary(unsigned int, int *);
void handle_printing(unsigned int, int *);
void print_hexa(unsigned int, int, int *);
void print_Uos_hexa(unsigned int, int, int *);
void print_octal(unsigned int, int *);
void print_octal_rec(unsigned int, int *);
void print_Uint(unsigned int, int *n);
void print_Uint_rec(unsigned int, int *n);
void get_flags(const char **format, int *plus_flag,
	       int *space_flag, int *hash_flag);
#endif
