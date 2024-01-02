/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:27:57 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/02 17:18:31 by bcarpent         ###   ########.fr       */
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
