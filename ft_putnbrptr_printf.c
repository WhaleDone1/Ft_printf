/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrptr_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:44:04 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/02 09:45:34 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_putprint_ptr(unsigned long long n)
{
	char	tmp;

	if (n >= 16)
	{
		ft_putprint_ptr(n / 16);
		ft_putprint_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			tmp = (n + '0');
			write(1, &tmp, 1);
		}
		else
		{
			tmp = (n - 10 + 'a');
			write(1, &tmp, 1);
		}
	}
}

int	ft_putnbrptr_printf(unsigned long long p)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (p == 0)
		len += write(1, "0", 1);
	else
	{
		ft_putprint_ptr(p);
		len += ft_ptr_len(p);
	}
	return (len);
}
