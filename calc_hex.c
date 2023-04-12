/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus37 <asmus37@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:49:57 by asmus37           #+#    #+#             */
/*   Updated: 2023/04/12 16:49:58 by asmus37          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//crear una función que imprima un número en hexadecimal

#include <unistd.h>
#include <stdlib.h>
//#include "libft.h"
#include <stdio.h>

void	putnbrulong(unsigned long num)
{
	
}

void	putnbrhex(int num, char c)
{
	char	*num_char;
	char	*hex_nums;
	int		temp;
	int		i;

	hex_nums = "0123456789abcdef";
	if (c == 'X')
		hex_nums = "0123456789ABCDEF";
	i = 0;
	temp = num;
	while (temp != 0)
	{
		temp /= 16;
		++i;
	}
	num_char = malloc(i + 1);
	i = 0;
	while (num != 0)
	{
		num_char[i++] = hex_nums[num % 16];
		num /= 16;
	}
	while (i >= 0)
		write(1, &num_char[i--], 1);
}

int	main(void)
{
	int	n;

	n = 0x55F;
	putnbrhex(n, 'x');
	return (0);
}
