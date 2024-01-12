/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <bcarpent@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:42:32 by bcarpent          #+#    #+#             */
/*   Updated: 2024/01/12 03:42:38 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main pour la fonction printf
#include <stddef.h>
#include <stdio.h>
#include "libprintf.h"

int	main(void)
{
	size_t	i;
	char	*str = "Hello, World!";
	int*	p = NULL;
	int	i2 = 100;
	int	*p2 = &i2;
	
	//fclose(stdout);
	i = ft_printf("Test 1: %d, %c, %s, %p, %x, %%\n", 42, 'A', str, (void *)&str, 255);
	printf("%ld\n", i);
	i = printf("Test 1: %d, %c, %s, %p, %x, %%\n", 42, 'A', str, (void *)&str, 255);
	printf("%ld\n", i);
	i = ft_printf("Test 2: %i, %u, %X, %s, %p, %%\n", -42, 255, 0xABCD, str, (void *)&str);
	printf("%ld\n", i);
	i = printf("Test 2: %i, %u, %X, %s, %p, %%\n", -42, 255, 0xABCD, str, (void *)&str);
	printf("%ld\n", i);
	i = ft_printf("Test 3: %c, %s, %p, %d, %x, %%\n", 'Z', str, (void *)&str, 123, 0xDEADBEEF);
	printf("%ld\n", i);
	i = printf("Test 3: %c, %s, %p, %d, %x, %%\n", 'Z', str, (void *)&str, 123, 0xDEADBEEF);
	printf("%ld\n", i);
	i = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%ia%%%ub%%%xg%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
	printf("\n%ld\n", i);
	i = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%ia%%%ub%%%xg%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
	printf("\n%ld\n", i);
	i = ft_printf("%p\n", p);
	printf("%ld\n", i);
	i = printf("%p\n", p);
	printf("%ld\n", i);
	i = ft_printf("the address is: %p, the value is: %d\n", p2, *p2);
	printf("%ld\n", i);
	i = printf("the address is: %p, the value is: %d\n", p2, *p2);
	printf("%ld\n", i);		
	i = ft_printf("sheesh123\n");
	printf("%ld\n", i);
	i = printf("sheesh123\n");
	printf("%ld\n", i);
	return 0;
}
