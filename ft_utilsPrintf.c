/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsPrintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:45:51 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/02 09:49:46 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_printf(int n)
{
	int		i;
	char	*s;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	s = ft_itoa(n);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

int	ft_putnbru_printf(unsigned int n)
{
	unsigned int	i;
	char			*s;

	i = 0;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	s = ft_uitoa(n);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}
