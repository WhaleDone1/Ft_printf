/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:26 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/02 15:24:22 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_putprint_hex(unsigned int n, const char format)
{
	char	tmp;

	if (n >= 16)
	{
		ft_putprint_hex(n / 16, format);
		ft_putprint_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_printf(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar_printf(n - 10 + 'a');
			if (format == 'X')
			{
				tmp = (n - 10 + 'A');
				write(1, &tmp, 1);
			}
		}
	}
}

int	ft_putnbrhexa_printf(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_putprint_hex(n, format);
	return (ft_hexa_len(n));
}
