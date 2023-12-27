#ifndef LIBPRINTF_H
#define LIBPRINTF_H

#include <stdarg.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

int ft_putchar_printf(char c);
int ft_putstr_printf(char *s);
int ft_putnbr_printf(int n);
int ft_putnbru_printf(unsigned int n);
int ft_putnbrptr_printf(unsigned long long p);
int ft_putnbrhexa_printf(unsigned int n, const char format);
int ft_printf(const char *s, ...);
char *ft_itoa(int n);
char *ft_uitoa(unsigned int n);

#endif