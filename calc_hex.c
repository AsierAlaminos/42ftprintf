/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:49:57 by asmus37           #+#    #+#             */
/*   Updated: 2023/09/20 18:13:48 by aalamino         ###   ########.fr       */
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
		num = 147483648;
		len += 2;
	}
	if (num < 0)
	{
		len += ft_putchar('-');
		num = num * -1;
	}
	if (num >= 0 && num <= 9)
		len += ft_putchar(num + '0');
	else
	{
		len += putnbr(num / 10);
		len += putnbr(num % 10);
	}
	return (len);
}

int	putnbrulong(unsigned int num)
{
	int		len;

	len = 0;
	if (num <= 9)
		len += ft_putchar(num + '0');
	if (num > 9)
	{
		len += putnbrulong(num / 10);
		len += putnbrulong(num % 10);
	}
	return (len);
}

int	print_hex(char *num, int size_num)
{
	int		len;
	char	print_char;

	len = 0;
	if (size_num == 0)
		size_num++;
	size_num--;
	while (size_num >= 0)
	{
		print_char = num[size_num];
		if (num[size_num] + '0' > 47 && num[size_num] + '0' < 58)
			print_char = num[size_num] + '0';
		len += ft_putchar(print_char);
		size_num--;
	}
	return (len);
}

int	putnbrhex(unsigned int num, char c)
{
	char	*num_char;
	char	*hex_chars;
	int		len;
	int		i;

	if (num == 0)
		return (ft_putchar('0'));
	hex_chars = "0123456789abcdef";
	if (c == 'X')
		hex_chars = "0123456789ABCDEF";
	len = nhexlen(num);
	num_char = malloc(len + 1);
	if (num_char == NULL)
		return (0);
	i = 0;
	while (num != 0)
	{
		num_char[i++] = hex_chars[num % 16];
		num /= 16;
	}
	len = i;
	len = print_hex(num_char, i);
	free(num_char);
	return (len);
}

int	putnbrlonghex(void *num, char *hex_chars)
{
	char				*num_char;
	int					len;
	int					i;
	unsigned long long	num_l;

	write(1, "0x", 2);
	num_l = (unsigned long long)num;
	len = nhexlen(num_l);
	num_char = malloc(len + 1);
	if (num_char == NULL)
		return (0);
	i = 0;
	while (num_l != 0)
	{
		num_char[i++] = hex_chars[num_l % 16];
		num_l /= 16;
	}
	len = print_hex(num_char, i) + 2;
	free(num_char);
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
