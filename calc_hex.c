/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus37 <asmus37@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:49:57 by asmus37           #+#    #+#             */
/*   Updated: 2023/06/05 14:01:26 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	putnbr(int num)
{
	int		len;

	len = 0;
	if (num == -2147483648)
	{
		write(1, "-2", 2);
		putnbr(147483648);
		len += 2;
	}
	if (num < 0)
	{
		len += ft_putchar('-');
		putnbr(num - 1);
	}
	if (num >= 0 && num <= 9)
		len += ft_putchar(num + '0');
	else
	{
		putnbr(num / 10);
		putnbr(num % 10);
	}
	return (len);
}

int	putnbrulong(unsigned long num)
{
	char	c;

	if (num <= 9)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	if (num > 9)
	{
		putnbrulong(num / 10);
		return (putnbrulong(num % 10) + 1);
	}
	return (0);
}

int	nhexlen(int num)
{
	int	len;

	while (num != 0)
	{
		num /= 16;
		++len;
	}
	return (len);
}

int	putnbrhex(int num, char c)
{
	char	*num_char;
	char	*hex_nums;
	int		len;
	int		i;

	hex_nums = "0123456789abcdef";
	if (c == 'X')
		hex_nums = "0123456789ABCDEF";
	len = nhexlen(num);
	num_char = malloc(len + 1);
	i = 0;
	while (num != 0)
	{
		num_char[i++] = hex_nums[num % 16];
		num /= 16;
	}
	while (i >= 0)
		write(1, &num_char[i--], 1);
	return (len);
}

int	putnbrlonghex(unsigned long num)
{
	char	*num_char;
	char	*hex_nums;
	int		len;
	int		i;

	write(1, "0x", 2);
	hex_nums = "0123456789abcdef";
	len = nhexlen(num);
	num_char = malloc(len + 1);
	i = 0;
	while (num != 0)
	{
		num_char[i++] = hex_nums[num % 16];
		num /= 16;
	}
	while (i >= 0)
		write(1, &num_char[i--], 1);
	return (len);
}

/*
int	main(void)
{
	unsigned long	n;
	//int	num;
	//void	*ptr;

	n = 2147483649;
	putnbrlonghex(n);
	//num = 2147;
	//ptr = (void *)2147;
	//putnbrulong(num);
	//print_hex_format(ptr);
	return (0);
}*/
