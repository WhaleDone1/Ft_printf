/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsPrintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:45:51 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/12 02:40:36 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_putchar_printf(char c)
{
	int	is_stdout_open;

	is_stdout_open = write(1, &c, 1);
	if (is_stdout_open < 0)
		return (-1);
	return (1);
}

unsigned int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_printf(char *s)
{
	int	is_stdout_open;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		is_stdout_open = write(1, s, ft_strlen(s));
	if (is_stdout_open < 0)
		return (is_stdout_open);
	return (ft_strlen(s));
}

int	ft_putnbr_printf(int n)
{
	int		is_stdout_open;
	int		len;
	char	*s;

	if (n == 0)
	{
		is_stdout_open = write(1, "0", 1);
		return (is_stdout_open);
	}
	s = ft_itoa(n);
	len = ft_strlen(s);
	is_stdout_open = write(1, s, len);
	if (is_stdout_open < 0)
		return (is_stdout_open);
	free(s);
	return (len);
}

int	ft_putnbru_printf(unsigned int n)
{
	int		is_stdout_open;
	int		len;
	char	*s;

	if (n == 0)
	{
		is_stdout_open = write(1, "0", 1);
		return (is_stdout_open);
	}
	s = ft_uitoa(n);
	len = ft_strlen(s);
	is_stdout_open = write(1, s, len);
	if (is_stdout_open < 0)
		return (is_stdout_open);
	free(s);
	return (len);
}
