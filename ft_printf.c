/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:27:57 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/02 09:38:55 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_printf_format(va_list paramslist, const char format)
{
	unsigned int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_printf(va_arg(paramslist, int));
	else if (format == 's')
		len += ft_putstr_printf(va_arg(paramslist, char *));
	else if (format == 'p')
		len += ft_putnbrptr_printf(va_arg(paramslist, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_printf(va_arg(paramslist, int));
	else if (format == 'u')
		len += ft_putnbru_printf(va_arg(paramslist, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_putnbrhexa_printf(va_arg(paramslist, unsigned int), format);
	else if (format == '%')
		len += ft_putchar_printf('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int				i;
	unsigned int	len;
	va_list			paramslist;

	i = 0;
	len = 0;
	va_start(paramslist, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_printf_format(paramslist, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar_printf(s[i]);
		i++;
	}
	va_end(paramslist);
	return (len);
}
/*
int main()
{
    char *str = "Hello, World!";
    ft_printf("Test 1: %d, %c, %s, %p, %x, %%\n", 42, 'A', str, (void *)&str, 255);
    ft_printf("Test 2: %i, %u, %X, %s, %p, %%\n", -42, 255, 0xABCD, str, (void *)&str);
    ft_printf("Test 3: %c, %s, %p, %d, %x, %%\n", 'Z', str, (void *)&str, 123, 0xDEADBEEF);
    printf("%d\n", ft_printf("Test 3: %c, %s, %p, %d, %x, %%\n", 'Z', str, (void *)&str, 123, 0xDEADBEEF));
    ft_printf("%d", printf("Test 3: %c, %s, %p, %d, %x, %%\n", 'Z', str, (void *)&str, 123, 0xDEADBEEF));
   
    size_t i;

    i = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%ia%%%ub%%%xg%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
    printf("\n%ld\n", i);
    i = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%ia%%%ub%%%xg%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
    printf("\n%ld\n", i);
    return 0;
}*/
